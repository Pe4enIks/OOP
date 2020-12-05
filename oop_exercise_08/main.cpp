//Пищик Е.С. М8О-206Б-19
//Лабораторная работа №8
//Вариант 16 - восьмиугольник, квадрат, треугольник

#include <thread>
#include <mutex>
#include <condition_variable>
#include <iostream>
#include <cmath>
#include <string>
#include <memory>
#include <fstream>
#include <vector>
#include "point.hpp"
#include "figure.hpp"
#include "triangle.hpp"
#include "square.hpp"
#include "octagon.hpp"
#include "factory.hpp"
#include "document.hpp"
#include "subscriber.hpp"
#include "processor.hpp"

int main(int argc,char* argv[])
{
    try
    {
        if(argc != 2) { throw std::exception("INVALID ARGUMENTS, USAGE: ./main <buff_size>"); }
        int  buffer_size = std::stoi(argv[1]);
        std::shared_ptr<std::vector<std::shared_ptr<Figure<double>>>> buffer = std::make_shared<std::vector<std::shared_ptr<Figure<double>>>>();
        buffer->reserve(buffer_size);
        Factory<double> factory;
        std::string cmd;
        Subscriber<double> sub;
        sub.processors.push_back(std::make_shared<StreamProcessor<double>>());
        sub.processors.push_back(std::make_shared<FileProcessor<double>>());
        std::thread sub_thread(std::ref(sub));
        while (true)
        {
            std::unique_lock<std::mutex> locker(sub.mtx);
            std::cin >> cmd;
            if (cmd == "add")
            {
                std::cout << "Enter square/triangle/octagon\n";
                try {  buffer->push_back(factory.create(std::cin)); }
                catch (std::logic_error &e)
                {
                    std::cout << e.what() << '\n';
                    continue;
                }
                if (buffer->size() == buffer_size)
                {
                    std::cout << "You've reached the limit\n";
                    sub.buffer = buffer;
                    sub.cond_var.notify_all();
                    sub.cond_var.wait(locker, [&](){ return sub.buffer == nullptr; });
                    buffer->clear();
                }
            } else if (cmd == "exit")  {  break; }
            else { std::cout << "Wrong command\n"; }
        }
        sub.stop = true;
        sub.cond_var.notify_all();
        sub_thread.join();
    }
    catch(const std::exception& e) { std::cerr << e.what() << '\n'; }
    return 0;
}

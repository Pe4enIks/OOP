//Пищик Е.С. М8О-206Б-19
//Лабораторная работа №7
//Вариант 16 - восьмиугольник, квадрат, треугольник

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

int main()
{
    std::cout << "Enter <filename/cin/exit>\n";
    while(true)
    {
        try
        {
            std::string name;
            Factory<double> fact;
            std::cin >> name;
            if(name == "exit") { break; }
            if(name == "cin")
            {
                fact.exec_cmd(std::cin);
                break;
            }
            else
            {
                std::ifstream finp;
                finp.open(name);
                if (!finp.is_open()) { throw std::runtime_error("File is not opened"); }
                fact.exec_cmd(finp);
                break;
            }
        }
        catch(const std::exception& e) { std::cerr << e.what() << '\n'; }
    }
    return 0;
}

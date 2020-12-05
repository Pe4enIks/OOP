#pragma once

#include "processor.hpp"

template <typename T>
struct Subscriber
{
    using value_type = T;
    void operator()();
    std::vector<std::shared_ptr<Processor<T>>> processors;
    std::shared_ptr<std::vector<std::shared_ptr<Figure<T>>>> buffer;
    std::mutex mtx;
    std::condition_variable cond_var;
    bool stop = false;
};

template <typename T>
void Subscriber<T>::operator()()
{
    while(true)
    {
        std::unique_lock<std::mutex>lock(mtx);
        cond_var.wait(lock,[&]{ return (buffer != nullptr || stop);});
        if (stop) { break; }
        for (auto elem: processors) { elem->process(buffer); }
        buffer = nullptr;
        cond_var.notify_all();
    }
}

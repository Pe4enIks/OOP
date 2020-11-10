#pragma once

#include "my_iterator.hpp"

//Мой контейнер - очередь
template <typename T>
class my_queue
{
private:
    std::unique_ptr<T> data_;
    size_t size_;
    size_t cap_;
public:
    my_queue();
    //Деструктор
    ~my_queue(){}
    void push(T const&);
    T pop();
    T& top() const;
    void insert(iterator<T>&, T&);
    T erase(iterator<T>&);
    T del(size_t const&);
    //Итераторы
    iterator<T> begin() { return data_.get(); }
    iterator<T> end() { return data_.get()+size_; }
    iterator<T> const begin() const { return data_.get(); }
    iterator<T> const end() const { return data_.get()+size_; }
};

//Конструктор по умолчанию
template <typename T>
my_queue<T>::my_queue()
{
    size_ = 0;
    cap_ = 1;
    std::unique_ptr<T> data(new T[cap_]);
    data_ = std::move(data);
}

//Добавление в конец очереди
template <typename T>
void my_queue<T>::push(T const& el)
{
    try
    {
        if(size_ == cap_)
        {
            cap_ *= 2;
            std::unique_ptr<T> data(new T[cap_]);
            for(size_t i = 0; i < size_; ++i) { data.get()[i] = data_.get()[i]; }
            data_ = std::move(data);
        }
        data_.get()[size_] = el;
        ++size_;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        exit(-1);
    }
}

//Удаление из начала очереди
template <typename T>
T my_queue<T>::pop()
{
    try
    {
        std::unique_ptr<T> data(new T[cap_]);
        T el;
        if (size_ == 0) { throw std::exception("Delete from empty queue"); }
        for(size_t i = 1; i < size_; ++i) { data.get()[i-1] = data_.get()[i]; }
        el = data_.get()[0];
        data_ = std::move(data);
        --size_;
        return el;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << "\n";
        exit(-1);
    }
}

//Первый элемент очереди
template <typename T>
T& my_queue<T>::top() const
{
    try
    {
        if(size_ == 0) { throw std::exception("Top element doesn't exist"); }
        return data_.get()[0];
    }
    catch(const std::exception& e) { std::cerr << e.what() << "\n"; }
    exit(-1);
}

//Вставка по итератору
template <typename T>
void my_queue<T>::insert(iterator<T>& iter, T& el)
{
    try
    {
        if(iter >= end() || iter < begin()) { throw std::exception("Iter out of bounds"); }
        iterator<T> prev_iter = iter;
        T prev_el = *prev_iter;
        T cur_el = *prev_iter;
        *prev_iter = el;
        ++prev_iter;
        while(prev_iter != end())
        {
            cur_el = *prev_iter;
            *prev_iter = prev_el;
            prev_el = cur_el;
            ++prev_iter;
        }
        this->push(prev_el);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << "\n";
        exit(-1);
    }
}

//Удаление по итератору
template <typename T>
T my_queue<T>::erase(iterator<T>& iter)
{
    try
    {
        if(iter >= end() || iter < begin()) { throw std::exception("Iter out of bounds"); }
        if(size_ == 0) { throw std::exception("Delete from empty queue"); }
        T val = *iter;
        size_t count = 1;
        iterator<T> prev_iter = iter;
        ++prev_iter;
        while(prev_iter != end())
        {
            ++count;
            *iter = *prev_iter;
            ++iter;
            ++prev_iter;
        }
        std::unique_ptr<T> data(new T[size_-1]);
        for(size_t i = 0; i < size_ - 1; ++i) { data.get()[i] = data_.get()[i];}
        data_ = std::move(data);
        --size_;
        iter = this->end();
        while(count > 0)
        {
            --count;
            --iter;
        }
        return val;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << "\n";
        exit(-1);
    }
}

//Удаление по индексу
template <typename T>
T my_queue<T>::del(size_t const& ind)
{
    try
    {
        if(size_ == 0 || ind >= size_ || ind < 0) { throw std::exception("Delete from empty queue");}
        T el = data_.get()[ind];
        for(size_t i = ind; i < size_-1; ++i) { data_.get()[ind] = data_.get()[ind+1]; }
        --size_;
        std::unique_ptr<T> data(new T[size_]);
        for(size_t i = 0; i < size_; ++i) {data.get()[i] = data_.get()[i];}
        return el;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << "\n";
        exit(-1);
    }

}

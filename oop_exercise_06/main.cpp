//Пищик Е.С. М8О-206Б-19
//Лабораторная работа №6
//Вариант 20 - трапеция и очередь

#include <iostream>
#include <algorithm>
#include <iterator>
#include <string>
#include "trapezoid.hpp"
#include "my_queue.hpp"
#include "my_iterator.hpp"
#include "my_allocator.hpp"


int main()
{
    my_queue<trapezoid<int>> q;
    trapezoid<int> tr_0;
    trapezoid<int> tr_1;
    trapezoid<int> tr_2;

    std::cin >> tr_0 >> tr_1 >> tr_2;

    q.push(tr_0);
    q.push(tr_1);
    q.push(tr_2);

    std::cout << "\nCount object with area less than 10: " << std::count_if(q.begin(), q.end(), [](trapezoid<int> obj){ return obj.area() < 10.0; }) << "\n";

    std::cout << "\nqueue: ";
    std::for_each(q.begin(), q.end(), [](auto& figure){std::cout << figure;});

    trapezoid<int> el = q.del(1);
    std::cout << "\nqueue: ";
    std::for_each(q.begin(), q.end(), [](auto& figure){std::cout << figure;});

    auto iter = q.begin();
    ++iter;
    std::cout << "\nIter 1\n" << *iter;

    q.insert(iter, tr_1);
    std::cout << "\nIter 2\n" << *iter;

    q.insert(iter, tr_1);
    std::cout << "\nIter 3\n" << *iter;

    std::cout << "\nqueue: ";
    std::for_each(q.begin(), q.end(), [](auto& figure){std::cout << figure;});

    ++iter;
    std::cout << "\nIter 4\n" << *iter;

    auto el_0 = q.erase(iter);
    std::cout << "\nqueue: ";
    std::for_each(q.begin(), q.end(), [](auto& figure){std::cout << figure;});

    std::cout << "\nIter 5\n" << *iter;
    auto el_1 = q.erase(iter);

    std::cout << "\nqueue: ";
    std::for_each(q.begin(), q.end(), [](auto& figure){std::cout << figure;});

    std::cout << "\nIter 6\n" << *iter;
    ++iter;
    auto el_2 = q.erase(iter);

    std::cout << "\nqueue: ";
    std::for_each(q.begin(), q.end(), [](auto& figure){std::cout << figure;});

    std::cout << "\nIter 7\n" << *iter;
    auto el_3 = q.erase(iter);

    std::cout << "\nDeleted elements:\n";
    std::cout << el_0 << el_1 << el_2 << el_3;

    std::cout << "\nqueue: ";
    std::for_each(q.begin(), q.end(), [](auto& figure){std::cout << figure;});

    std::cout << "\nCount object with area less than 5: " << std::count_if(q.begin(), q.end(), [](trapezoid<int> obj){ return obj.area() < 5.0; }) << "\n";

    iter = q.begin();
    --iter;
    q.insert(iter, tr_0);
    return 0;
}

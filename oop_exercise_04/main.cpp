//Пищик Е.С. М8О-206Б-19 Лабораторная работа №4 Вариант 16
//8-угольник, треугольник, квадрат
#include <iostream>
#include <string>
#include <utility>
#include <cmath>
#include <algorithm>

//Константа "pi"
#define PI 3.14159265

//Шаблонные классы фигур
//Класс квадрата
template <typename T, size_t SIZE=4>
struct Square
{
    using type = T;
    std::pair<T,T> v_arr[SIZE];
    size_t size = SIZE;
    std::pair<T,T>* begin() { return &v_arr[0]; }
    std::pair<T,T>* end() { return &v_arr[SIZE]; }
};

//Класс треугольника
template <typename T, size_t SIZE=3>
struct Triangle
{
    using type = T;
    std::pair<T,T> v_arr[SIZE];
    size_t size = SIZE;
    std::pair<T,T>* begin() { return &v_arr[0]; }
    std::pair<T,T>* end() { return &v_arr[SIZE]; }
};

//Класс восьмиугольника
template <typename T, size_t SIZE=8>
struct Octagon
{
    using type = T;
    std::pair<T,T> v_arr[SIZE];
    size_t size = SIZE;
    std::pair<T,T>* begin() { return &v_arr[0]; }
    std::pair<T,T>* end() { return &v_arr[SIZE]; }
};

// Печать любой фигуры
template <typename T>
typename std::enable_if<(sizeof(T::v_arr)>0),void>::type print(T& fig)
{
    for(auto v: fig)
    {
        std::cout << "(" << v.first << "," << v.second << ") ";
    }
    std::cout << std::endl;
}

// Печать tuple фигур
template <typename T,size_t index>
typename std::enable_if<index>=std::tuple_size<T>::value,void>::type print_tuple(T&)
{
    std::cout << std::endl;
}

template <typename T,size_t index>
typename std::enable_if<index<std::tuple_size<T>::value,void>::type print_tuple(T& tuple)
{
    auto v = std::get<index>(tuple);
    std::cout << "Figure " << index << ": ";
    print(v);
    print_tuple<T,index+1>(tuple);
}

//Нахождение площади фигуры
template<typename T>
typename std::enable_if<(sizeof(T::v_arr)>0),double>::type square(T& fig)
{
    double side = sqrt(pow((fig.v_arr[1].first - fig.v_arr[0].first), 2) + pow((fig.v_arr[1].second - fig.v_arr[0].second), 2));
    for(size_t i = 1; i < fig.size; ++i)
    {
        side = side < sqrt(pow((fig.v_arr[i].first - fig.v_arr[0].first), 2) + pow((fig.v_arr[i].second - fig.v_arr[0].second), 2)) ? side : sqrt(pow((fig.v_arr[i].first - fig.v_arr[0].first), 2) + pow((fig.v_arr[i].second - fig.v_arr[0].second), 2));
    }
    if(fig.size == 3) { return sqrt(3.0)/4.0*pow(side,2); }
    else if(fig.size == 4) { return pow(side,2); }
    else if(fig.size == 8) { return 2*pow(side,2)/tan(PI/8); }
    else { return 0.0; }
}

//Нахождение суммарной площади в tuple
template <typename T,size_t index>
double square_tuple(T& tuple)
{
    auto item = std::get<index>(tuple);
    double value = square(item);
    if constexpr ((index+1) < std::tuple_size<T>::value)
    {
        return value + square_tuple<T,index+1>(tuple);
    }
    return value;
}

int main()
{
    //Создаем три экземпляра шаблонных классов
    Square<int> sq;
    Triangle<double> tr;
    Octagon<double> ogon;

    //Инициализация
    sq.v_arr[0] = {0,0};
    sq.v_arr[1] = {1,1};
    sq.v_arr[2] = {0,1};
    sq.v_arr[3] = {1,0};

    tr.v_arr[0] = {1.0,0.0};
    tr.v_arr[1] = {0.0,0.0};
    tr.v_arr[2] = {0.5,sqrt(0.75)};

    ogon.v_arr[0] = {sqrt(2.0),sqrt(2.0)+2.0};
    ogon.v_arr[1] = {sqrt(2.0)+1.0,1.0};
    ogon.v_arr[2] = {-1.0,1.0};
    ogon.v_arr[3] = {0.0,sqrt(2.0)+2.0};
    ogon.v_arr[4] = {0.0,0.0};
    ogon.v_arr[5] = {sqrt(2.0),0.0};
    ogon.v_arr[6] = {-1.0,1.0+sqrt(2.0)};
    ogon.v_arr[7] = {sqrt(2.0)+1.0,sqrt(2.0)+1.0};

    //Создаем tuple из фигур
    auto tuple = std::make_tuple(tr, sq, ogon);
    //Печать tuple фигур
    print_tuple<decltype(tuple),0>(tuple);
    //Печать суммарной площади фигур в tuple
    std::cout << "Square: " << square_tuple<decltype(tuple),0>(tuple) << std::endl;

    return 0;
}

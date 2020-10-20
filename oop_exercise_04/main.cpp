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

    std::pair<T,T>* begin() { return &v_arr[0]; }
    std::pair<T,T>* end() { return &v_arr[SIZE]; }

    constexpr double get_square()
    {
        double side_0 = sqrt(pow((v_arr[1].first - v_arr[0].first), 2) + pow((v_arr[1].second - v_arr[0].second), 2));
        double side_1 = sqrt(pow((v_arr[2].first - v_arr[0].first), 2) + pow((v_arr[2].second - v_arr[0].second), 2));
        double side_2 = sqrt(pow((v_arr[3].first - v_arr[0].first), 2) + pow((v_arr[3].second - v_arr[0].second), 2));
        double side = std::min({side_0, side_1, side_2});
        return pow(side,2);
    }
};

//Класс треугольника
template <typename T, size_t SIZE=3>
struct Triangle
{
    using type = T;
    std::pair<T,T> v_arr[SIZE];

    std::pair<T,T>* begin() { return &v_arr[0]; }
    std::pair<T,T>* end() { return &v_arr[SIZE]; }

    constexpr double get_square()
    {
        double side = sqrt(pow((v_arr[1].first - v_arr[0].first), 2) + pow((v_arr[1].second - v_arr[0].second), 2));
        return sqrt(3.0)/4.0*pow(side,2);
    }
};

//Класс восьмиугольника
template <typename T, size_t SIZE=8>
struct Octagon
{
    using type = T;
    std::pair<T,T> v_arr[SIZE];

    std::pair<T,T>* begin() { return &v_arr[0]; }
    std::pair<T,T>* end() { return &v_arr[SIZE]; }

    constexpr double get_square()
    {
        double side_0 = sqrt(pow((v_arr[1].first - v_arr[0].first), 2) + pow((v_arr[1].second - v_arr[0].second), 2));
        double side_1 = sqrt(pow((v_arr[2].first - v_arr[0].first), 2) + pow((v_arr[2].second - v_arr[0].second), 2));
        double side_2 = sqrt(pow((v_arr[3].first - v_arr[0].first), 2) + pow((v_arr[3].second - v_arr[0].second), 2));
        double side_3 = sqrt(pow((v_arr[4].first - v_arr[0].first), 2) + pow((v_arr[4].second - v_arr[0].second), 2));
        double side_4 = sqrt(pow((v_arr[5].first - v_arr[0].first), 2) + pow((v_arr[5].second - v_arr[0].second), 2));
        double side_5 = sqrt(pow((v_arr[6].first - v_arr[0].first), 2) + pow((v_arr[6].second - v_arr[0].second), 2));
        double side_6 = sqrt(pow((v_arr[7].first - v_arr[0].first), 2) + pow((v_arr[7].second - v_arr[0].second), 2));
        double side = std::min({side_0, side_1, side_2, side_3, side_4, side_5, side_6});
        return 2*pow(side,2)/tan(PI/8);
    }
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

//Нахождение суммарной площади в tuple
template <typename T,size_t index>
double square_tuple(T& tuple)
{
    auto item = std::get<index>(tuple);
    double value = item.get_square();
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
    ogon.v_arr[7] = {sqrt(2.0)+1,sqrt(2.0)+1.0};

    //Создаем tuple из фигур
    auto tuple = std::make_tuple(tr, sq, ogon);
    //Печать tuple фигур
    print_tuple<decltype(tuple),0>(tuple);
    //Печать суммарной площади фигур в tuple
    std::cout << "Square: " << square_tuple<decltype(tuple),0>(tuple) << std::endl;

    return 0;
}

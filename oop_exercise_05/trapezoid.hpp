#pragma once

//Структура трапеции
template <typename T>
struct Trapezoid
{
    using vertex_t = std::pair<T,T>;
    vertex_t p1_, p2_, p3_, p4_;
    Trapezoid()
    {
        p1_ = {0, 0};
        p2_ = {0, 0};
        p3_ = {0, 0};
        p4_ = {0, 0};
    }
    Trapezoid(T const& p11, T const& p12, T const& p21, T const& p22, T const& p31, T const& p32, T const& p41, T const& p42)
    {
        p1_ = {p11, p12};
        p2_ = {p21, p22};
        p3_ = {p31, p32};
        p4_ = {p41, p42};
    }
    double area();
};

//Оператор ввода
template<typename T>
std::istream& operator>>(std::istream& is, Trapezoid<T>& tr)
{
    while(true)
    {
        try
        {
            std::string str[8];
            double d[8];
            std::cout << "Enter 8 values: p1(x,y), p2(x,y), p3(x,y), p4(x,y), where p1,p4 - first base, p2,p3 - second base\n";
            for(size_t i = 0; i < 8; ++i) { is >> str[i]; }
            for(size_t i = 0; i < 8; ++i) { d[i] = std::stod(str[i]); }
            tr.p1_ = { static_cast<T>(d[0]), static_cast<T>(d[1]) };
            tr.p2_ = { static_cast<T>(d[2]), static_cast<T>(d[3]) };
            tr.p3_ = { static_cast<T>(d[4]), static_cast<T>(d[5]) };
            tr.p4_ = { static_cast<T>(d[6]), static_cast<T>(d[7]) };
            double diff_y_0 = static_cast<double>(tr.p3_.second-tr.p2_.second);
            double diff_y_1 = static_cast<double>(tr.p4_.second-tr.p1_.second);
            double diff_x_0 = static_cast<double>(tr.p3_.first-tr.p2_.first);
            double diff_x_1 = static_cast<double>(tr.p4_.first-tr.p1_.first);
            if(diff_y_0/diff_x_0 != diff_y_1/diff_x_1) {throw std::exception("It's not a trapezoid");}
            return is;
        }
        catch(const std::exception& e) { std::cerr << e.what() << "\n"; }
    }
}

//Оператор вывода
template<typename T>
std::ostream& operator<<(std::ostream& os, Trapezoid<T>& tr)
{
    os << "Trapezoid\n";
    os << "(" << tr.p1_.first << "," << tr.p1_.second << ") ";
    os << "(" << tr.p2_.first << "," << tr.p2_.second << ") ";
    os << "(" << tr.p3_.first << "," << tr.p3_.second << ") ";
    os << "(" << tr.p4_.first << "," << tr.p4_.second << ")\n";
    return os;
}

//Площадь
template<typename T>
double Trapezoid<T>::area()
{
    try
    {
        double sum = 0;
        sum += static_cast<double>(p1_.first * p2_.second);
        sum += static_cast<double>(p2_.first * p3_.second);
        sum += static_cast<double>(p3_.first * p4_.second);
        sum += static_cast<double>(p4_.first * p1_.second);
        sum -= static_cast<double>(p2_.first * p1_.second);
        sum -= static_cast<double>(p3_.first * p2_.second);
        sum -= static_cast<double>(p4_.first * p3_.second);
        sum -= static_cast<double>(p1_.first * p4_.second);
        return 0.5 * std::abs(sum);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << "\n";
        exit(-1);
    }
}

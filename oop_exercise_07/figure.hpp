#pragma once

template <typename T>
class Figure
{
public:
    using value_type = T;
    virtual Point<double> center() = 0;
    virtual void print_figure() = 0;
    virtual void print_figure(std::ostream&) = 0;
    virtual void print_figure(std::ofstream&) = 0;
    virtual double area() = 0;
    virtual ~Figure() {}
};

#pragma once

template <typename T>
struct Point
{
    using value_type = T;
    Point() {}
    Point(T const & x, T const & y) : x_(x), y_(y) {}
    T x_;
    T y_;
};

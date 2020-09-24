#pragma once
#include <cmath>
struct Point
{
    Point() {}
    Point(double const & x, double const & y) : x_(x), y_(y) {}
    double x_;
    double y_;
};

struct Line
{
    Line() {}
    Line(Point const & p1, Point const & p2) : p1_(p1), p2_(p2) {}
    double length()
    {
       return sqrt((this->p1_.x_ - this->p2_.x_) * (this->p1_.x_ - this->p2_.x_)  + (this->p1_.y_ - this->p2_.y_) * (this->p1_.y_ - this->p2_.y_));
    }
    Point p1_;
    Point p2_;
};
#pragma once

#ifndef EPS
#define EPS 0.0000000001
#endif
#ifndef THRESHHOLD
#define THRESHHOLD 0.5
#endif

template <typename T>
class Octagon : public Figure<T>
{
private:
    Point<T> p1_;
    Point<T> p2_;
    Point<T> p3_;
    Point<T> p4_;
    Point<T> p5_;
    Point<T> p6_;
    Point<T> p7_;
    Point<T> p8_;
    Point<double> c_;
public:
    Octagon(){}
    Octagon(std::istream& is) : Octagon() { is >> *this; }
    Octagon(Point<T> const, Point<T> const, Point<T> const, Point<T> const, Point<T> const, Point<T> const, Point<T> const, Point<T> const, Point<T> const);
    Point<double>& get_center() { return c_; }
    Point<double> center() { return Point(this->get_center().x_, this->get_center().y_); }
    void print_figure() { std::cout << *this; }
    void print_figure(std::ostream& os) { os << *this; }
    void print_figure(std::ofstream& os) { os << *this; }
    Point<T>& get_point1() { return p1_; }
    Point<T>& get_point2() { return p2_; }
    Point<T>& get_point3() { return p3_; }
    Point<T>& get_point4() { return p4_; }
    Point<T>& get_point5() { return p5_; }
    Point<T>& get_point6() { return p6_; }
    Point<T>& get_point7() { return p7_; }
    Point<T>& get_point8() { return p8_; }
    double area();
};

template <typename T>
double Octagon<T>::area()
{
    double s = static_cast<double>(this->p1_.x_*this->p2_.y_+this->p2_.x_*this->p3_.y_+this->p3_.x_*this->p4_.y_+this->p4_.x_*this->p5_.y_+this->p5_.x_*this->p6_.y_+this->p6_.x_*this->p7_.y_)/2;
    s += static_cast<double>(this->p7_.x_*this->p8_.y_+this->p8_.x_*this->p1_.y_)/2;
    s -= static_cast<double>(this->p2_.x_*this->p1_.y_+this->p3_.x_*this->p2_.y_+this->p4_.x_*this->p3_.y_+this->p5_.x_*this->p4_.y_+this->p6_.x_*this->p5_.y_+this->p7_.x_*this->p6_.y_)/2;
    s -= static_cast<double>(this->p8_.x_*this->p7_.y_+this->p1_.x_*this->p8_.y_)/2;
    return std::abs(s);
}

template <typename T>
Octagon<T>::Octagon(Point<T> const p1, Point<T> const p2, Point<T> const p3, Point<T> const p4, Point<T> const p5, Point<T> const p6, Point<T> const p7, Point<T> const p8, Point<T> const c)
: p1_(p1), p2_(p2), p3_(p3), p4_(p4), p5_(p5), p6_(p6), p7_(p7), p8_(p8), c_(c)
{
    try
    {
        double ca1 = sqrt(pow(p1.x_ - c_.x_, 2)+pow(p1.y_ - c_.y_, 2));
        double ca2 = sqrt(pow(p2.x_ - c_.x_, 2)+pow(p2.y_ - c_.y_, 2));
        double ca3 = sqrt(pow(p3.x_ - c_.x_, 2)+pow(p3.y_ - c_.y_, 2));
        double ca4 = sqrt(pow(p4.x_ - c_.x_, 2)+pow(p4.y_ - c_.y_, 2));
        double ca5 = sqrt(pow(p5.x_ - c_.x_, 2)+pow(p5.y_ - c_.y_, 2));
        double ca6 = sqrt(pow(p6.x_ - c_.x_, 2)+pow(p6.y_ - c_.y_, 2));
        double ca7 = sqrt(pow(p7.x_ - c_.x_, 2)+pow(p7.y_ - c_.y_, 2));
        double ca8 = sqrt(pow(p8.x_ - c_.x_, 2)+pow(p8.y_ - c_.y_, 2));
        double d1 = sqrt(pow(p1.x_ - p2_.x_, 2)+pow(p1.y_ - p2_.y_, 2));
        double d2 = sqrt(pow(p2.x_ - p3_.x_, 2)+pow(p2.y_ - p3_.y_, 2));
        double d3 = sqrt(pow(p3.x_ - p4_.x_, 2)+pow(p3.y_ - p4_.y_, 2));
        double d4 = sqrt(pow(p4.x_ - p5_.x_, 2)+pow(p4.y_ - p5_.y_, 2));
        double d5 = sqrt(pow(p5.x_ - p6_.x_, 2)+pow(p5.y_ - p6_.y_, 2));
        double d6 = sqrt(pow(p6.x_ - p7_.x_, 2)+pow(p6.y_ - p7_.y_, 2));
        double d7 = sqrt(pow(p7.x_ - p8_.x_, 2)+pow(p7.y_ - p8_.y_, 2));
        double d8 = sqrt(pow(p8.x_ - p1_.x_, 2)+pow(p8.y_ - p1_.y_, 2));
        if((ca1+ca2+ca3+ca4+ca5+ca6+ca7+ca8)/8 - ca1 >= EPS) { throw std::exception("Not a octagon"); }
        if(d1 <= EPS) { throw std::exception("Not a octagon"); }
        if(d2 <= EPS) { throw std::exception("Not a octagon"); }
        if(d3 <= EPS) { throw std::exception("Not a octagon"); }
        if(d4 <= EPS) { throw std::exception("Not a octagon"); }
        if(d5 <= EPS) { throw std::exception("Not a octagon"); }
        if(d6 <= EPS) { throw std::exception("Not a octagon"); }
        if(d7 <= EPS) { throw std::exception("Not a octagon"); }
        if(d8 <= EPS) { throw std::exception("Not a octagon"); }
        if(d1 - d2 >= THRESHHOLD) { throw std::exception("Not a octagon"); }
        if(d2 - d3 >= THRESHHOLD) { throw std::exception("Not a octagon"); }
        if(d3 - d4 >= THRESHHOLD) { throw std::exception("Not a octagon"); }
        if(d4 - d5 >= THRESHHOLD) { throw std::exception("Not a octagon"); }
        if(d6 - d7 >= THRESHHOLD) { throw std::exception("Not a octagon"); }
        if(d7 - d8 >= THRESHHOLD) { throw std::exception("Not a octagon"); }
        if(d8 - d1 >= THRESHHOLD) { throw std::exception("Not a octagon"); }
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        exit(-1);
    }
}

template<typename T>
std::ostream& operator<<(std::ostream &os, Octagon<T>& tr)
{
    os << "Octagon:" << std::endl;
    os << "First point: (" << tr.get_point1().x_ << "," << tr.get_point1().y_ << ")" << std::endl;
    os << "Second point: (" << tr.get_point2().x_ << "," << tr.get_point2().y_ << ")" << std::endl;
    os << "Third point: (" << tr.get_point3().x_ << "," << tr.get_point3().y_ << ")" << std::endl;
    os << "Fourth point: (" << tr.get_point4().x_ << "," << tr.get_point4().y_ << ")" << std::endl;
    os << "Fith point: (" << tr.get_point5().x_ << "," << tr.get_point5().y_ << ")" << std::endl;
    os << "Sixth point: (" << tr.get_point6().x_ << "," << tr.get_point6().y_ << ")" << std::endl;
    os << "Seventh point: (" << tr.get_point7().x_ << "," << tr.get_point7().y_ << ")" << std::endl;
    os << "Eighth point: (" << tr.get_point8().x_ << "," << tr.get_point8().y_ << ")" << std::endl;
    return os;
}

template<typename T>
std::ofstream& operator<<(std::ofstream &os, Octagon<T>& tr)
{
    os << "Octagon:" << std::endl;
    os << tr.get_point1().x_ << " " << tr.get_point1().y_ << std::endl;
    os << tr.get_point2().x_ << " " << tr.get_point2().y_ << std::endl;
    os << tr.get_point3().x_ << " " << tr.get_point3().y_ << std::endl;
    os << tr.get_point4().x_ << " " << tr.get_point4().y_ << std::endl;
    os << tr.get_point5().x_ << " " << tr.get_point5().y_ << std::endl;
    os << tr.get_point6().x_ << " " << tr.get_point6().y_ << std::endl;
    os << tr.get_point7().x_ << " " << tr.get_point7().y_ << std::endl;
    os << tr.get_point8().x_ << " " << tr.get_point8().y_ << std::endl;
    return os;
}

template<typename T>
std::istream& operator>>(std::istream &is, Octagon<T>& tr)
{
    std::cout << "Enter 18 coordinates for 9 vertex, p1-p8 for a circle and 1 center\n";
    std::string p11, p12, p21, p22, p31, p32, p41, p42, p51, p52, p61, p62, p71, p72, p81, p82, c1, c2;
    while(true)
    {
        try
        {
            is >> p11 >> p12 >> p21 >> p22 >> p31 >> p32 >> p41 >> p42 >> p51 >> p52 >> p61 >> p62 >> p71 >> p72 >> p81 >> p82 >> c1 >> c2;
            tr.get_point1().x_ = std::stod(p11);
            tr.get_point1().y_ = std::stod(p12);
            tr.get_point2().x_ = std::stod(p21);
            tr.get_point2().y_ = std::stod(p22);
            tr.get_point3().x_ = std::stod(p31);
            tr.get_point3().y_ = std::stod(p32);
            tr.get_point4().x_ = std::stod(p41);
            tr.get_point4().y_ = std::stod(p42);
            tr.get_point5().x_ = std::stod(p51);
            tr.get_point5().y_ = std::stod(p52);
            tr.get_point6().x_ = std::stod(p61);
            tr.get_point6().y_ = std::stod(p62);
            tr.get_point7().x_ = std::stod(p71);
            tr.get_point7().y_ = std::stod(p72);
            tr.get_point8().x_ = std::stod(p81);
            tr.get_point8().y_ = std::stod(p82);
            tr.get_center().x_ = std::stod(c1);
            tr.get_center().y_ = std::stod(c2);
            tr.get_point1().x_ = static_cast<T>(tr.get_point1().x_);
            tr.get_point1().y_ = static_cast<T>(tr.get_point1().y_);
            tr.get_point2().x_ = static_cast<T>(tr.get_point2().x_);
            tr.get_point2().y_ = static_cast<T>(tr.get_point2().y_);
            tr.get_point3().x_ = static_cast<T>(tr.get_point3().x_);
            tr.get_point3().y_ = static_cast<T>(tr.get_point3().y_);
            tr.get_point4().x_ = static_cast<T>(tr.get_point4().x_);
            tr.get_point4().y_ = static_cast<T>(tr.get_point4().y_);
            tr.get_point5().x_ = static_cast<T>(tr.get_point5().x_);
            tr.get_point5().y_ = static_cast<T>(tr.get_point5().y_);
            tr.get_point6().x_ = static_cast<T>(tr.get_point6().x_);
            tr.get_point6().y_ = static_cast<T>(tr.get_point6().y_);
            tr.get_point7().x_ = static_cast<T>(tr.get_point7().x_);
            tr.get_point7().y_ = static_cast<T>(tr.get_point7().y_);
            tr.get_point8().x_ = static_cast<T>(tr.get_point8().x_);
            tr.get_point8().y_ = static_cast<T>(tr.get_point8().y_);
            tr.get_center().x_ = static_cast<T>(tr.get_center().x_);
            tr.get_center().y_ = static_cast<T>(tr.get_center().y_);
            double ca1 = sqrt(pow(tr.get_point1().x_ - tr.get_center().x_, 2)+pow(tr.get_point1().y_ - tr.get_center().y_, 2));
            double ca2 = sqrt(pow(tr.get_point2().x_ - tr.get_center().x_, 2)+pow(tr.get_point2().y_ - tr.get_center().y_, 2));
            double ca3 = sqrt(pow(tr.get_point3().x_ - tr.get_center().x_, 2)+pow(tr.get_point3().y_ - tr.get_center().y_, 2));
            double ca4 = sqrt(pow(tr.get_point4().x_ - tr.get_center().x_, 2)+pow(tr.get_point4().y_ - tr.get_center().y_, 2));
            double ca5 = sqrt(pow(tr.get_point5().x_ - tr.get_center().x_, 2)+pow(tr.get_point5().y_ - tr.get_center().y_, 2));
            double ca6 = sqrt(pow(tr.get_point6().x_ - tr.get_center().x_, 2)+pow(tr.get_point6().y_ - tr.get_center().y_, 2));
            double ca7 = sqrt(pow(tr.get_point7().x_ - tr.get_center().x_, 2)+pow(tr.get_point7().y_ - tr.get_center().y_, 2));
            double ca8 = sqrt(pow(tr.get_point8().x_ - tr.get_center().x_, 2)+pow(tr.get_point8().y_ - tr.get_center().y_, 2));
            double d1 = sqrt(pow(tr.get_point1().x_ - tr.get_point2().x_, 2)+pow(tr.get_point1().y_ - tr.get_point2().y_, 2));
            double d2 = sqrt(pow(tr.get_point2().x_ - tr.get_point3().x_, 2)+pow(tr.get_point2().y_ - tr.get_point3().y_, 2));
            double d3 = sqrt(pow(tr.get_point3().x_ - tr.get_point4().x_, 2)+pow(tr.get_point3().y_ - tr.get_point4().y_, 2));
            double d4 = sqrt(pow(tr.get_point4().x_ - tr.get_point5().x_, 2)+pow(tr.get_point4().y_ - tr.get_point5().y_, 2));
            double d5 = sqrt(pow(tr.get_point5().x_ - tr.get_point6().x_, 2)+pow(tr.get_point5().y_ - tr.get_point6().y_, 2));
            double d6 = sqrt(pow(tr.get_point6().x_ - tr.get_point7().x_, 2)+pow(tr.get_point6().y_ - tr.get_point7().y_, 2));
            double d7 = sqrt(pow(tr.get_point7().x_ - tr.get_point8().x_, 2)+pow(tr.get_point7().y_ - tr.get_point8().y_, 2));
            double d8 = sqrt(pow(tr.get_point8().x_ - tr.get_point1().x_, 2)+pow(tr.get_point8().y_ - tr.get_point1().y_, 2));
            if((ca1+ca2+ca3+ca4+ca5+ca6+ca7+ca8)/8 - ca1 >= EPS) { throw std::exception("Not a octagon"); }
            if(d1 <= EPS) { throw std::exception("Not a octagon"); }
            if(d2 <= EPS) { throw std::exception("Not a octagon"); }
            if(d3 <= EPS) { throw std::exception("Not a octagon"); }
            if(d4 <= EPS) { throw std::exception("Not a octagon"); }
            if(d5 <= EPS) { throw std::exception("Not a octagon"); }
            if(d6 <= EPS) { throw std::exception("Not a octagon"); }
            if(d7 <= EPS) { throw std::exception("Not a octagon"); }
            if(d8 <= EPS) { throw std::exception("Not a octagon"); }
            if(d1 - d2 >= EPS) { throw std::exception("Not a octagon"); }
            if(d2 - d3 >= EPS) { throw std::exception("Not a octagon"); }
            if(d3 - d4 >= EPS) { throw std::exception("Not a octagon"); }
            if(d4 - d5 >= EPS) { throw std::exception("Not a octagon"); }
            if(d6 - d7 >= EPS) { throw std::exception("Not a octagon"); }
            if(d7 - d8 >= EPS) { throw std::exception("Not a octagon"); }
            if(d8 - d1 >= EPS) { throw std::exception("Not a octagon"); }
            return is;
        }
        catch(const std::exception& ex)
        {
            std::cerr << "Incorrect data, try again" << std::endl;
            std::cerr << ex.what() << std::endl;
        }
    }
}

#pragma once
#ifndef EPS
#define EPS 0.0000000001
#endif

template <typename T>
class Triangle : public Figure<T>
{
private:
    Point<T> p1_;
    Point<T> p2_;
    Point<T> p3_;
public:
    Triangle(){}
    Triangle(std::istream& is) : Triangle() { is >> *this; }
    Triangle(Point<T> const, Point<T> const, Point<T> const);
    Point<double> center(){ return Point<double>(static_cast<double>(this->p1_.x_ + this->p2_.x_ + this->p3_.x_)/3, static_cast<double>(this->p1_.y_ + this->p2_.y_ + this->p3_.y_)/3); }
    void print_figure() { std::cout << *this; }
    void print_figure(std::ostream& os) { os << *this; }
    void print_figure(std::ofstream& os) { os << *this; }
    Point<T>& get_point1() { return p1_; }
    Point<T>& get_point2() { return p2_; }
    Point<T>& get_point3() { return p3_; }
    double area();
};

template <typename T>
double Triangle<T>::area()
{
    double s = static_cast<double>(this->p1_.x_*this->p2_.y_+this->p2_.x_*this->p3_.y_+this->p3_.x_*this->p1_.y_-this->p2_.x_*this->p1_.y_-this->p3_.x_*this->p2_.y_-this->p1_.x_*this->p3_.y_)/2;
    return std::abs(s);
}


template <typename T>
Triangle<T>::Triangle(Point<T> const p1, Point<T> const p2, Point<T> const p3) : p1_(p1), p2_(p2), p3_(p3)
{
    try
    {
        double d1 = sqrt(pow(p1.x_ - p2_.x_, 2)+pow(p1.y_ - p2_.y_, 2));
        double d2 = sqrt(pow(p1.x_ - p3_.x_, 2)+pow(p1.y_ - p3_.y_, 2));
        double d3 = sqrt(pow(p2.x_ - p3_.x_, 2)+pow(p2.y_ - p3_.y_, 2));
        double dx1 = static_cast<double>(p1.x_)-static_cast<double>(p2.x_);
        double dy1 = static_cast<double>(p1.y_)-static_cast<double>(p2.y_);
        double dx2 = static_cast<double>(p1.x_)-static_cast<double>(p3.x_);
        double dy2 = static_cast<double>(p1.y_)-static_cast<double>(p3.y_);
        double dx3 = static_cast<double>(p2.x_)-static_cast<double>(p3.x_);
        double dy3 = static_cast<double>(p2.y_)-static_cast<double>(p3.y_);
        double tg1 = dx1 / dy1;
        double tg2 = dx2 / dy2;
        double tg3 = dx3 / dy3;
        if(d1 <= EPS) { throw std::exception("Not a triangle"); }
        if(d2 <= EPS) { throw std::exception("Not a triangle"); }
        if(d3 <= EPS) { throw std::exception("Not a triangle"); }
        if(std::abs(tg1 - tg2) <= EPS) { throw std::exception("Not a triangle"); }
        if(std::abs(tg1 - tg3) <= EPS) { throw std::exception("Not a triangle"); }
        if(std::abs(tg2 - tg3) <= EPS) { throw std::exception("Not a triangle"); }
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        exit(-1);
    }
}

template<typename T>
std::ostream& operator<<(std::ostream &os, Triangle<T>& tr)
{
    os << "Triangle:" << std::endl;
    os << "First point: (" << tr.get_point1().x_ << "," << tr.get_point1().y_ << ")" << std::endl;
    os << "Second point: (" << tr.get_point2().x_ << "," << tr.get_point2().y_ << ")" << std::endl;
    os << "Third point: (" << tr.get_point3().x_ << "," << tr.get_point3().y_ << ")" << std::endl;
    return os;
}

template<typename T>
std::ofstream& operator<<(std::ofstream &os, Triangle<T>& tr)
{
    os << "Triangle:" << std::endl;
    os << tr.get_point1().x_ << " " << tr.get_point1().y_ <<  std::endl;
    os << tr.get_point2().x_ << " " << tr.get_point2().y_ <<  std::endl;
    os << tr.get_point3().x_ << " " << tr.get_point3().y_ <<  std::endl;
    return os;
}

template<typename T>
std::istream& operator>>(std::istream &is, Triangle<T>& tr)
{
    std::cout << "Enter 6 coordinates for 3 vertex\n";
    std::string p11, p12, p21, p22, p31, p32;
    while(true)
    {
        try
        {
            is >> p11 >> p12 >> p21 >> p22 >> p31 >> p32;
            tr.get_point1().x_ = std::stod(p11);
            tr.get_point1().y_ = std::stod(p12);
            tr.get_point2().x_ = std::stod(p21);
            tr.get_point2().y_ = std::stod(p22);
            tr.get_point3().x_ = std::stod(p31);
            tr.get_point3().y_ = std::stod(p32);
            tr.get_point1().x_ = static_cast<T>(tr.get_point1().x_);
            tr.get_point1().y_ = static_cast<T>(tr.get_point1().y_);
            tr.get_point2().x_ = static_cast<T>(tr.get_point2().x_);
            tr.get_point2().y_ = static_cast<T>(tr.get_point2().y_);
            tr.get_point3().x_ = static_cast<T>(tr.get_point3().x_);
            tr.get_point3().y_ = static_cast<T>(tr.get_point3().y_);
            double d1 = sqrt(pow(tr.get_point1().x_ - tr.get_point2().x_, 2)+pow(tr.get_point1().y_ - tr.get_point2().y_, 2));
            double d2 = sqrt(pow(tr.get_point1().x_ - tr.get_point3().x_, 2)+pow(tr.get_point1().y_ - tr.get_point3().y_, 2));
            double d3 = sqrt(pow(tr.get_point2().x_ - tr.get_point3().x_, 2)+pow(tr.get_point2().y_ - tr.get_point3().y_, 2));
            double dx1 = static_cast<double>(tr.get_point1().x_)-static_cast<double>(tr.get_point2().x_);
            double dy1 = static_cast<double>(tr.get_point1().y_)-static_cast<double>(tr.get_point2().y_);
            double dx2 = static_cast<double>(tr.get_point1().x_)-static_cast<double>(tr.get_point3().x_);
            double dy2 = static_cast<double>(tr.get_point1().y_)-static_cast<double>(tr.get_point3().y_);
            double dx3 = static_cast<double>(tr.get_point2().x_)-static_cast<double>(tr.get_point3().x_);
            double dy3 = static_cast<double>(tr.get_point2().y_)-static_cast<double>(tr.get_point3().y_);
            double tg1 = dx1 / dy1;
            double tg2 = dx2 / dy2;
            double tg3 = dx3 / dy3;
            if(d1 <= EPS) { throw std::exception("Not a triangle"); }
            if(d2 <= EPS) { throw std::exception("Not a triangle"); }
            if(d3 <= EPS) { throw std::exception("Not a triangle"); }
            if(std::abs(tg1 - tg2) <= EPS) { throw std::exception("Not a triangle"); }
            if(std::abs(tg1 - tg3) <= EPS) { throw std::exception("Not a triangle"); }
            if(std::abs(tg2 - tg3) <= EPS) { throw std::exception("Not a triangle"); }
            return is;
        }
        catch(const std::exception& ex)
        {
            std::cerr << "Incorrect data, try again" << std::endl;
            std::cerr << ex.what() << std::endl;
        }
    }
}

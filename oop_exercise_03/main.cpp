//Пищик Е.С. М8О-206Б-19 Лабораторная №3 Вариант 16
//8-уголник, треугольник, квадрат
#include <iostream>
#include <string>
#include <cmath>
#include <string>
#include <fstream>
#include <vector>
#include "structs.hpp"
class Figure
{
    public:
    virtual Point center() = 0;
    virtual void print_figure() const = 0;
    virtual double area() = 0;
    virtual ~Figure() {}
};
//Наследуемый класс от Figure
//Треугольник задается 3-мя точками
class Triangle : public Figure
{
    Point p1_;
    Point p2_;
    Point p3_;
    public:
    //Геттеры
    Point& get_point1() {return p1_;}
    Point& get_point2() {return p2_;}
    Point& get_point3() {return p3_;}
    //Конструкторы
    Triangle(){}
    Triangle(Point const& p1, Point const& p2, Point const& p3) : p1_(p1), p2_(p2), p3_(p3) {}
    //Методы
    //Нахождение точки центра фигуры 
    Point center(){ return Point((this->p1_.x_ + this->p2_.x_ + this->p3_.x_)/3, (this->p1_.y_ + this->p2_.y_ + this->p3_.y_)/3); }
    //Вычисление площади фигуры
    double area() 
    {
        double s = (this->p1_.x_ - this->p3_.x_)*(this->p2_.y_ - this->p3_.y_) - (this->p1_.y_ - this->p3_.y_)*(this->p2_.x_ - this->p3_.x_)/2;
        return s < 0 ? -s : s;
    }
    //Печать координат вершин на поток вывода
    void print_figure() const
    {
        std::cout << std::endl;
        std::cout << "Triangle:" << std::endl;
        std::cout << "First point: (" << this->p1_.x_ << "," << this->p1_.y_ << ")" << std::endl;
        std::cout << "Second point: (" << this->p2_.x_ << "," << this->p2_.y_ << ")" << std::endl;
        std::cout << "Third point: (" << this->p3_.x_ << "," << this->p3_.y_ << ")" << std::endl;
    }
};
//Наследуемый класс от Figure
//Квадрат задается 2 точками одной из диагоналей
class Square : public Figure
{
    Point p1_;
    Point p2_;
    public:
    //Геттеры
    Point& get_point1() {return p1_;}
    Point& get_point2() {return p2_;}
    //Конструктор
    Square(){}
    Square(Point const& p1, Point const& p2) : p1_(p1), p2_(p2) {}
    //Методы
    //Нахождение точки центра фигуры 
    Point center(){ return Point((p1_.x_ + p2_.x_)/2, (p1_.y_ + p2_.y_)/2); }
    //Вычисление площади фигуры
    double area() { return pow(p1_.x_ - p2_.x_, 2); }
    //Печать координат вершин на поток вывода
    void print_figure() const
    {
        std::cout << std::endl;
        std::cout << "Square:" << std::endl;
        std::cout << "First point: (" << this->p1_.x_ << "," << this->p1_.y_ << ")" << std::endl;
        std::cout << "Second point: (" << this->p2_.x_ << "," << this->p2_.y_ << ")" << std::endl;
    }
};
//Наследуемый класс от Figure
//Восьмиугольник задается 8 точками
class Octagon : public Figure
{
    Point p1_;
    Point p2_;
    Point p3_;
    Point p4_;
    Point p5_;
    Point p6_;
    Point p7_;
    Point p8_;
    public:
    //Геттеры
    Point& get_point1() {return p1_;}
    Point& get_point2() {return p2_;}
    Point& get_point3() {return p3_;}
    Point& get_point4() {return p4_;}
    Point& get_point5() {return p5_;}
    Point& get_point6() {return p6_;}
    Point& get_point7() {return p7_;}
    Point& get_point8() {return p8_;}
    //Конструктор
    Octagon(){}
    Octagon(Point const& p1, Point const& p2, Point const& p3, Point const& p4, Point const& p5, Point const& p6, Point const& p7, Point const& p8) : 
    p1_(p1), p2_(p2), p3_(p3), p4_(p4), p5_(p5), p6_(p6), p7_(p7), p8_(p8) {}
    //Методы
    //Нахождение точки центра фигуры 
    Point center()
    {
        double x_center, y_center = 0;
        x_center = (this->p1_.x_ + this->p2_.x_ + this->p3_.x_ + this->p4_.x_ + this->p5_.x_ + this->p6_.x_ + this->p7_.x_ + this->p8_.x_)/8;
        y_center = (this->p1_.y_ + this->p2_.y_ + this->p3_.y_ + this->p4_.y_ + this->p5_.y_ + this->p6_.y_ + this->p7_.y_ + this->p8_.y_)/8;
        return Point(x_center, y_center);
    }
    //Вычисление площади фигуры
    double area()
    {
        Point c = this->center();
        double s = 0;
        s += (p1_.x_*p2_.y_ + p2_.x_*p3_.y_ + p3_.x_*p4_.y_ + p4_.x_*p5_.y_ + p5_.x_*p6_.y_ + p6_.x_*p7_.y_ + p7_.x_*p8_.y_ + p8_.x_*p1_.y_);
        s -= (p2_.x_*p1_.y_ + p3_.x_*p2_.y_ + p4_.x_*p3_.y_ + p5_.x_*p4_.y_ + p6_.x_*p5_.y_ + p7_.x_*p6_.y_ + p8_.x_*p7_.y_ + p1_.x_*p8_.y_);
        return s > 0 ? s/2 : -(s/2);
    }
    //Печать координат вершин на поток вывода
    void print_figure() const
    {
        std::cout << std::endl;
        std::cout << "Octagon:" << std::endl;
        std::cout << "First point: (" << this->p1_.x_ << "," << this->p1_.y_ << ")" << std::endl;
        std::cout << "Second point: (" << this->p2_.x_ << "," << this->p2_.y_ << ")" << std::endl;
        std::cout << "Third point: (" << this->p3_.x_ << "," << this->p3_.y_ << ")" << std::endl;
        std::cout << "Fourth point: (" << this->p4_.x_ << "," << this->p4_.y_ << ")" << std::endl;
        std::cout << "Fifth point: (" << this->p5_.x_ << "," << this->p5_.y_ << ")" << std::endl;
        std::cout << "Sixth point: (" << this->p6_.x_ << "," << this->p6_.y_ << ")" << std::endl;
        std::cout << "Seventh point: (" << this->p7_.x_ << "," << this->p7_.y_ << ")" << std::endl;
        std::cout << "Eighth point: (" << this->p8_.x_ << "," << this->p8_.y_ << ")" << std::endl;
    }
};
//Для ввода через cin собственных классов
//Вводится 16 чисел, координаты 8 точек для восьмиугольника
std::istream& operator>>(std::istream &is, Octagon& ogon)
{
    std::string p11, p12, p21, p22, p31, p32, p41, p42, p51, p52, p61, p62, p71, p72, p81, p82;
    while(true)
    {
        try
        {
            is >> p11 >> p12 >> p21 >> p22 >> p31 >> p32 >> p41 >> p42 >> p51 >> p52 >> p61 >> p62 >> p71 >> p72 >> p81 >> p82;
            ogon.get_point1().x_ = std::stod(p11);
            ogon.get_point1().y_ = std::stod(p12);
            ogon.get_point2().x_ = std::stod(p21);
            ogon.get_point2().y_ = std::stod(p22);
            ogon.get_point3().x_ = std::stod(p31);
            ogon.get_point3().y_ = std::stod(p32);
            ogon.get_point4().x_ = std::stod(p41);
            ogon.get_point4().y_ = std::stod(p42);
            ogon.get_point5().x_ = std::stod(p51);
            ogon.get_point5().y_ = std::stod(p52);
            ogon.get_point6().x_ = std::stod(p61);
            ogon.get_point6().y_ = std::stod(p62);
            ogon.get_point7().x_ = std::stod(p71);
            ogon.get_point7().y_ = std::stod(p72);
            ogon.get_point8().x_ = std::stod(p81);
            ogon.get_point8().y_ = std::stod(p82);
            return is;
        }
        catch(const std::exception& ex)
        {
            std::cerr << "Incorrect data, try again" << std::endl;
            std::cerr << ex.what() << std::endl;
        }
    }
}
//Вводится 4 числа координаты двух диагональных точек для квадрата
std::istream& operator>>(std::istream &is, Square& sqr)
{
    std::string p11, p12, p21, p22;
    while(true)
    {
        try
        {
            is >> p11 >> p12 >> p21 >> p22;
            sqr.get_point1().x_ = std::stod(p11);
            sqr.get_point1().y_ = std::stod(p12);
            sqr.get_point2().x_ = std::stod(p21);
            sqr.get_point2().y_ = std::stod(p22);
            return is;
        }
        catch(const std::exception& ex)
        {
            std::cerr << "Incorrect data, try again" << std::endl;
            std::cerr << ex.what() << std::endl;
        }
    }
}
//Вводится 6 чисел по 2 числа на каждую вершину трейгольника
std::istream& operator>>(std::istream &is, Triangle& tr)
{
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
            return is;
        }
        catch(const std::exception& ex)
        {
            std::cerr << "Incorrect data, try again" << std::endl;
            std::cerr << ex.what() << std::endl;
        }
    }
}
//Функция вычисления площади в векторе
double area_in_vector(std::vector<Figure*> figures)
{
    double sum = 0;
    std::vector<Figure*>::iterator iter = figures.begin();
    while(iter != figures.end())
    {
        //*iter элемент на который указывает iter, т.е Figure*
        sum += (*iter)->area();
        ++iter;
    }
    return sum;
}
//Удаление эл-та по индексу
void delete_el(std::vector<Figure*> & figures, int i = 0)
{
    figures.erase(figures.begin() + i);
}
//Тестирующая функция для треугольника
void TestTriangle(double p11, double p12, double p21, double p22, double p31, double p32)
{
    Point p1(p11, p12);
    Point p2(p21, p22);
    Point p3(p31, p32);
    Triangle tr(p1, p2, p3);
    tr.print_figure();
    std::cout << "Area = " << tr.area() << std::endl;
    std::cout << "Center x = " << tr.center().x_ << ", y = " << tr.center().y_ << std::endl;
}
//Тестирующая функция для квадрата
void TestSquare(double p11, double p12, double p21, double p22)
{
    Point p1(p11, p12);
    Point p2(p21, p22);
    Square sqr(p1, p2);
    sqr.print_figure();
    std::cout << "Area = " << sqr.area() << std::endl;
    std::cout << "Center x = " << sqr.center().x_ << ", y = " << sqr.center().y_ << std::endl;
}
//Тестирующая функция для 8-миугольника
void TestOctagon(double p11, double p12, double p21, double p22, double p31, double p32, double p41, double p42,
double p51, double p52, double p61, double p62, double p71, double p72, double p81, double p82)
{
    //Координаты передаются по круговому обходу
    Point p1(p11, p12);
    Point p2(p21, p22);
    Point p3(p31, p32);
    Point p4(p41, p42);
    Point p5(p51, p52);
    Point p6(p61, p62);
    Point p7(p71, p72);
    Point p8(p81, p82);
    Octagon ogon(p1, p2, p3, p4, p5, p6, p7, p8);
    ogon.print_figure();
    std::cout << "Area = " << ogon.area() << std::endl;
    std::cout << "Center x = " << ogon.center().x_ << ", y = " << ogon.center().y_ << std::endl;
}
//Тестирующая функция для cin с моими классами
void TestCin()
{
    std::cout << "Enter 16 numbers, coordinates 8 points, in the correct order (in a circle) for octagon:" << std::endl;
    Octagon ogon;
    std::cin >> ogon;
    ogon.print_figure();
    std::cout << "Area = " << ogon.area() << std::endl;
    std::cout << "Center x = " << ogon.center().x_ << ", y = " << ogon.center().y_ << std::endl;
    std::cout << "Enter 4 numbers - 2 pairs diagonal coordinates for square:"<< std::endl;
    Square sqr;
    std::cin >> sqr;
    sqr.print_figure();
    std::cout << "Area = " << sqr.area() << std::endl;
    std::cout << "Center x = " << sqr.center().x_ << ", y = " << sqr.center().y_ << std::endl;
    std::cout << "Enter 6 numbers - 3 pairs coordinates for triangle:" << std::endl;
    Triangle tr;
    std::cin >> tr;
    tr.print_figure();
    std::cout << "Area = " << tr.area() << std::endl;
    std::cout << "Center x = " << tr.center().x_ << ", y = " << tr.center().y_ << std::endl;
}
//Тестирующая функция для вектора
void TestVector()
{
    //Вектор хранящий элементы типа Figure*
    std::vector<Figure*> figures;
    std::cout << "Enter 16 numbers, coordinates 8 points, in the correct order (in a circle) for octagon:" << std::endl;
    Octagon ogon;
    std::cin >> ogon;
    std::cout << "Enter 4 numbers - 2 pairs diagonal coordinates for square:"<< std::endl;
    Square sqr;
    std::cin >> sqr;
    std::cout << "Enter 6 numbers - 3 pairs coordinates for triangle:" << std::endl;
    Triangle tr;
    std::cin >> tr;
    figures.push_back(&ogon);
    figures.push_back(&sqr);
    figures.push_back(&tr);
    //Итератор на начало вектора
    std::vector<Figure*>::iterator iter = figures.begin();
    while(iter != figures.end())
    {
        //*iter элемент на который указывает iter, т.е Figure*
        (*iter)->print_figure();
        std::cout << "Area = " << (*iter)->area() << std::endl;
        std::cout << "Center x = " << (*iter)->center().x_ << ", y = " << (*iter)->center().y_ << std::endl;
        ++iter;
    }
    std::cout << "Summary area in vector: " << area_in_vector(figures) << std::endl;
    //удаляем элемент с индексом 0
    delete_el(figures, 0);
    iter = figures.begin();
    while(iter != figures.end())
    {
        //*iter элемент на который указывает iter, т.е Figure*
        (*iter)->print_figure();
        std::cout << "Area = " << (*iter)->area() << std::endl;
        std::cout << "Center x = " << (*iter)->center().x_ << ", y = " << (*iter)->center().y_ << std::endl;
        ++iter;
    }
    std::cout << "Summary area in vector after delete element by index: " << area_in_vector(figures) << std::endl;
}

int main()
{
    TestCin();
    TestVector();
    std::string name = "start";
	std::cout << "Enter q or Q or quit or Quit for close programm" << std::endl;
	//Бесконечный дикл до ввода ключевого слова для выхода
	while(true)
	{
		std::cout << "Enter test file name: ";
		std::cin >> name;
		if (name == "Q" || name == "q" || name == "Quit" || name == "quit") break;
		//поток ввода из файла, имя файла хранится в string переменной name
		std::ifstream finp(name.c_str());
        std::string s11, s12, s21, s22;
        std::string t11, t12, t21, t22, t31, t32;
        std::string p11, p12, p21, p22, p31, p32, p41, p42, p51, p52;
        std::string p61, p62, p71, p72, p81, p82;
        //Взятие 16 чисел для восьмиугольника из файла
		finp >> p11 >> p12 >> p21 >> p22 >> p31 >> p32 >> p41 >> p42 >> p51 >> p52 >> p61 >> p62 >> p71 >> p72 >> p81 >> p82;
        //Взятие 4 чисел для квадрата из файла
        finp >> s11 >> s12 >> s21 >> s22;
        //Взятие 6 чисел для треугольника из файла
        finp >> t11 >> t12 >> t21 >> t22 >> t31 >> t32;
        try
        {
            TestOctagon(std::stod(p11), std::stod(p12), std::stod(p21), std::stod(p22), std::stod(p31), std::stod(p32), std::stod(p41),
            std::stod(p42), std::stod(p51), std::stod(p52), std::stod(p61), std::stod(p62), std::stod(p71), std::stod(p72), std::stod(p81), std::stod(p82));
            TestSquare(std::stod(s11), std::stod(s12), std::stod(s21), std::stod(s22));
            TestTriangle(std::stod(t11), std::stod(t12), std::stod(t21), std::stod(t22), std::stod(t31), std::stod(t32));
        }
        catch(std::exception& ex) 
        {
            std::cerr << "Incorrect data" << std::endl;
            std::cerr << ex.what() << std::endl;
        }
		finp.close();
	}
	return 0;
}
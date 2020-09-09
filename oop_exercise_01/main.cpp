//Пищик Е.С. М8О-206Б-19 Лабораторная работа №1 вариант 20
/*Создать класс Bottle для работы с емкостями. Класс должен состоять из двух вещественных чисел: 
a - объем емкости в литрах и b – процент наполнения емкости (0 – пустая, 1 – полная). 
Реализовать операции сложения и вычитания, а также сравнения объектов класса бутылка. 
При сложении должен складываться фактический объем заполнения бутылок.*/
#include <iostream>
#include <fstream>
#include <string>

class Bottle
{
	//2 приватных поля, a_ - объем емкости, b_ - процент заполнения емкости
	//a_ >= 0, 0 <= b_ <= 1 
	double a_;
	double b_;
	public:
	// Конструктор класса
	explicit Bottle(double const& a = 0, double const& b = 0) : a_(a), b_(b) {}
	//Геттеры
	double getA() { return a_; }
	double getB() { return b_; }
};

//оператор сложения двух бутылок
Bottle operator+(Bottle & lhs, Bottle & rhs)
{
	return Bottle(lhs.getA() + rhs.getA(), (lhs.getA() * lhs.getB() + rhs.getA() * rhs.getB()) / (lhs.getA() + rhs.getA()));
}

//оператор вычитания двух бутылок
Bottle operator-(Bottle & lhs, Bottle & rhs)
{
	//разница объемов жидкости
	double v_filled = lhs.getA() * lhs.getB() - rhs.getA() * rhs.getB();
	//разница максимальных объемов
	double v = lhs.getA() - rhs.getA();
	return Bottle(v > 0 ? v : -v, v_filled > 0 ? v_filled : -v_filled);
}

//операторы сравнения
//сравнение по текущему объему жидкости
bool operator<(Bottle & lhs, Bottle & rhs) { return lhs.getA() * lhs.getB() < rhs.getA() * rhs.getB(); }
bool operator>(Bottle & lhs, Bottle & rhs) { return rhs < lhs; }
bool operator<=(Bottle & lhs, Bottle & rhs) { return !(rhs < lhs); }
bool operator>=(Bottle & lhs, Bottle & rhs) { return !(lhs < rhs); }
bool operator==(Bottle & lhs, Bottle & rhs) { return !(rhs < lhs) && !(lhs < rhs); }
bool operator!=(Bottle & lhs, Bottle & rhs) { return !(lhs == rhs); }


//Тестирующая функция, в файл с тестом должно быть записано 6 числе типа double
void TestFunction(double p_11, double p_12, double p_21, double p_22, double p_31, double p_32)
{
	Bottle s1(p_11, p_12);
	Bottle s2(p_21, p_22);
	Bottle s3(p_31, p_32);
	Bottle s;
	Bottle t;
	s = s1 + s2;
	t = s2 - s1;
	std::cout << std::endl <<"First bottle: a = " << s1.getA() << " b = " << s1.getB() << std::endl;
	std::cout << "Second bottle: a = " << s2.getA() << " b = " << s2.getB() << std::endl;
	std::cout << "Third bottle: a = " << s3.getA() << " b = " << s3.getB() << std::endl;
	std::cout << "Sum first and second bottles: a = " << s.getA() << " b = " << s.getB() << std::endl;
	std::cout << "Sub first and second bottles: a = " << t.getA() << " b = " << t.getB() << std::endl;
	if (s1 < s2) std::cout << "first bottle < second bottle" << std::endl;
	else std::cout << "first bottle > second bottle" << std::endl;
	if (s1 == s3) std::cout << "first bottle = third bottle" << std::endl;
	else std::cout << "first bottle != third bottle" << std::endl;
	if (s1 == s2) std::cout << "first bottle = second bottle" << std::endl;
	else std::cout << "first bottle != second bottle" << std::endl;
	std::cout << "Completed\n" << std::endl;
}

int main()
{
	std::string name = "start";
	std::cout << "Enter q or Q or quit or Quit for close programm" << std::endl;
	//Бесконечный дикл до ввода ключевого слова для выхода
	while(true)
	{
		double a = 0, b = 0, c = 0, d = 0, e = 0, f = 0;
		std::cout << "Enter test file name: ";
		std::cin >> name;
		if (name == "Q" || name == "q" || name == "Quit" || name == "quit") break;
		//поток ввода из файла, имя файла хранится в string переменной name
		std::ifstream finp(name.c_str());
		//взятие из файла 6 чисел и запись в переменные
		finp >> a >> b >> c >> d >> e >> f;
		TestFunction(a, b, c, d, e, f);
		finp.close();
	}
	return 0;
}
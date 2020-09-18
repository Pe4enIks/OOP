//Пищик Е.С. М8О-206Б-19 Лабораторная работа №2 вариант 9
/*Создать класс BritishMoney для работы с денежными суммами в старой британской система. 
Сумма денег должна быть представлено тремя полями: типа unsigned long long для фунтов стерлингов,
типа unsigned long long – для шиллингов, unsigned long long – для пенсов (пенни). 
Реализовать сложение сумм, вычитание, деление сумм, деление суммы на дробное число, 
умножение на дробное число и операции сравнения. 1 фунт = 20 шиллингов, 1 шиллинг = 12 пенни. 
Операции сложения, вычитания, умножения, деления, 
сравнения (на равенство, больше и меньше) должны быть выполнены в виде перегрузки операторов. 
Необходимо реализовать пользовательский литерал для работы с константами типа BritishMoney.*/
//В тест файл вводится 9 чисел, где каждые 3 след числа - стерлинги, шиллинги и пенни для экземпляра класса
#include <iostream>
#include <fstream>
#include <string>
typedef unsigned long long ull;
class BritishMoney
{
	//3 приватных поля, ster_ - стерлинги, shil_ - шиллинги, penni_ - пенни
	ull ster_;
	ull shil_;
	ull penni_;
	public:
	// Конструктор класса
	explicit BritishMoney(ull const& ster = 0, ull const& shil = 0, ull const& penni = 0) : 
	ster_(ster), shil_(shil), penni_(penni) {}
	//Геттеры
	ull get_ster() const { return ster_; }
	ull get_shil() const { return shil_; }
	ull get_penni() const { return penni_;}
};
//Пользовательский литерал - ster, ввод количества стрелингов, shil - шиллинги, penni - пенни
BritishMoney operator""_ster(ull obj)
{
    return BritishMoney(obj, 0, 0);
}
BritishMoney operator""_shil(ull obj)
{
    return BritishMoney(0, obj, 0);
}
BritishMoney operator""_penni(ull obj)
{
    return BritishMoney(0, 0, obj);
}
//оператор сложения денег
BritishMoney operator+(BritishMoney & lhs, BritishMoney & rhs)
{
	ull dop_shil = lhs.get_penni() + rhs.get_penni() >= 12 ? 1 : 0;
	ull res_penni = lhs.get_penni() + rhs.get_penni() >= 12 ? 
	lhs.get_penni() + rhs.get_penni() - 12 : lhs.get_penni() + rhs.get_penni();
	ull dop_ster = lhs.get_shil() + rhs.get_shil() + dop_shil  >= 20 ? 1 : 0;
	ull res_shil = lhs.get_shil() + rhs.get_shil() + dop_shil >= 20 ?
	lhs.get_shil() + rhs.get_shil() + dop_shil - 20: lhs.get_shil() + rhs.get_shil() + dop_shil;
	ull res_ster = lhs.get_ster() + rhs.get_ster() + dop_ster;
	return BritishMoney(res_ster, res_shil, res_penni);
}

//оператор вычитания
BritishMoney operator-(BritishMoney & lhs, BritishMoney & rhs)
{
	ull res_lhs = lhs.get_penni() + 12 * lhs.get_shil() + 240 * lhs.get_ster();
	ull res_rhs = rhs.get_penni() + 12 * rhs.get_shil() + 240 * rhs.get_ster();
	if(res_lhs <= res_rhs) {return BritishMoney(0, 0, 0);}
	ull res = res_lhs - res_rhs;
	ull res_ster = res / 240;
	ull res_shild = (res - 240 * res_ster) / 12;
	ull res_penni = res - 240 * res_ster - 12 * res_shild;
	return BritishMoney(res_ster, res_shild, res_penni);
}
//операторы деления
double operator/(BritishMoney & lhs, BritishMoney & rhs)
{
	double res_lhs = lhs.get_penni() + 12 * lhs.get_shil() + 240 * lhs.get_ster();
	double res_rhs = rhs.get_penni() + 12 * rhs.get_shil() + 240 * rhs.get_ster();
	return res_lhs / res_rhs;
}
BritishMoney operator/(BritishMoney & lhs, double const& rhs)
{
	ull res = (lhs.get_penni() + 12 * lhs.get_shil() + 240 * lhs.get_ster()) / rhs;
	ull res_ster = res / 240;
	ull res_shild = (res - 240 * res_ster) / 12;
	ull res_penni = res - 240 * res_ster - 12 * res_shild;
	return BritishMoney(res_ster, res_shild, res_penni);
}
//оператор умножения
BritishMoney operator*(BritishMoney & lhs, double const& rhs)
{
	ull res = (lhs.get_penni() + 12 * lhs.get_shil() + 240 * lhs.get_ster()) * rhs;
	ull res_ster = res / 240;
	ull res_shild = (res - 240 * res_ster) / 12;
	ull res_penni = res - 240 * res_ster - 12 * res_shild;
	return BritishMoney(res_ster, res_shild, res_penni);
}

//операторы сравнения
bool operator<(BritishMoney & lhs, BritishMoney & rhs) 
{
	if(lhs.get_ster() == rhs.get_ster())
	{
		if(lhs.get_shil() == rhs.get_shil()) { return lhs.get_shil() < rhs.get_shil(); }
		else { return lhs.get_shil() < rhs.get_shil(); }
	}
	else {return lhs.get_ster() < rhs.get_ster(); } 
}
bool operator>(BritishMoney & lhs, BritishMoney & rhs) { return rhs < lhs; }
bool operator<=(BritishMoney & lhs, BritishMoney & rhs) { return !(rhs < lhs); }
bool operator>=(BritishMoney & lhs, BritishMoney & rhs) { return !(lhs < rhs); }
bool operator==(BritishMoney & lhs, BritishMoney & rhs) { return !(rhs < lhs) && !(lhs < rhs); }
bool operator!=(BritishMoney & lhs, BritishMoney & rhs) { return !(lhs == rhs); }


//Тестирующая функция, в файл с тестом должно быть записано 6 числе типа double
void TestFunction(ull p_11 = 0, ull p_12 = 0, ull p_13 = 0, ull p_21 = 0, 
ull p_22 = 0, ull p_23 = 0, ull p_31 = 0, ull p_32 = 0, ull p_33 = 0)
{
    //Создание денег
	BritishMoney s1(p_11, p_12, p_13);
	BritishMoney s2(p_21, p_22, p_23);
	BritishMoney s3(p_31, p_32, p_33);
    //Использование пользовательских литералов для создания объектов типа BritishMoney
    BritishMoney s4 = 135_ster;
	BritishMoney s5 = 13_shil;
	BritishMoney s6 = 7_penni; 
    //Создание
	BritishMoney s;
	BritishMoney t;
	BritishMoney r;
	BritishMoney f;
	BritishMoney e;
	double div = 0;
    //Сложение, вычитание деление умножение
	s = s1 + s2;
	t = s2 - s1;
	r = s1 - s2;
	div = s1 / s2;
	f = s1 / 2.0;
	e = f * 3.0;
	std::cout <<"First: ster = " << s1.get_ster() << " shil = " << s1.get_shil();
	std::cout << " penni = " << s1.get_penni() << std::endl;
	std::cout <<"Second: ster = " << s2.get_ster() << " shil = " << s2.get_shil();
	std::cout << " penni = " << s2.get_penni() << std::endl;
	std::cout <<"Third: ster = " << s3.get_ster() << " shil = " << s3.get_shil();
	std::cout << " penni = " << s3.get_penni() << std::endl;
    std::cout << "Fourth created by literal _ster: ster = " << s4.get_ster() << " shil = ";
	std::cout << s4.get_shil() << " penni = " << s4.get_penni() << std::endl;
	std::cout << "Fifth created by literal _shil: ster = " << s5.get_ster() << " shil = ";
	std::cout << s5.get_shil() << " penni = " << s5.get_penni() << std::endl;
	std::cout << "Sixth created by literal _penni: ster = " << s6.get_ster() << " shil = ";
	std::cout << s6.get_shil() << " penni = " << s6.get_penni() << std::endl;
	std::cout << "Sum first and second : ster = " << s.get_ster() << " shil = " << s.get_shil();
	std::cout << " penni = " << s.get_penni() << std::endl;
	std::cout << "Sub second and first : ster = " << t.get_ster() << " shild = ";
	std::cout << t.get_shil() << " penni = " << t.get_penni() << std::endl;
	std::cout << "Sub first and second : ster = " << r.get_ster() << " shild = ";
	std::cout << r.get_shil() << " penni = " << r.get_penni() << std::endl;
	std::cout << "First div second = " << div << std::endl;
	std::cout << "First div double = 2.0 : ster = " << f.get_ster() << " shild = ";
	std::cout << f.get_shil() << " penni = " << f.get_penni() << std::endl;
	std::cout << "First mul double = 3.0 : ster = " << e.get_ster() << " shild = ";
	std::cout << e.get_shil() << " penni = " << e.get_penni() << std::endl;
    //Сравнение
	if (s1 < s2) std::cout << "first < second" << std::endl;
	else std::cout << "first > second" << std::endl;
	if (s1 == s3) std::cout << "first = third" << std::endl;
	else std::cout << "first != third" << std::endl;
	if (s1 == s2) std::cout << "first = second" << std::endl;
	else std::cout << "firste != second" << std::endl;
	std::cout << "Completed\n" << std::endl;
}

int main()
{
	std::string name = "start";
	std::cout << "Take 9 numbers from test_file - 3 pairs(sterlings, shillings, pennies)" << std::endl;
	std::cout << "Enter q or Q or quit or Quit for close programm" << std::endl;
	//Бесконечный дикл до ввода ключевого слова для выхода
	while(true)
	{
		ull a = 0, d = 0, g = 0;  
		ull b = 0, c = 0, e = 0, f = 0, h = 0, k = 0;
		std::cout << "Enter test file name: ";
		std::cin >> name;
		if (name == "Q" || name == "q" || name == "Quit" || name == "quit") break;
		//поток ввода из файла, имя файла хранится в string переменной name
		std::ifstream finp(name.c_str());
		//взятие из файла 9 чисел и запись в переменные
		finp >> a >> b >> c >> d >> e >> f >> g >> h >> k;
		TestFunction(a, b, c, d, e, f, g, h, k);
		finp.close();
	}
	return 0;
}
#include <iostream>
#include "Vector.hpp"

void printHeader();

int main()
{
	printHeader();

	try
	{
		Vector<int> arr(4);
		arr.push_back(1);
		arr.push_back(4);
		arr.push_back(155);
		arr.push_back(23);
		arr.push_back(18);

		arr.print("arrInt");
		int ind(3);
		std::cout << "Печатаю индекс " << ind << ": " << arr.at(ind) << std::endl;
		std::cout << "Текущий размер массива: " << arr.size() << std::endl;
		std::cout << "Ёмкость нашего вектора: " << arr.capacity() << std::endl << std::endl;

		Vector<double> arrDoub(20);
		arrDoub.push_back(1);
		arrDoub.push_back(4.8);
		arrDoub.push_back(155.23);
		arrDoub.push_back(18.5);

		arrDoub.print("arrDoub");
		ind = 1;
		std::cout << "Печатаю индекс " << ind << ": " << arrDoub.at(ind) << std::endl;
		std::cout << "Текущий размер массива: " << arrDoub.size() << std::endl;
		std::cout << "Ёмкость нашего вектора: " << arrDoub.capacity() << std::endl << std::endl;
	}
	catch (const std::bad_alloc)
	{
		std::cout << "Ошибка: недостаточно памяти!" << std::endl;
	}
	catch (const std::exception& ex)
	{
		std::cout << "Ошибка: " << ex.what() << std::endl;
	}

	return 0;
}


// функции
// заголовок 
void printHeader()
{
	using namespace std;
	setlocale(LC_ALL, "Russian");   // задаём русский текст
	system("chcp 1251");            // настраиваем кодировку консоли
	std::system("cls");
	cout << "Задача 3*. Аналог std::vector\n"
		 << "-----------------------------\n" << endl;
}

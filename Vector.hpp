#pragma once
#include <iostream>

template <class T>
class Vector
{
protected:
private:
	T* array_ = nullptr;// массив элементов типа Т
	size_t size_;		// текущий размер массива
	size_t capacity_;	// ёмкость массива

public:
	// конструктор
	Vector(const size_t capacity) : size_(0), capacity_(capacity > 0 ? capacity : 1)
	{
		array_ = new T[capacity_];
	}
	Vector(const Vector& sma) = delete; // конструктор копирования
	// деструктор
	~Vector()
	{
		if (array_) delete[] array_;
	}

	void push_back(const T element)	// добавляем элемент к конец
	{
		if (size_ >= capacity_)	// нужно увеличить ёмкость(вместимость) массива
		{
			capacity_ = 2 * size_;
			T* moreArr = new T[capacity_];
			for (int i = 0; i < size_; ++i) moreArr[i] = array_[i];

			delete[] array_;
			array_ = moreArr;
		}
		array_[size_] = element;
		++size_;
	}
	T at(const int index)		// беру элемент по индексу
	{
		if (index < 0 || index >= size_) throw std::exception("не верный индекс (at)!");
		return array_[index];
	}
	size_t size()
	{
		return size_;
	}
	size_t capacity()
	{
		return capacity_;
	}
	void print(const std::string& str)		// вывод в консоль
	{
		std::cout << "Массив " << str << ": ";
		for (int i = 0; i < size_; ++i)
		{
			std::cout << array_[i] << " ";
		}
		std::cout << std::endl;
	}
	Vector& operator= (const Vector& sma) = delete;	// перегрузка =
};


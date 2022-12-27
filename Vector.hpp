#pragma once
#include <iostream>

template <class T>
class Vector
{
protected:
private:
	T* array_ = nullptr;// ������ ��������� ���� �
	size_t size_;		// ������� ������ �������
	size_t capacity_;	// ������� �������

public:
	// �����������
	Vector(const size_t capacity) : size_(0), capacity_(capacity > 0 ? capacity : 1)
	{
		array_ = new T[capacity_];
	}
	Vector(const Vector& sma) = delete; // ����������� �����������
	// ����������
	~Vector()
	{
		if (array_) delete[] array_;
	}

	void push_back(const T element)	// ��������� ������� � �����
	{
		if (size_ >= capacity_)	// ����� ��������� �������(�����������) �������
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
	T at(const int index)		// ���� ������� �� �������
	{
		if (index < 0 || index >= size_) throw std::exception("�� ������ ������ (at)!");
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
	void print(const std::string& str)		// ����� � �������
	{
		std::cout << "������ " << str << ": ";
		for (int i = 0; i < size_; ++i)
		{
			std::cout << array_[i] << " ";
		}
		std::cout << std::endl;
	}
	Vector& operator= (const Vector& sma) = delete;	// ���������� =
};


#pragma once
#include <iostream>
class fraction //перегрузка 
{
private:
	unsigned int numerator;
	unsigned int denominator;
public:
	fraction();
	fraction(const unsigned int num, const unsigned int den);
	fraction operator+(const fraction& obj);
	fraction operator-(const fraction& obj);
	fraction operator*(const fraction& obj);
	fraction operator/(const fraction& obj);
	fraction operator+(const int& value); //унарные операторы(сохраняет новое значение в один из начальных слагаемых)
	fraction operator-(const int& value);
	operator float();
	void show();
};


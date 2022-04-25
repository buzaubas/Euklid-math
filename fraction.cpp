#include "fraction.h"

fraction::fraction() // : unsigned int(0) (через делегирование)
{
	numerator = 0;
	denominator = 0;
}

fraction::fraction(const unsigned int num, const unsigned int den)
{
	this->numerator = num;
	this->denominator = den;
}

fraction fraction::operator+(const fraction& obj)
{
	size_t NOK;
	size_t max;
	if (this->denominator >= obj.denominator)
	{
		max = this->denominator;
	}
	else 
	{
		max = obj.denominator;
	}
	for (size_t i = max; i > 0; i++) {

		if ((i % this->denominator == 0) && (i % obj.denominator == 0)) {
			NOK = i;
			break;
		}
	}
	size_t priv_one = NOK / this->denominator;
	size_t priv_two = NOK / obj.denominator;

	fraction new_one(this->numerator * priv_one, NOK), new_two(obj.numerator * priv_two, NOK);

	return fraction(new_one.numerator + new_two.numerator, NOK);
}

fraction fraction::operator-(const fraction& obj)
{
	size_t NOK;
	size_t max;
	if (this->denominator >= obj.denominator)
	{
		max = this->denominator;
	}
	else
	{
		max = obj.denominator;
	}
	for (size_t i = max; i > 0; i++) {

		if ((i % this->denominator == 0) && (i % obj.denominator == 0)) {
			NOK = i;
			break;
		}
	}
	size_t priv_one = NOK / this->denominator;
	size_t priv_two = NOK / obj.denominator;

	fraction new_one(this->numerator * priv_one, NOK), new_two(obj.numerator * priv_two, NOK);
	return fraction(new_one.numerator - new_two.numerator, NOK);
}

fraction::operator float()
{
	if (numerator == 0 && denominator == 0)
		return 0;
	if (denominator == 0)
	{
		std::cout << "Error" << std::endl;
		return FLT_MAX;
	}
	return (float)this->numerator / (float)this->denominator;
}

void fraction::show()
{
	std::cout << this->numerator;
	std::cout << "/";
	std::cout << this->denominator << std::endl;
}

fraction fraction::operator*(const fraction& obj)
{
	size_t a = this->numerator * obj.numerator;
	size_t b = this->denominator * obj.denominator;
	size_t euklid;

	while (a != 0 && b != 0)
	{
		if (a > b)
			a = a % b;
		else
			b = b % a;
		euklid = a + b;
	}

	return fraction((this->numerator * obj.numerator) / euklid, (this->denominator * obj.denominator) / euklid);
}

fraction fraction::operator/(const fraction& obj)
{

	size_t a = this->numerator * obj.numerator;
	size_t b = this->denominator * obj.denominator;
	size_t euklid;

	while (a != 0 && b != 0)
	{
		if (a > b)
			a = a % b;
		else
			b = b % a;
		euklid = a + b;
	}

	return fraction((this->numerator * obj.denominator) / euklid, (this->denominator * obj.numerator) / euklid);
}

fraction fraction::operator+(const int& value)
{
	fraction obj(value, 1);

	size_t NOK;
	size_t max;
	if (this->denominator >= obj.denominator)
	{
		max = this->denominator;
	}
	else
	{
		max = obj.denominator;
	}
	for (size_t i = max; i > 0; i++) 
	{

		if ((i % this->denominator == 0) && (i % obj.denominator == 0)) {
			NOK = i;
			break;
		}
	}
	size_t priv_one = NOK / this->denominator;
	size_t priv_two = NOK / obj.denominator;

	fraction new_one(this->numerator * priv_one, NOK), new_two(obj.numerator * priv_two, NOK);
	return fraction(new_one.numerator + new_two.numerator, NOK);
}

fraction fraction::operator-(const int& value)
{
	fraction obj(value, 1);

	size_t NOK;
	size_t max;
	if (this->denominator >= obj.denominator)
	{
		max = this->denominator;
	}
	else
	{
		max = obj.denominator;
	}
	for (size_t i = max; i > 0; i++) 
	{
		if ((i % this->denominator == 0) && (i % obj.denominator == 0)) {
			NOK = i;
			break;
		}
	}
	size_t priv_one = NOK / this->denominator;
	size_t priv_two = NOK / obj.denominator;

	fraction new_one(this->numerator * priv_one, NOK), new_two(obj.numerator * priv_two, NOK);
	return fraction(new_one.numerator - new_two.numerator, NOK);
}

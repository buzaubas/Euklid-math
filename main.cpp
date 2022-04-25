#include <iostream>
#include "fraction.h"

int main()
{
	//fraction first(3, 5), second(1, 2), third;
	fraction first(2, 3), second(2, 2), third;

	third = first + second;
	third.show();
	std::cout << third << std::endl << std::endl;

	third = first - second;
	third.show();
	std::cout << third << std::endl << std::endl;

	third = first * second;
	third.show();
	std::cout << third << std::endl << std::endl;

	third = first / second;
	third.show();
	std::cout << third << std::endl << std::endl;

	return 0;
}

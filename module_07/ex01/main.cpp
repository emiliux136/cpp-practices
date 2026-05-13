#include "iter.hpp"
#include <iostream>
#include <cctype>
#include <cmath>

void toup(char &arr)
{
	arr = std::toupper(static_cast<unsigned char>(arr));
}

void sum_one(int &value)
{
	value = value + 1;
}

void apply_round(double &value)
{
	value = std::round(value);
}

int main()
{
	char array[] = "Hola que tal";
	std::cout << "Original: " << array << std::endl;
	::iter(array, 12, toup);
	std::cout << "Modified: " << array << std::endl;
	std::cout << std::endl;

	std::cout << "Original: ";
	int enteros[4] = {0, 1, 2, 3};
	for (int i = 0; i < 4; i++)
		std::cout << enteros[i] << ' ';
	std::cout << std::endl;
	::iter(enteros, 4, sum_one);
	std::cout << "Modified: ";
	for (int i = 0; i < 4; i++)
		std::cout << enteros[i] << ' ';
	std::cout << std::endl;	
	std::cout << std::endl;	

	double numbers[5] = {1.56, 2.10, 37.455, 4.68, 5.23};
	std::cout << "Original: ";
	for (int i = 0; i < 5; i++)
		std::cout << numbers[i] << ' ';
	std::cout << std::endl;
	::iter(numbers, 5, apply_round);
	std::cout << "Modified: ";
	for (int i = 0; i < 5; i++)
		std::cout << numbers[i] << ' ';
	std::cout << std::endl;

	return (0);
}
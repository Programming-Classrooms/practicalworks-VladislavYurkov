#include <iostream>


/*
Написать программу, которая на заданном отрезке [a,b]
натурального ряда чисел находит все числа Армстронга
*/


int main()
{
	int64_t a = 0, b = 0;
	while (a < 1)
	{
		std::cout << "Input a: ";
		std::cin >> a;
	}
	while (b < 1)
	{
		std::cout << "Input b: ";
		std::cin >> b;
	}
	if (a > b) { 
		int64_t help = a;
		a = b;
		b = help;
	}
	{
		size_t length;
		uint64_t tempNumber, sumOfDigits;
		for (size_t i = a; i <= b; ++i)
		{
			length = 0;
			tempNumber = i, sumOfDigits = 0;
			while (tempNumber)
			{
				tempNumber /= 10;
				length++;
			}
			tempNumber = i;
			for (size_t j = 0; j < length; ++j)
			{
				sumOfDigits += pow(tempNumber % 10, length);
				tempNumber /= 10;
			}
			if (sumOfDigits == i) {
				std::cout << i << std::endl;
			}
		}
	}
	return 0;
}

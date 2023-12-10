#include <iostream>


/*
Написать программу, которая для заданного натурального числа
выполняет разложение числа на простые множители.
*/


int main()
{
	int64_t number = 0;
	try
	{
		std::cout << "Input natural number: ";
		std::cin >> number;
		if (number < 1)
		{
			throw "number is not natural";
		}
	}

	catch (const char* e)
	{
		std::cout << e << '\n';
	}


	std::cout << number << " = ";
	while (number > 1)
	{
		for (int64_t i = 2; i <= number;)
		{
			if (number % i)
			{
				++i;
			}
			else
			{
				number /= i;
				if (number != 1)
				{
					std::cout << i << " * ";
				}
				else
				{
					std::cout << i;
				}
			}
		}
	}

	return 0;
}

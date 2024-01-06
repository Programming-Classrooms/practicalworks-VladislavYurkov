/*
	Написать программу, которая для заданного натурального числа
	добавляет слева и справа в записи числа цифру, повторяющуюся
	максимальное число раз
*/


#include <iostream>
#include <cmath>


int main()
{
	try 
	{
		int64_t number = 0;
		std::cout << "Input natural number: ";
		std::cin >> number;

		if (number < 1)
		{
			throw "n isn't natural";
		}

		int16_t maxCount = 0;
		int16_t maxDigit = 0;

		int64_t numberCopy = number;
		int16_t numberLength = 0;

		while (numberCopy)
		{
			int16_t digit = numberCopy % 10;
			int16_t count = 0;

			int64_t tempNumber = numberCopy;
			while (tempNumber)
			{
				int currentDigit = tempNumber % 10;
				if (currentDigit == digit)
				{
					++count;
				}
				tempNumber /= 10;
			}

			if (count > maxCount)
			{
				maxCount = count;
				maxDigit = digit;
			}


			numberCopy /= 10;
			++numberLength;
		}

		if (!maxDigit)
		{
			throw "The most often number is zero";
		}

		number += maxDigit * pow(10, numberLength);
		number *= 10;
		number += maxDigit;

		std::cout << "Modified number: " << number << '\n';
	}
	catch (const char* e)
	{
		std::cout << e << '\n';
	}
	return 0;
}

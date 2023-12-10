#include <iostream>

/*
Написать программу, которая находит в последовательности,
состоящей из цифр подряд записанных натуральных чисел,
цифру с заданным номером.
*/


int main()
{
	int32_t T = 0;
	while (T < 1)
	{
		std::cout << "Input T: ";
		std::cin >> T;
	}


	int32_t firstPrime = 0;
	int32_t secondPrime = -100;
	for (int32_t i = 2;T; ++i)
	{
		bool isPrime = true;
		for (int32_t j = 2; j <= sqrt(i); ++j)
		{
			if (!(i % j))
			{
				isPrime = false;
			}
		}


		if (isPrime)
		{
			if (firstPrime)
			{
				secondPrime = firstPrime;
			}
			firstPrime = i;
			if (firstPrime - secondPrime == 2)
			{
				std::cout << secondPrime << " " << firstPrime << std::endl;
				--T;
			}
		}
	}

	
	return 0;
}

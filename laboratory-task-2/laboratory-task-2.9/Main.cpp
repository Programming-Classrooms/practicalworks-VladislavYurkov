/*
Написать программу, которая для заданного натурального
числа N находит, не превышающие это число дружественные
*/


#include <iostream>


int main()
{
	int64_t n = 0;
	while (n < 1)
	{
		std::cout << "Input natural n: ";
		std::cin >> n;
	}


	int64_t firstPrimary;
	int64_t secondPrimary;
	for (int64_t i = 2; i <= n; ++i)
	{
		firstPrimary = i;
		int64_t sumOfDevidersOfFirstPrimary = 1, sumOfDevidersOfSecondPrimary = 1; ;
		for (int64_t j = 2; j < firstPrimary; ++j)
		{
			if (!(firstPrimary % j))
			{
				sumOfDevidersOfFirstPrimary += j;
			}
		}
		secondPrimary = sumOfDevidersOfFirstPrimary;
		for (int64_t k = 2; k < secondPrimary; ++k)
		{
			if (!(secondPrimary % k))
			{
				sumOfDevidersOfSecondPrimary += k;
			}
		}
		if (sumOfDevidersOfSecondPrimary == firstPrimary && firstPrimary < secondPrimary)
		{
			std::cout << firstPrimary << " and " << secondPrimary << std::endl;
		}

	}
	return 0;
}

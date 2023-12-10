#include <iostream>


/*
Написать программу, которая для заданного натурального
числа N находит, не превышающие это число дружественные
*/


int main()
{
	int64_t n = 0;
	while (n < 1)
	{
		std::cout << "Input natural n: ";
		std::cin >> n;
	}


	int64_t temp1,temp2;
	for (int64_t i = 2; i <= n; ++i)
	{
		temp1 = i;
		int64_t sum1 = 1, sum2 = 1; ;
		for (int64_t j = 2; j < temp1; ++j)
		{
			if (!(temp1 % j))
			{
				sum1 += j;
			}
		}
		temp2 = sum1;
		for (int64_t k = 2; k < temp2; ++k)
		{
			if (!(temp2 % k))
			{
				sum2 += k;
			}
		}
		if (sum2 == temp1 && temp1 < temp2)
		{
			std::cout << temp1 << " and " << temp2 << std::endl;
		}

	}
	return 0;
}

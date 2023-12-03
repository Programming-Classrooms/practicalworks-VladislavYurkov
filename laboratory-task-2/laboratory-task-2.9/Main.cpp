#include <iostream>
int main()
{
	unsigned long long n = 0;
	while (n < 1)
	{
		std::cout << "Input natural n: ";
		std::cin >> n;
	}
	unsigned long long temp1,temp2;
	for (unsigned long long i = 2; i <= n; ++i)
	{
		temp1 = i;
		unsigned long long sum1 = 1, sum2 = 1; ;
		for (unsigned long long j = 2; j < temp1; ++j)
		{
			if (!(temp1 % j))
			{
				sum1 += j;
			}
		}
		temp2 = sum1;
		for (unsigned long long k = 2; k < temp2; ++k)
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
	EXIT_SUCCESS;
}
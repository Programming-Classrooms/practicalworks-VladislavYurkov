#include <iostream>
int main()
{
	unsigned long long n = 0;
	while (n < 1)
	{
		std::cout << "Input natural n: ";
		std::cin >> n;
	}
	std::cout << n << " = ";
	while (n > 1)
	{
		for (unsigned long long i = 2; i <= n;)
		{
			if (n % i)
			{
				++i;
			}
			else
			{
				n /= i;
				if (n != 1)
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

	EXIT_SUCCESS;
}
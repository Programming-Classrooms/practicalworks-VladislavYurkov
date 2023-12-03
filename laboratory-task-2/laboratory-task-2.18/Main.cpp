#include <iostream>
int main()
{
	int T = 0;
	while (T < 1)
	{
		std::cout << "Input T: ";
		std::cin >> T;
	}
	int prim_1 = 0;
	int prim_2 = -100;
	for (int i = 2;T; ++i)
	{
		bool is_prime = true;
		for (int j = 2; j <= sqrt(i); ++j)
		{
			if (!(i % j))
			{
				is_prime = false;
			}
		}
		if (is_prime)
		{
			if (prim_1)
			{
				prim_2 = prim_1;
			}
			prim_1 = i;
			if (prim_1 - prim_2 == 2)
			{
				std::cout << prim_2 << " " << prim_1 << std::endl;
				--T;
			}
		}
	}
	EXIT_SUCCESS;
}
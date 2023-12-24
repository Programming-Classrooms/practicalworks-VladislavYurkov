/*
Написать программу, которая находит для заданного натурального
N все пифагоровы тройки чисел, каждое из которых
не превосходит N.
*/


#include <iostream>


int main()
{
	int n = 0;
	while (n < 1)
	{
		std::cout << "Input natural n: ";
		std::cin >> n;
	}


	for (int i = 3; i <= n; ++i)
	{
		for (int j = i + 1; j <= n; ++j)
		{
			for (int k = j + 1; k <= n; ++k)
			{
				if (k * k == j * j + i * i)
				{
					std::cout << i << " " << j << " " << k << std::endl;
				}
			}
		}
	}


	return 0;
}

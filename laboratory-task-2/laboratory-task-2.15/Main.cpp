#include <iostream>
int main()
{
	unsigned long long a = 0, b = 0;
	while (a < 1)
	{
		std::cout << "Input natural a: ";
		std::cin >> a;
	}
	while (b < 1)
	{
		std::cout << "Input natural b: ";
		std::cin >> b;
	}
	if (a > b) { a ^= b ^= a ^= b; }
	{
		short temp1 = 0, temp2 = 0;
		bool first_iteration;
		for (int i = a; i <= b; i++)
		{
			first_iteration = true;
			bool is_true = true;
			int num = i;
			while (num > 0)
			{
				if (first_iteration) { temp1 = i % 10; first_iteration = false; }
				else { temp1 = temp2; }
				num /= 10;
				temp2 = num % 10;
				if (temp1 <= temp2)
				{
					is_true = false;
					break;
				}
			}
			if (is_true)
			{
				std::cout << i << std::endl;
			}

		}
	}
	EXIT_SUCCESS;
}
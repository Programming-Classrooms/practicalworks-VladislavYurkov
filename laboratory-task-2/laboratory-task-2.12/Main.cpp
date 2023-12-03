#include <iostream>
int main()
{
	unsigned long long a = 0, b = 0;
	while (a < 1)
	{
		std::cout << "Input a: ";
		std::cin >> a;
	}
	while (b < 1)
	{
		std::cout << "Input b: ";
		std::cin >> b;
	}
	if (a > b) { a ^= b ^= a ^= b; }
	{
		short len;
		uint64_t temp_num, sum;
		for (int i = a; i <= b; ++i)
		{
			len = 0;
			temp_num = i, sum = 0;
			while (temp_num)
			{
				temp_num /= 10;
				len++;
			}
			temp_num = i;
			for (int j = 0; j < len; ++j)
			{
				sum += pow(temp_num % 10, len);
				temp_num /= 10;
			}
			if (sum == i) {
				std::cout << i << std::endl;
			}
		}
	}
	EXIT_SUCCESS;
}
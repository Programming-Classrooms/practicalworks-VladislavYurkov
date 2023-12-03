#include <iostream>
#include <cmath>
int main()
{
	unsigned long long n = 0;
	short res = 0;
	short d0 = 0;
	short d1 = 1;
	short d2 = 2;
	short d3 = 3;
	short d4 = 4;
	short d5 = 5;
	short d6 = 6;
	short d7 = 7;
	short d8 = 8;
	short d9 = 9;
	while (n < 1)
	{
		std::cout << "Input natural n: ";
		std::cin >> n;
	}
	unsigned long long new_n = n;
	short len = 0;
	while (n)
	{
		++len;
		short temp = n % 10;
		switch (temp)
		{
		case 0:
			d0 += 10;
			break;
		case 1:
			d1 += 10;
			break;
		case 2:
			d2 += 10;
			break;
		case 3:
			d3 += 10;
			break;
		case 4:
			d4 += 10;
			break;
		case 5:
			d6 += 10;
			break;
		case 6:
			d6 += 10;
			break;
		case 7:
			d7 += 10;
			break;
		case 8:
			d8 += 10;
			break;
		case 9:
			d9 += 10;
			break;
		default:
			break;
		}
		n /= 10;
	}
	while (!res)
	{
		short res1 = std::max(d1, d2);
		short res2 = std::max(d3, d4);
		short res3 = std::max(d5, d6);
		short res4 = std::max(d7, d8);
		short res5 = std::max(d9, d0);
		short res11 = std::max(res1, res2);
		short res12 = std::max(res3, res4);
		short res21 = std::max(res11, res21);
		res = std::max(res21, res5);
	}
	short max_num = res % 10;
	new_n = max_num * pow(10, len + 1) + 10 * new_n + max_num;
	std::cout << "New n = " << new_n;
	EXIT_SUCCESS;
}

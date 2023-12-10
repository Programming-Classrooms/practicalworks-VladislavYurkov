#include <iostream>


/*
Написать программу, которая на заданном отрезке [a,b]
натурального ряда чисел находит числа, десятичная запись
которых есть строго возрастающая последовательность цифр
*/


int main()
{
	int64_t a = 0, b = 0;
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
	if (a > b) {
		int64_t help = a;
		a = b;
		b = help;
	}
	{
		short temp1 = 0, temp2 = 0;
		bool firstIteration;
		for (int i = a; i <= b; i++)
		{
			firstIteration = true;
			bool isTrue = true;
			int num = i;
			while (num > 0)
			{
				if (firstIteration) {
					temp1 = i % 10; firstIteration = false; 
				}
				else {
					temp1 = temp2;
				}
				num /= 10;
				temp2 = num % 10;
				if (temp1 <= temp2)
				{
					isTrue = false;
					break;
				}
			}
			if (isTrue)
			{
				std::cout << i << std::endl;
			}

		}
	}
	return 0;
}

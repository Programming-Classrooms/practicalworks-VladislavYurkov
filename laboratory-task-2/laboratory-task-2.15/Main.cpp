/*
Написать программу, которая на заданном отрезке [a,b]
натурального ряда чисел находит числа, десятичная запись
которых есть строго возрастающая последовательность цифр
*/


#include <iostream>


int main()
{
	int64_t a = 0;
	int64_t b = 0;
	
	while (a < 1) {
		std::cout << "Input natural a: ";
		std::cin >> a;
	}

	while (b < 1) {
		std::cout << "Input natural b: ";
		std::cin >> b;
	}

	if (a > b) {
		int64_t help = a;
		a = b;
		b = help;
	}

	short prevDigit = 0, nextDigit = 0;
	bool firstIteration;
	for (int i = a; i <= b; i++) {
		firstIteration = true;
		bool isFit = true;
		int num = i;

		while (num > 0) {
			if (firstIteration) {
				prevDigit = i % 10; firstIteration = false; 
			}
			else {
				prevDigit = nextDigit;
			}
			num /= 10;
			nextDigit = num % 10;
			if (prevDigit <= nextDigit)
			{
				isFit = false;
				break;
			}
		}
		if (isFit)
		{
			std::cout << i << std::endl;
		}

	}
return 0;
}

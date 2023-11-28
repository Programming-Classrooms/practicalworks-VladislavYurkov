#include <iostream>
#include <cmath>
int main()
{
	//Вариант 8
	/*
	Разработать консольное приложение для вычисления приближённого
значения функции, используя представление ее в виде ряда Тейлора.
Вычисления заканчивать, когда очередное слагаемое окажется по модулю
меньше заданного числа 𝑒𝑝𝑠𝑖𝑙𝑜𝑛, где 0 < 𝑒𝑝𝑠𝑖𝑙𝑜𝑛 < 10−𝑘 , 𝑘 – натуральное
число, 𝑘 > 1. Сравнить полученный результат со значением, вычисленным с
помощью стандартных функций. Значение 𝑥 и 𝑘 ввести по запросу.
	*/
	/*
	8.√(1 + 𝑥) = 1 + (1/2)*𝑥 − (1\(2*4))*x^2 + (1*3/(2*4*6))*𝑥^3 − ⋯ , где 𝑥 ∈ (−1; +1)
	*/
	int32_t k;
	double x, eps, res = 1, el = 1;
	while (true)
	{
		std::cout << "Input x: ";
		std::cin >> x;
		if (x >= 1 or x <= -1)
		{
			std::cout << "Wrong number" << '\n';
		}
		else
		{
			break;
		}
	}
	while (true)
	{
		std::cout << "Input k: ";
		std::cin >> k;
		if (k < 1)
		{
			std::cout << "Wrong number"<<'\n';
		}
		else
		{
			break;
		}
	}
	eps = pow(10, -k);
	int_32t i = 0;
	el = x / 2;
	while (abs(el) >= eps)
	{
		res += el;
		++i;
		el = el * x * (0.5 - i) / (i + 1);
	}
	std::cout.precision(k);
	std::cout << "Result: " << res << '\n' << "Standart result: " << sqrt(x+1);
}

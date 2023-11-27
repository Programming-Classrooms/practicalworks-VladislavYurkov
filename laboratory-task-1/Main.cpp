#include <iostream>
int main()
{
	//Вариант 8
	int k;
	double x, eps, res = 1, el = 1;
	while (true)
	{
		std::cout << "Input x: ";
		std::cin >> x;
		if (x >= 1 or x <= -1)
		{
			std::cout << "Wrong number\n";
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
			std::cout << "Wrong number\n";
		}
		else
		{
			break;
		}
	}
	eps = pow(10, -k);
	int i = 0;
	el = x / 2;
	while (abs(el) >= eps)
	{
		res += el;
		i++;
		el = el * x * (0.5 - i) / (i + 1);
	}
	std::cout.precision(k);
	std::cout << "Result: " << res << "\nStandart result: " << sqrt(x+1);
}
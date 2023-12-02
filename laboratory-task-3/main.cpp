#include <iostream>
#include <ctime>


// Вариант 42
/*
В одномерном массиве, состоящем из п вещественных элементов, вычислить:
- самую длинную цепочку подряд стоящих различных элементов;
- сумму элементов массива, расположенных между первым и последним нулём.
Упорядочить по возрастанию отдельно элементы, стоящие на четных местах, и элементы,
стоящие на нечетных местах.
*/


void inputMethod(bool inputMethod, double arr[], int lenght) {
	if (inputMethod)
	{
		double a, b;
		std::cout << "Input interval" << '\n' << "Input a: ";
		std::cin >> a;
		std::cout << "Input b: ";
		std::cin >> b;
		if (a > b) { std::swap(a, b); }
		for (int i = 0; i < lenght; ++i)
		{
			arr[i] = a + rand() * (b - a) / RAND_MAX;
		}
	}
	else
	{
		std::cout << "Input " << lenght << " real numbers" << '\n';
		for (int i = 0; i < lenght; ++i)
		{
			std::cin >> arr[i];
		}
	}
}

void maxChainOfDifferent(double arr[], int lenght) {
	int chainMaxLength = 0;
	for (int i = 0; i < lenght; ++i)
	{
		for (int j = i - 1; j >= 0; --j)
		{
			if (arr[i] == arr[j])
			{
				chainMaxLength = std::max(chainMaxLength, i - j);
				break;
			}
		}
	}
	if (chainMaxLength == 0)
	{
		chainMaxLength = lenght;
	}
	std::cout << "Max lenght of chain = " << chainMaxLength << '\n';
}

void sumBetweenZeros(double arr[],int length)
{
	double sum = 0;
	int startZero = -1, endZero = -1;
	for (int i = 0; i < length; ++i)
	{
		if (!arr[i])
		{
			startZero = i;
			break;
		}
	}
	for (int i = length - 1; i >= 0; --i)
	{
		if (!arr[i])
		{
			endZero = i;
			break;
		}
	}
	if (startZero == -1 or endZero == -1)
	{
		std::cout << "Not enough zeros!!!" << '\n';
	}
	else
	{
		for (int i = startZero + 1; i < endZero; ++i)
		{
			sum += arr[i];
		}
		std::cout << "Sum of numbers between zeros = " << sum << '\n';
	}
}

int main()
{
	int const LENGTHBASE = 10000;
	double arr[LENGTHBASE] = {};
	int n = 100002;
	while (n > 10001)
	{
		std::cout << "Input number of real numbers: ";
		std::cin >> n;
	}


	std::cout << "Choose input method" << "\n1.From keyboard" << "\n2.Random elements\n";
	uint8_t method;
	std::cin >> method;
	inputMethod(--method, arr, n);


	for (int i = 0; i < n; i += 2)
	{
		for (int j = i + 2; j < n; j += 2)
		{
			if (arr[i] > arr[j])
			{
				std::swap(arr[i], arr[j]);
			}
		}
	}


	for (int i = 1; i < n; i += 2)
	{
		for (int j = i + 2; j < n; j += 2)
		{
			if (arr[i] > arr[j])
			{
				std::swap(arr[i], arr[j]);
			}
		}
	}


	std::cout << "array:" << '\n';
	for (int i = 0; i < n; ++i)
	{
		std::cout << arr[i] << '\n';
	}


	return 0;
}

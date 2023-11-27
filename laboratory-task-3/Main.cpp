// Вариант 42
#include <iostream>
#include <ctime>
void input_method_choose(bool input_method, double arr[], int lenght) {
	if (input_method)
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
int max_chain(double arr[], int lenght) {
	int chain_max_length = 0;
	for (int i = 0; i < lenght; ++i)
	{
		for (int j = i - 1; j >= 0; --j)
		{
			if (arr[i] == arr[j])
			{
				chain_max_length = std::max(chain_max_length, i - j);
				break;
			}
		}
	}
	if (chain_max_length == 0)
	{
		chain_max_length = lenght;
	}
	std::cout << "Max lenght of chain = " << chain_max_length << '\n';
}
double zero(double arr[],int length)
{
	double sum = 0;
	int start_0 = -1, end_0 = -1;
	for (int i = 0; i < n; ++i)
	{
		if (!arr[i])
		{
			start_0 = i;
			break;
		}
	}
	for (int i = n - 1; i >= 0; --i)
	{
		if (!arr[i])
		{
			end_0 = i;
			break;
		}
	}
	if (start_0 == -1 or end_0 == -1)
	{
		std::cout << "Not enough zeros!!!" << '\n';
	}
	else
	{
		for (int i = start_0 + 1; i < end_0; ++i)
		{
			sum += arr[i];
		}
		std::cout << "Sum of numbers between zeros = " << sum << '\n';
	}
}
int main()
{
	int const LENGTH_0 = 10000;
	double arr[LENGTH_0] = {};
	int n = 100002;
	while (n > 10001)
	{
		std::cout << "Input number of real numbers: ";
		std::cin >> n;
	}
	std::cout << "Choose input method" << "\n1.From keyboard" << "\n2.Random elements\n";
	uint8_t method;
	std::cin >> method;
	input_method_choose(--method, arr, n);
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
	EXIT_SUCCESS;
}

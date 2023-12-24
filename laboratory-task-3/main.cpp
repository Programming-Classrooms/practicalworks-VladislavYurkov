// Вариант 42
/*
	В одномерном массиве, состоящем из п вещественных элементов, вычислить:
	- самую длинную цепочку подряд стоящих различных элементов;
	- сумму элементов массива, расположенных между первым и последним нулём.
	Упорядочить по возрастанию отдельно элементы, стоящие на четных местах, и элементы,
	стоящие на нечетных местах.
*/


#include <iostream>
#include <ctime>


double randomDouble(double lowerBorder, double upperBorder)
{
	return lowerBorder + rand() * (upperBorder - lowerBorder) / RAND_MAX;
}

void arrayFill(bool inputMethod, double arr[], size_t lenght) 
{
	if (inputMethod) {
		double a, b;
		std::cout << "Input interval" << '\n' << "Input a: ";
		std::cin >> a;
		std::cout << "Input b: ";
		std::cin >> b;
		if (a > b) {
			std::swap(a, b);
		}
		for (size_t i = 0; i < lenght; ++i) {
			arr[i] = randomDouble(a, b);
		}
	}
	else {
		std::cout << "Input " << lenght << " real numbers" << '\n';
		for (size_t i = 0; i < lenght; ++i) {
			std::cin >> arr[i];
		}
	}
}

void maxChainOfDifferent(double arr[], size_t lenght) {
	size_t chainMaxLength = 0;
	for (size_t i = 0; i < lenght; ++i) {
		for (size_t j = i - 1; j >= 0; --j) {
			if (arr[i] == arr[j]) {
				chainMaxLength = std::max(chainMaxLength, i - j);
				break;
			}
		}
	}

	if (chainMaxLength == 0) {
		chainMaxLength = lenght;
	}
	std::cout << "Max lenght of chain = " << chainMaxLength << '\n';
}

void sumBetweenZeros(double arr[],int length)
{
	double sum = 0;
	size_t startZero = -1;
	size_t endZero = -1;
	for (int i = 0; i < length; ++i) {
		if (!arr[i])
		{
			startZero = i;
			break;
		}
	}
	for (int i = length - 1; i >= 0; --i) {
		if (!arr[i]) {
			endZero = i;
			break;
		}
	}

	if (!(startZero != -1 && endZero != -1)) {
		if (startZero == -1 && endZero == -1) {
			std::cout << "There are no zeros\n";
		}
		else {
			std::cout << "There are only one zero\n";
		}
	}
	else {
		for (size_t i = startZero + 1; i < endZero; ++i) {
			sum += arr[i];
		}
		std::cout << "Sum of numbers between zeros = " << sum << '\n';
	}
}

void bubbleSort(double& a, double& b)
{
	if (a > b)
	{
		std::swap(a, b);
	}
}

int main()
{
	size_t const LENGTHBASE = 10000;
	double arr[LENGTHBASE] = {};
	size_t lenght = 100002;
	while (lenght > 10001)
	{
		std::cout << "Input number of real numbers: ";
		std::cin >> lenght;
	}
	try{
		std::cout << "Choose input method" << "\n1.From keyboard" << "\n2.Random elements\n";
		uint8_t method;
		std::cin >> method;
		if (--method > 1){
			throw std::runtime_error("Wrong input method");
		}
		inputMethod(--method, arr, lenght);

		for (size_t i = 0; i < lenght; i += 2)
		{
			for (size_t j = i + 2; j < lenght; j += 2)
			{
				bubbleSort(arr[i], arr[j]);
			}
		}

		for (size_t i = 1; i < lenght; i += 2)
		{
			for (size_t j = i + 2; j < lenght; j += 2)
			{
				bubbleSort(arr[i], arr[j]);
			}
		}

		std::cout << "array:" << '\n';
		for (int i = 0; i < lenght; ++i)
		{
			std::cout << arr[i] << '\n';
		}

	}
	


	return 0;
}

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
#include <cstdint>


double randomDouble(double lowerBorder, double upperBorder)
{
	return lowerBorder + rand() * (upperBorder - lowerBorder) / RAND_MAX;
}

void arrayFill(bool inputMethod, double arr[], size_t length) 
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
		for (size_t i = 0; i < length; ++i) {
			arr[i] = randomDouble(a, b);
		}
	}
	else {
		std::cout << "Input " << length << " real numbers" << '\n';
		for (size_t i = 0; i < length; ++i) {
			std::cin >> arr[i];
		}
	}
}

void maxChainOfDifferentOut(double arr[], size_t length) {
	size_t chainMaxLength = 0;
	for (size_t i = 0; i < length; ++i) {
		for (size_t j = 0; j < i; ++j) {
			if (arr[i] == arr[j]) {
				chainMaxLength = std::max(chainMaxLength, i - j);
				break;
			}
		}
	}

	if (chainMaxLength == 0) {
		chainMaxLength = length;
	}
	std::cout << "Max length of chain = " << chainMaxLength << '\n';
}

void sumBetweenZerosOut(double arr[],int length)
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
	size_t length = 100002;
	while (length > 10001){
		std::cout << "Input number of real numbers: ";
		std::cin >> length;
	}
	try {
		std::cout << "Choose input method" << "\n1.From keyboard" << "\n2.Random elements\n";
		size_t method;
		std::cin >> method;
		if (method != 1 && method != 2) {
			throw std::runtime_error("Wrong input method");
		}
		arrayFill(--method, arr, length);

		maxChainOfDifferentOut(arr, length);

		sumBetweenZerosOut(arr, length);

		for (size_t i = 0; i < length; i += 2) {
			for (size_t j = i + 2; j < length; j += 2) {
				bubbleSort(arr[i], arr[j]);
			}
		}

		for (size_t i = 1; i < length; i += 2) {
			for (size_t j = i + 2; j < length; j += 2) {
				bubbleSort(arr[i], arr[j]);
			}
		}

		std::cout << "array:" << '\n';
		for (int i = 0; i < length; ++i){
			std::cout << arr[i] << '\n';
		}

	}
	catch (std::runtime_error e) {
		std::cout << e.what() << '\n';
	}
	return 0;
}

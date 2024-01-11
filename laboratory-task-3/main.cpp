// Вариант 42
/*
	В одномерном массиве, состоящем из п вещественных элементов, вычислить:
	- самую длинную цепочку подряд стоящих различных элементов;
	- сумму элементов массива, расположенных между первым и последним нулём.
	Упорядочить по возрастанию отдельно элементы, стоящие на четных местах, и элементы,
	стоящие на нечетных местах.
*/


#include <iostream>
#include <random>
#include <ctime>
#include <cstdint>
#include <string>


bool StaticOrDynamic()
{
	std::string chosedNumber;
	std::cout << "Input type of array:\n";
	std::cout << "1.Static\n";
	std::cout << "2.Dynamic\n";
	std::getline(std::cin, chosedNumber);
	if (chosedNumber != "1" && chosedNumber != "2") {
		throw std::runtime_error("Wrong type");
	}
	return chosedNumber == "1";
}

bool isNumber(std::string line)
{
	size_t lineLength = line.length();
	for (size_t i = 0; i < lineLength; ++i) {
		if (!(line[i] >= '0' && line[i] <= '9')) {
			return false;
		}
	}
	return true;
}

size_t inputArrayLength()
{
	std::string length;
	std::cout << "Input length of array: ";
	std::getline(std::cin, length);
	if (length == "")
	{
		throw std::runtime_error("Empty input");
	}
	if (!isNumber(length)) {
		throw std::runtime_error("Not a number");
	}
	if (stoull(length) > 1000000) {
		throw std::runtime_error("Too big");
	}
	return stoull(length);
}

bool manualOrRandomFill()
{
	std::string inputMethod; 
	std::cout << "Choose input method\n";
	std::cout << "1.From keyboard\n";
	std::cout << "2.Random numbers\n";
	std::getline(std::cin, inputMethod);
	if (inputMethod != "1" && inputMethod != "2")
	{
		throw std::runtime_error("Wrong input method");
	}
	return inputMethod == "1";
}

void setBorders(double& leftBorder, double& rightBorder)
{
	std::cout << "Please, enter real borders\n";
	std::cout << "Left border = ";
	std::cin >> leftBorder;
	std::cout << "Right border = ";
	std::cin >> rightBorder;
	if (leftBorder > rightBorder) {
		throw std::runtime_error("Left border bigger than right one");
	}
}

double randDouble(double leftBorder, double rightBorder)
{
	return rand() * (rightBorder - leftBorder) / RAND_MAX + leftBorder;
}

void staticArrayFill(double staticArray[], const size_t LENGTH)
{
	bool manualFill = manualOrRandomFill();
	if(manualFill) {
		std::cout << "Please, enter " << LENGTH << " real numbers:\n";
		for(size_t i = 0; i < LENGTH; ++i) {
			std::cin >> staticArray[i];
		}
		
	}

	else {
		double leftBorder = 0.0;
		double rightBorder = 0.0; 
		setBorders(leftBorder, rightBorder);
		for(size_t i = 0; i < LENGTH; ++i) {
			staticArray[i] = randDouble(leftBorder, rightBorder);
		}
	}

	std::cout << "\nArray filled. Your array:\n";
	for(size_t i = 0; i < LENGTH; ++i) {
		std::cout << staticArray[i] << ' ';
	}
	std::cout << '\n';
}

int main()
{	
	try {

		bool isStatic = StaticOrDynamic();

		const size_t LENGTH = inputArrayLength();

		if(isStatic) {
			const size_t BASE_LENGTH = 1000000;
			double staticArray[BASE_LENGTH] = {};

			staticArrayFill(staticArray, LENGTH);
		}
		else {
			double* dynamicArray = new double[LENGTH];
		}
	}
	catch(std::runtime_error e) {
		std::cerr << e.what() << '\n';
	}
}

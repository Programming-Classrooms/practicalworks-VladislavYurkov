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

bool isNaturalNumber(std::string line)
{
	size_t lineLength = line.length();
	for (size_t i = 0; i < lineLength; ++i) {
		if (!(line[i] >= '0' && line[i] <= '9')) {
			return false;
		}
	}
	return true;
}

bool isRealNumber(std::string line)
{
	bool isPoint = false;
	size_t lineLength = line.length();
	for (size_t i = 0; i < lineLength; ++i) {
		if (!i) {
			if (line[0] == '-') {
				i++;
				continue;
			}
		}
		if(line[i] == '.') {
			if(!i) {
				return false;
			}
			if(isPoint) {
				return false;
			}
			isPoint = true;
			++i;
			continue;
		}
		if(!(line[i] >= '0' && line[i] <= '9')) {
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
	if (!isNaturalNumber(length)) {
		throw std::runtime_error("Not a number");
	}
	if (!stoull(length)) {
		throw std::runtime_error("Zero length is not allowed");
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
	std::string leftBorderInput;
	std::string rightBorderInput;
	std::cout << "Please, enter real borders\n";
	std::cout << "Left border = ";
	std::cin >> leftBorderInput;
	std::cout << "Right border = ";
	std::cin >> rightBorderInput;
	if(isRealNumber(leftBorderInput) && isRealNumber(rightBorderInput)) {
		leftBorder = stod(leftBorderInput);
		rightBorder = stod(rightBorderInput);
	}
	else {
		throw std::runtime_error("Borders is not real numbers");
	}
	if(leftBorder > rightBorder) {
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

size_t maxChainOfDiffNumsLengthStatic(double staticArray[], const size_t LENGTH)
{
	size_t currentMaxChain = 0;
	bool founded = false;
	for (size_t i = 0; i < LENGTH - 1; ++i) {
		for (size_t j = i + 1; j < LENGTH; ++j) {
			for (size_t k = j; k != i; --k) {
				if(staticArray[k - 1] == staticArray[j]) {
					currentMaxChain = std::max(currentMaxChain, j - i);
					founded = true;
					break;
				}
			}
			if (founded) {
				break;
			}
		}
		if(!founded) {
			currentMaxChain = std::max(currentMaxChain, LENGTH - i);
		}
		founded = false;
	}
	return currentMaxChain;
}

double sumBetweenFirstAndLastZerosStatic(double staticArray[], const size_t LENGTH) {
	size_t begInd = -1;
	size_t endInd = -1;
	for (size_t i = 0; i < LENGTH; ++i) {
		if (!staticArray[i]) {
			begInd = i;
			break;
		}
	}

	if (begInd == -1) {
		throw std::runtime_error("There is no zeros in array");
	}

	for (size_t i = LENGTH - 1; i != 0; --i) {
		if(!staticArray[i]) {
			endInd = i;
			break;
		}
	}

	if (endInd == begInd) {
		throw std::runtime_error("There is only one zero in array");
	}

	double sum = 0.0;
	for (size_t i = begInd + 1; i < endInd; ++i) {
		sum += staticArray[i];
	}
	return sum;
}

int main()
{	
	srand(time(NULL));
	try {

		bool isStatic = StaticOrDynamic();

		const size_t LENGTH = inputArrayLength();

		if(isStatic) {
			const size_t BASE_LENGTH = 1000000;
			double staticArray[BASE_LENGTH] = {};

			staticArrayFill(staticArray, LENGTH);

			std::cout << maxChainOfDiffNumsLengthStatic(staticArray, LENGTH) << '\n';
			try {
				std::cout << sumBetweenFirstAndLastZerosStatic(staticArray, LENGTH) << '\n';
			}
			catch (std::runtime_error e) {
				std::cerr << e.what() << '\n';
			}
		}
		else {
			double* dynamicArray = new double[LENGTH];
		}
	}
	catch(std::runtime_error e) {
		std::cerr << e.what() << '\n';
	}
	return 0;
}

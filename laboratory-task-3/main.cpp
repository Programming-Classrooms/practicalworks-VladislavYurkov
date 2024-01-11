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
	if (!isNumber(length)) {
		throw std::runtime_error("Not a number");
	}
	if (stoull(length) > 1000000) {
		throw std::runtime_error("Too big");
	}
	return stoull(length);
}

int main()
{	
	try {

		bool isStatic = StaticOrDynamic();

		const size_t LENGTH = inputArrayLength();

		if(isStatic) {
			const size_t BASE_LENGTH = 1000000;
			double staticArray[BASE_LENGTH] = {};

		}
		else {
			double* dynamicArray = new double[LENGTH];
		}
	}
	catch(std::runtime_error e) {
		std::cerr << e.what() << '\n';
	}
}

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


bool isStatic()
{
	std::string chosedNumber;
	std::cout << "Input type of array:\n";
	std::cout << "1.Static\n";
	std::cout << "2.Dynamic\n";
	std::cin >> chosedNumber;
	if (!(chosedNumber != "1" && chosedNumber != "2")) {
		throw std::runtime_error("Wrong type");
	}
	return chosedNumber == "1";
}

int main()
{
	bool isStatic = isStatic();
	
}

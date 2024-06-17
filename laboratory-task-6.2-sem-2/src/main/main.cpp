#include "src/Functions/Functions.hpp"


int main()
{
	try
	{
		std::vector<int> numbers;
		numbers = readInt();
		printVector(numbers);
		std::cout << "Сумма чисел в векторе = " << numbersSum(numbers) << '\n';
		
		std::cout << "Общее количество чисел = " << numbersCount(numbers) << '\n';
		
		std::cout << "Введите число: ";
		int target = inputInt();
		
		std::cout << "Количество чисел, равных \'" << target << "\' = " << eqNumbersCount(numbers, target) << '\n';
		
		std::cout << "Количество чисел, больших \'" << target << "\' = " << suiteNumbersCount(numbers, greaterThen, target) << '\n';
		
		replaceNulls(numbers);
		std::cout << "Нули были заменены целой частью среднего арифметического\n";
		printVector(numbers);
		
		increaceByRange(numbers);
		std::cout << "Ко всем элементам вектора прибавили сумму чисел из заданного интервалла\n";
		printVector(numbers);
		
		replaceEven(numbers);
		std::cout << "Чётные числа были заменены на разницу максимального и минимального элементов\n";
		printVector(numbers);

		deleteRepeat(numbers);
		std::cout << "Удалены все повторы\n";
		printVector(numbers);
	}
	catch(const std::logic_error& e)
	{
		std::cerr << e.what() << '\n';
	}
	catch(const std::out_of_range& e)
	{
		std::cerr << e.what() << '\n';
	}
	return 0;
}

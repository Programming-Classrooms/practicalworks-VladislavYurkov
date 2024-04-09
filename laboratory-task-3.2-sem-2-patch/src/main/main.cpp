#include "src/Matrix/Matrix.hpp"
int main()
{
	try
	{
		//Конструкиоры
		Matrix defaultMtrx;
		Matrix paramMtrx(3,4);
		Matrix mtrxCpy(paramMtrx);
		Matrix newOwner(std::move(defaultMtrx));

		//Оператор доступа к элементу
		paramMtrx[1][3] = 8;

		//Операторы присваивания
		paramMtrx = newOwner;
		newOwner = std::move(mtrxCpy);

		//Составные арифметические операторы
		Matrix first(2,2);
		Matrix second(2,2);

		for (size_t i = 0; i < 2; ++i)
		{
			for (size_t j = 0; j < 2; ++j)
			{
				first[i][j] = 1;
				second[i][j] = 2;
			}
			
		}

		first *= 4;
		first /= 2;
		first += second;
		first -= second;
		first *= second;

		//Арифметические операторы
		Matrix third(2,2);

		for (size_t i = 0; i < 2; ++i)
		{
			for (size_t j = 0; j < 2; ++j)
			{
				third[i][j] = i*10 + j + 11; 
			}
			
		}


		third = 2 * first * 2;
		third = second / 2;
		third = first + second;
		third = first - second;
		third = first * second;

		//Операторы сравнения
		first == second;
		first != third;

		//Операторы работы с потоком

		Matrix inputMtrx;

		std::cin >> inputMtrx;
		std::cout << inputMtrx;

	}
	catch(const std::logic_error& e)
	{
		std::cerr << e.what() << '\n';
	}
	return 0;
}

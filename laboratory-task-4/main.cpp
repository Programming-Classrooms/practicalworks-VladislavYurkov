//Вариант 15
/*
		Для вещественной квадратной матрицы путем перестановки строк и столбцов
	добиться того, чтобы ее максимальный элемент находился в левом верхнем углу,
	следую¬щий по величине — в позиции (2,2), следующий по величине — в позиции
	(3,3) и т. д., заполняя таким образом всю главную диагональ.
		Найти номер первой из строк полученной матрицы, не содержащих ни одного
	положительного элемента.
*/


#include <iostream>
#include <random>
#include <time.h>
#include <iomanip>


void swap(double& a, double& b)
{
	double help = a;
	a = b;
	b = help;
}

bool notPositiveRow(double**& sqrMtrx, size_t sqrMtrxSide, size_t row)
{
	for (size_t i = 0; i < sqrMtrxSide; ++i) {
		if (sqrMtrx[row][i] > 0) {
			return false;
		}
	}
	return true;
}

size_t firstNotPositiveRow(double**& sqrMtrx, size_t sqrMtrxSide)
{
	for (size_t i = 0; i < sqrMtrxSide;++i) {
		if (notPositiveRow(sqrMtrx, sqrMtrxSide, i)) {
			return i + 1;
		}
	}
	return -1;
}

void firstNotPosOut(double**& sqrMtrx, size_t sqrMtrxSide)
{
	if (firstNotPositiveRow(sqrMtrx, sqrMtrxSide) == static_cast<size_t>(-1)) {
		std::cout << "This matrix doesn\'t have rows without positive numbers";
	}
	else {
		std::cout << "First row that have no positive numbers has number " << firstNotPositiveRow(sqrMtrx, sqrMtrxSide);
	}
}

void rowSwap(double**& sqrMtrx, size_t sqrMtrxSide,size_t a, size_t b)
{
	for (size_t i = 0; i < sqrMtrxSide; ++i) {
		swap(sqrMtrx[a][i], sqrMtrx[b][i]);
	}
}

void columnSwap(double**& sqrMtrx, size_t sqrMtrxSide,size_t a, size_t b)
{
	for (size_t i = 0; i < sqrMtrxSide; ++i) {
		swap(sqrMtrx[i][a], sqrMtrx[i][b]);
	}
}

void maxElInCorner(double**& sqrMtrx, size_t sqrMtrxSide, size_t iter)
{
	size_t max_i = iter, max_j = iter;
	for (size_t i = iter; i < sqrMtrxSide; ++i) {
		for (size_t j = iter; j < sqrMtrxSide; ++j) {
			if (sqrMtrx[i][j] > sqrMtrx[max_i][max_j]) {
				max_i = i;
				max_j = j;
			}
		}
	}
	rowSwap(sqrMtrx, sqrMtrxSide, iter, max_i);
	columnSwap(sqrMtrx, sqrMtrxSide, iter, max_j);
}

void maxSort(double**& sqrMtrx, size_t sqrMtrxSide)
{
	for (size_t i = 0; i < sqrMtrxSide; ++i) {
		maxElInCorner(sqrMtrx, sqrMtrxSide, i);
	}
}

void memory(double**& sqrMtrx, size_t sqrMtrxSide)
{
	sqrMtrx = new double* [sqrMtrxSide];
	for (size_t i = 0; i < sqrMtrxSide; ++i) {
		sqrMtrx[i] = new double[sqrMtrxSide];
	}
}

void mtrxOut(double**& sqrMtrx, size_t sqrMtrxSide)
{
	for (size_t i = 0; i < sqrMtrxSide; ++i) {
		for (size_t j = 0; j < sqrMtrxSide; ++j) {
			std::cout << std::setw(12) << sqrMtrx[i][j];
		}
		std::cout << '\n';
	}
	std::cout << "\n\n\n";
}

void mtrxFillRandom(double**& sqrMtrx, size_t sqrMtrxSide)
{
	double a, b;
	srand(time(NULL));
	std::cout << "The matrix will be filled with random real numbers between a and b\n" << "Input a: ";
	std::cin >> a;
	std::cout << "Input b: ";
	std::cin >> b;
	if (a > b) {
		swap(a, b);
	}
	for (size_t i = 0; i < sqrMtrxSide; ++i) {
		for (size_t j = 0; j < sqrMtrxSide; ++j) {
			sqrMtrx[i][j] = a + rand() * (b - a) / RAND_MAX;
		}
	}
	mtrxOut(sqrMtrx, sqrMtrxSide);
}

void mtrxFillKeyboard(double**& sqrMtrx, size_t sqrMtrxSide)
{
	std::cout << "Please, input matrix from keyboard\n";
	for (size_t i = 0; i < sqrMtrxSide; ++i) {
		for (size_t j = 0; j < sqrMtrxSide; ++j) {
			std::cin >> sqrMtrx[i][j];
		}
	}
}

void mtrxFill(double**& sqrMtrx, size_t sqrMtrxSide)
{
	int16_t inputMethod;
	std::cout << "Choose input method\n" << "1.Random\n" << "2.From keyboard\n";
	std::cin >> inputMethod;
	switch (inputMethod) {
	case 1:
		mtrxFillRandom(sqrMtrx, sqrMtrxSide);
		break;
	case 2:
		mtrxFillKeyboard(sqrMtrx, sqrMtrxSide);
		break;
	default:
		throw;
		break;
	}
}

void mtrxDel(double**& sqrMtrx, size_t sqrMtrxSide)
{
	for (size_t i = 0; i < sqrMtrxSide; ++i) {
		delete sqrMtrx[i];
	}
	delete sqrMtrx;
}

void wrongInput(double**& sqrMtrx, size_t sqrMtrxSide)
{
	mtrxDel(sqrMtrx,sqrMtrxSide);
	std::cout << "Wrong input";
	exit(-1);
}

int main()
{
	double** sqrMtrx = nullptr;
	size_t sqrMtrxSide = 0;
	std::cout << "Input square matrix side: ";
	try
	{
		int64_t side_test;
		std::cin >> side_test;
		if (side_test < 0)
		{
			throw;
		}
		sqrMtrxSide = side_test;

		memory(sqrMtrx, sqrMtrxSide);
		mtrxFill(sqrMtrx, sqrMtrxSide);

		maxSort(sqrMtrx, sqrMtrxSide);
		std::cout << "Matrix sorted" << '\n';
		mtrxOut(sqrMtrx, sqrMtrxSide);

		firstNotPosOut(sqrMtrx, sqrMtrxSide);

		mtrxDel(sqrMtrx, sqrMtrxSide);
	}
	catch (...)
	{
		wrongInput(sqrMtrx,sqrMtrxSide);
	}
	return 0;
}

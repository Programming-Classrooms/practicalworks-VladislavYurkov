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
#include <exception>


void swapArrays(double* &first, double* &second)
{
	double* help = first;
	first = second;
	second = help;
}

bool isRowWithoutPosNums(double** sqrMtrx, size_t sqrMtrxSide, size_t row)
{
	for (size_t i = 0; i < sqrMtrxSide; ++i) {
		if (sqrMtrx[row][i] > 0) {
			return false;
		}
	}
	return true;
}

size_t numberOfFirstRowWithoutPosNums(double** sqrMtrx, size_t sqrMtrxSide)
{
	for (size_t i = 0; i < sqrMtrxSide;++i) {
		if (isRowWithoutPosNums(sqrMtrx, sqrMtrxSide, i)) {
			return i + 1;
		}
	}
	return 0;
}

void firstNotPosRowPrint(double** sqrMtrx, size_t sqrMtrxSide)
{
	if (!numberOfFirstRowWithoutPosNums(sqrMtrx, sqrMtrxSide)) {
		std::cout << "This matrix doesn\'t have rows without positive numbers";
	}
	else {
		std::cout << "First row that have no positive numbers has number " << numberOfFirstRowWithoutPosNums(sqrMtrx, sqrMtrxSide);
	}
}

void rowSwap(double** sqrMtrx, size_t firstRow, size_t secondRow)
{
	swapArrays(sqrMtrx[firstRow], sqrMtrx[secondRow]);
}

//Делаю циклом потому что поменять колонны местами без обращения к конкретному элементу не возможно
void columnSwap(double** sqrMtrx, size_t sqrMtrxSide,  size_t firstColumn, size_t secondColumn)
{
		for (size_t i = 0; i < sqrMtrxSide; ++i) {
			std::swap(sqrMtrx[i][firstColumn], sqrMtrx[i][secondColumn]);
		}
}

void moveMaxElemInCorner(double** sqrMtrx, size_t sqrMtrxSide, size_t iter)
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
	rowSwap(sqrMtrx, iter, max_i);
	columnSwap(sqrMtrx, sqrMtrxSide, iter, max_j);
}

void moveMaxElemsInDiagonal(double** sqrMtrx, size_t sqrMtrxSide)
{
	for (size_t i = 0; i < sqrMtrxSide; ++i) {
		moveMaxElemInCorner(sqrMtrx, sqrMtrxSide, i);
	}
}

void memAllocSqrMtrx(double**& sqrMtrx, size_t sqrMtrxSide)
{
	sqrMtrx = new double* [sqrMtrxSide];
	for (size_t i = 0; i < sqrMtrxSide; ++i) {
		sqrMtrx[i] = new double[sqrMtrxSide];
	}
}

void printMtrx(double** sqrMtrx, size_t sqrMtrxSide)
{
	size_t width;
	size_t numberOfBlankLines;
	std::cout << "Please, enter the desired width of the array elements\n";
	std::cin >> width;
	std::cout << "Please, enter number of blank lines after matrix\n";
	std::cin >> numberOfBlankLines;
	for (size_t i = 0; i < sqrMtrxSide; ++i) {
		for (size_t j = 0; j < sqrMtrxSide; ++j) {
			std::cout << std::setw(width) << sqrMtrx[i][j];
		}
		std::cout << '\n';
	}
	for (size_t i = 0; i <= numberOfBlankLines; ++i) {
		std::cout << '\n';
	}
}

double randDouble(double leftBorder, double rightBorder) {
	return leftBorder + rand() * (rightBorder - leftBorder) / RAND_MAX;
}

void setBorders(double& leftBorder, double& rightBorder) {
	std::cout << "Input left border\n";
	std::cin >> leftBorder;
	std::cout << "Input right border\n";
	std::cin >> rightBorder;

	if (leftBorder > rightBorder) {
		throw std::runtime_error("Wrong borders");
	}
}

//Заполнение массива случайными числами неразрывно связано с его выводом, не могу убрать вывод массива
void mtrxFillRandomAndPrint(double** sqrMtrx, size_t sqrMtrxSide)
{
	srand(time(NULL));

	double leftBorder = 0;
	double rightBorder = 0;
	setBorders(leftBorder, rightBorder);

	for (size_t i = 0; i < sqrMtrxSide; ++i) {
		for (size_t j = 0; j < sqrMtrxSide; ++j) {
			sqrMtrx[i][j] = randDouble(leftBorder, rightBorder);
		}
	}

	printMtrx(sqrMtrx, sqrMtrxSide);
}

void mtrxFillKeyboard(double** sqrMtrx, size_t sqrMtrxSide)
{
	std::cout << "Please, input matrix from keyboard\n";
	for (size_t i = 0; i < sqrMtrxSide; ++i) {
		for (size_t j = 0; j < sqrMtrxSide; ++j) {
			std::cin >> sqrMtrx[i][j];
		}
	}
}

void fillSqrMtrx(double** sqrMtrx, size_t sqrMtrxSide)
{
	int16_t inputMethod;
	std::cout << "Choose input method\n" << "1.Random\n" << "2.From keyboard\n";
	std::cin >> inputMethod;
	switch (inputMethod) {
	case 1:
		mtrxFillRandomAndPrint(sqrMtrx, sqrMtrxSide);
		break;
	case 2:
		mtrxFillKeyboard(sqrMtrx, sqrMtrxSide);
		break;
	default:
		throw std::runtime_error("");
		break;
	}
}

void memCleanSqrMtrx(double**& sqrMtrx, size_t sqrMtrxSide)
{
	for (size_t i = 0; i < sqrMtrxSide; ++i) {
		delete sqrMtrx[i];
	}
	delete sqrMtrx;
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
			throw std::runtime_error("wrong side");
		}
		sqrMtrxSide = side_test;

		memAllocSqrMtrx(sqrMtrx, sqrMtrxSide);
		mtrxFill(sqrMtrx, sqrMtrxSide);

		moveMaxElemsInDiagonal(sqrMtrx, sqrMtrxSide);
		std::cout << "Matrix sorted" << '\n';
		printMtrx(sqrMtrx, sqrMtrxSide);

		firstNotPosRowPrint(sqrMtrx, sqrMtrxSide);

		memCleanSqrMtrx(sqrMtrx, sqrMtrxSide);
	}
	catch (std::runtime_error e)
	{
		std::cerr << e.what() << '\n';
		memCleanSqrMtrx(sqrMtrx, sqrMtrxSide);
	}
	return 0;
}

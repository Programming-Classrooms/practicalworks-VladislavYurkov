#include <iostream>
#include <random>
#include <time.h>
#include <iomanip>
using std::cin;
using std::cout;


//Вариант 15
/*
Для вещественной квадратной матрицы путем перестановки строк и столбцов
добиться того, чтобы ее максимальный элемент находился в левом верхнем углу,
следую¬щий по величине — в позиции (2,2), следующий по величине — в позиции
(3,3) и т. д., заполняя таким образом всю главную диагональ.
Найти номер первой из строк полученной матрицы, не содержащих ни одного
положительного элемента.
*/


void swap(double& a, double& b)
{
	double help = a;
	a = b;
	b = help;
}

bool notPositiveRow(double**& mtrx, size_t side, size_t row)
{
	for (size_t i = 0; i < side; ++i)
	{
		if (mtrx[row][i] > 0)
		{
			return false;
		}
	}
	return true;
}

size_t firstNotPositiveRow(double**& mtrx, size_t side)
{
	for (size_t i = 0; i < side;++i)
	{
		if (notPositiveRow(mtrx, side, i))
		{
			return i + 1;
		}
	}
	return -1;
}

void firstNotPosOut(double**& mtrx, size_t side)
{
	if (firstNotPositiveRow(mtrx, side) == -1)
	{
		cout << "This matrix doesn\'t have rows without positive numbers";
	}
	else
	{
		cout << "First row that have no positive numbers has number " << firstNotPositiveRow(mtrx, side);
	}
}

void rowSwap(double**& mtrx, size_t side,size_t a, size_t b)
{
	for (size_t i = 0; i < side; ++i)
	{
		swap(mtrx[a][i], mtrx[b][i]);
	}
}

void columnSwap(double**& mtrx, size_t side,size_t a, size_t b)
{
	for (size_t i = 0; i < side; ++i)
	{
		swap(mtrx[i][a], mtrx[i][b]);
	}
}

void maxElInCorner(double**& mtrx, size_t side, size_t iter)
{
	size_t max_i = iter, max_j = iter;
	for (size_t i = iter; i < side; ++i)
	{
		for (size_t j = iter; j < side; ++j)
		{
			if (mtrx[i][j] > mtrx[max_i][max_j])
			{
				max_i = i;
				max_j = j;
			}
		}
	}
	rowSwap(mtrx, side, iter, max_i);
	columnSwap(mtrx, side, iter, max_j);
}

void maxSort(double**& mtrx, size_t side)
{
	for (size_t i = 0; i < side; ++i)
	{
		maxElInCorner(mtrx, side, i);
	}
}

void memory(double**& mtrx, size_t side)
{
	mtrx = new double* [side];
	for (size_t i = 0; i < side; ++i)
	{
		mtrx[i] = new double[side];
	}
}

void mtrxOut(double**& mtrx, size_t side)
{
	for (size_t i = 0; i < side; ++i)
	{
		for (size_t j = 0; j < side; ++j)
		{
			cout << std::setw(12) << mtrx[i][j];
		}
		cout << '\n';
	}
}

void mtrxFillRandom(double**& mtrx, size_t side)
{
	double a, b;
	srand(time(NULL));
	cout << "The matrix will be filled with random real numbers between a and b\n" << "Input a: ";
	cin >> a;
	cout << "Input b: ";
	cin >> b;
	if (a > b)
	{
		swap(a, b);
	}
	for (size_t i = 0; i < side; ++i)
	{
		for (size_t j = 0; j < side; ++j)
		{
			mtrx[i][j] = a + rand() * (b - a) / RAND_MAX;
		}
	}
	mtrxOut(mtrx, side);
}

void mtrxFillKeyboard(double**& mtrx, size_t side)
{
	cout << "Please, input matrix from keyboard\n";
	for (size_t i = 0; i < side; ++i)
	{
		for (size_t j = 0; j < side; ++j)
		{
			cin >> mtrx[i][j];
		}
	}
}

void mtrxFill(double**& mtrx, size_t side)
{
	int16_t inputMethod;
	cout << "Choose input method\n" << "1.Random\n" << "2.From keyboard\n";
	cin >> inputMethod;
	switch (inputMethod)
	{
	case 1:
		mtrxFillRandom(mtrx, side);
		break;
	case 2:
		mtrxFillKeyboard(mtrx, side);
		break;
	default:
		throw;
		break;
	}
}

void mtrxDel(double**& mtrx, size_t side)
{
	for (size_t i = 0; i < side; ++i)
	{
		delete mtrx[i];
	}
	delete mtrx;
}

void wrongInput(double**& mtrx, size_t side)
{
	mtrxDel(mtrx,side);
	cout << "Wrong input";
	exit(-1);
}

std::terminate_handler criticalError(double**& mtrx, size_t side)
{
	mtrxDel(mtrx,side);
	cout << "Critical error!";
	exit(-100);
}

int main()
{
	double** mtrx;
	size_t side;
	std::set_terminate(criticalError(mtrx,side));
	cout << "Input square matrix side: ";
	try
	{
		int64_t side_test;
		cin >> side_test;
		if (side_test < 0)
		{
			throw;
		}
		side = side_test;

		memory(mtrx, side);
		mtrxFill(mtrx, side);

		maxSort(mtrx, side);
		cout << "Matrix sorted" << '\n';
		mtrxOut(mtrx, side);

		firstNotPosOut(mtrx, side);

		mtrxDel(mtrx, side);
	}
	catch (...)
	{
		wrongInput(mtrx,side);
	}
	return 0;
}
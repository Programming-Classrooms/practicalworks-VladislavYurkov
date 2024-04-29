#include "src/Functions/Functions.hpp"


int main()
{
	try
	{	
		std::vector<std::vector<int>> mtrx;
		initMtrx(mtrx);
		printMtrx(mtrx);
		std::cout << '\n';
		anihilateMax(mtrx);
		printMtrx(mtrx);
		std::cout << '\n';
		sortRows(mtrx);
		printMtrx(mtrx);

	}
	catch(const std::invalid_argument& e)
	{
		std::cerr << e.what() << '\n';
	}
	catch(const std::logic_error& e)
	{
		std::cerr << e.what() << '\n';
	}
	return 0;
}

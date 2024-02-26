#include "src/MyString/MyString.hpp"

int main()
{
	try {

		MyString line1 = "Hello, ";
		MyString line2 = "world!\n";

		MyString line = line1 + line2;

		std::cout << line;

	}
	catch (std::exception e)
	{
		std::cerr << e.what();
	}
	return 0;
}

#include "src/String/String.hpp"
int main()
{
	String obj("String");
    String newObj(String obj);
	std::cout << obj.getSize();
	return 0;
}

#include "src/String/String.hpp"
int main()
{
	try{
		MyString obj("String");
		MyString newObj(std::move(obj));
		std::cin >> obj;
		std::cout << obj;
	}
	catch(std::logic_error e) {
		std::cerr << e.what() << '\n';
	}
	catch(std::bad_alloc e) {
		std::cerr << e.what() << '\n';
	}
	catch(std::exception e) {
		std::cerr << e.what() << '\n';
	}
	return 0;
}

#include "src/TDeque/TDeque.hpp"

void print(char * elem)
{
	std::cout << elem << '\n';
}

int main()
{
	TDeque<char*> dek;
	dek.InsFront("Hello");
	dek.InsFront("Hell");
	dek.InsFront("Hel");
	dek.InsFront("He");
	dek.InsFront("H");
	dek.Browse(print);
	return 0;
}

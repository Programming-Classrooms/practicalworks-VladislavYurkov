#include "src/List/List.hpp"


int main()
{
	Student firstGraduate("Student", 1, 7121, 5, 5, 7);
	Student secondGraduate("Student2", 2, 7111, 7, 7, 9);
	List studentsList;
	studentsList.insertFirst(firstGraduate);
	studentsList.insertLast(secondGraduate);
	std::cout << studentsList;
	return 0;
}

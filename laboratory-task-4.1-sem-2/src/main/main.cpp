#include "src/Student/Student.hpp"
#include "src/Professor/Professor.hpp"

int main()
{
	uint32_t menuOption = 0;
	Person** personsList = new Person*[10000];
	size_t numerOfPersons = 0;
	Student* newStudent = new Student;
	Professor* newProfessor = new Professor;
	while (menuOption != 5)
	{
		std::cout << "Choose option:\n";
		std::cout << "1.Input student\n";
		std::cout << "2.Input professor\n";
		std::cout << "3.Print students' list\n";
		std::cout << "4.Print professors' list\n";
		std::cout << "5.Finish work\n";
		std::cin >> menuOption;
		switch (menuOption)
		{
		case 1:
			newStudent->input();
			personsList[numerOfPersons++] = newStudent;
			break;
		case 2:
			newProfessor->input();
			personsList[numerOfPersons++] = newProfessor;
			break;
		case 3:
			std::cout << "\nList of students:\n\n";
			for (size_t i = 0; i < numerOfPersons; ++i)
			{
				if (dynamic_cast<Student*>(personsList[i]))
				{
					personsList[i]->print();
					std::cout << '\n';
				}
				
			}
			std::cout << '\n';
			break;
		case 4:
			std::cout << "\nList of professors:\n\n";
			for (size_t i = 0; i < numerOfPersons; ++i)
			{
				if (dynamic_cast<Professor*>(personsList[i]))
				{
					personsList[i]->print();
					std::cout << '\n';
				}
				
			}
			std::cout << '\n';
			break;
		case 5:
			std::cout << "Finished!\n";
			break;
		default:
			std::cout << "Wrong option, try again\n";
			break;
		}

	}
	
	return 0;
}

#include "src/Student/Student.hpp"


int main()
{
	try
	{
		std::ifstream studentsFile("src/resources/Students.txt");
		checkFile(studentsFile);

		std::vector<Student> studentsArr;
		readStudents(studentsArr, studentsFile);
		
		studentsFile.close();
		
		std::ofstream fioFile("src/resources/Fio.txt");
		
		sortByAlphabet(studentsArr);
		printStudentsInFile(studentsArr, fioFile);
		
		fioFile.close();

		std::ofstream groupsFile("src/resources/Groups.txt");

		sortByGroups(studentsArr);
		printStudentsInFile(studentsArr, groupsFile);
		
		groupsFile.close();
	}
	catch(const std::logic_error& e)
	{
		std::cerr << e.what() << '\n';
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return 0;
}

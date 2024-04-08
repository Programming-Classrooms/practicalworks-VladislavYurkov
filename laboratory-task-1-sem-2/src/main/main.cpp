#include "src/Employee/Employee.hpp"
#include "src/Numbers/Numbers.hpp"
#include "src/Surnames/Surnames.hpp"

int main()
{
	try{
		std::ifstream fileNum("src/main/Numbers.txt");
		checkFile(fileNum);
		int32_t* allNumbers = new int32_t[1000];
		size_t allNumbersSize = 0;
		readInt(fileNum, allNumbers, allNumbersSize);
		fileNum.close();
		if (allNumbersSize == 0) {
			throw std::logic_error("File Numbers.txt doesn't have any numbers!!!");
		}
		//printArr(allNumbers, allNumbersSize);

		int32_t* allNumbersCpy = new int32_t[1000];
		copyArr(allNumbersCpy, allNumbers, allNumbersSize);
		paritySort(allNumbersCpy, allNumbersSize);
		//printArr(allNumbersCpy, allNumbersSize);

		std::ifstream fileStr("src/main/Strings.txt");
		checkFile(fileStr);
		std::string* allSurnames = new std::string[1000];
		size_t allSurnamesSize = 0;
		readSurnames(fileStr, allSurnames, allSurnamesSize);
		fileStr.close();
		if (allSurnamesSize == 0) {
			throw std::logic_error("File Strings.txt has no surnames!!!");
		}
		mergeSort(allSurnames, 0, allSurnamesSize - 1, compareSurnames);
		//printArr(allSurnames, allSurnamesSize);

		Employee* employees = new Employee[1000];
		size_t employeesSize = allSurnamesSize;
		fillEmployyes(employees, employeesSize, allNumbers, allNumbersSize, allSurnames);
		mergeSort(employees, 0, employeesSize - 1, compareEmployees);
		//printEmployees(employees, employeesSize);

		std::ofstream fileRes("src/main/result.txt");
		employeesToTxt(fileRes, employees, employeesSize);
		fileRes.close();

		std::ofstream fileResBin("src/main/result.bin", std::ios::binary);
		employeesToBin(fileResBin, employees, employeesSize);
		fileResBin.close();

		std::ifstream fileInBin("src/main/result.bin", std::ios::binary);
		checkFile(fileInBin);
		printBin(fileInBin, employees, employeesSize);
		fileInBin.close();

		delete[] allNumbers;
		delete[] allNumbersCpy;
		delete[] allSurnames;
		delete[] employees;
	}
	catch(std::logic_error e) {
		std::cerr << e.what() << '\n';
	}
	catch(std::runtime_error e) {
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

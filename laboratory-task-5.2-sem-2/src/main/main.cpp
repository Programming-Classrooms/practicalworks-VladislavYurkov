#include "src/Trucks/Trucks.hpp"
#include "src/CircularQueue/CircularQueue.hpp"

int main()
{
	try
	{

		//=======================================Int====================================
		CircularQueue<int> standartInt;
		CircularQueue<int> tenInt(10);
		CircularQueue<int> copyInt(tenInt);

		tenInt.push_back(3);
		tenInt.push_back(4);
		tenInt.push_back(5);
		tenInt.pop_front();
		copyInt = tenInt;
		std::cout << copyInt[1] << '\n';
		tenInt.print(std::cout);
		std::cout << copyInt.getByIndex(copyInt.find(5)) << '\n' << '\n';

		//======================================Char*===================================
		CircularQueue<char*> standartChar;
		CircularQueue<char*> tenChar(10);
		CircularQueue<char*> copyChar(tenChar);

		tenChar.push_back("Three");
		tenChar.push_back("Four");
		tenChar.push_back("Five");
		tenChar.pop_front();
		copyChar = tenChar;
		std::cout << copyChar[1] << '\n';
		tenChar.print(std::cout);
		std::cout << copyChar.getByIndex(copyChar.find("Five")) << '\n' << '\n';

		//=====================================Trucks===================================
		CircularQueue<Trucks> standartTrucks;
		CircularQueue<Trucks> tenTrucks(10);
		CircularQueue<Trucks> copyTrucks(tenTrucks);

		std::string* threeTrucks = new std::string[3];
		std::string* fourTrucks = new std::string[4];
		std::string* fiveTrucks = new std::string[5];
		
		threeTrucks[0] = "One";
		threeTrucks[1] = "Two";
		threeTrucks[2] = "Three";

		fourTrucks[0] = "One";
		fourTrucks[1] = "Two";
		fourTrucks[2] = "Three";
		fourTrucks[3] = "Four";

		fiveTrucks[0] = "One";
		fiveTrucks[1] = "Two";
		fiveTrucks[2] = "Three";
		fiveTrucks[3] = "Four";
		fiveTrucks[4] = "Five";

		tenTrucks.push_back(Trucks(threeTrucks, 3));
		tenTrucks.push_back(Trucks(fourTrucks, 4));
		tenTrucks.push_back(Trucks(fiveTrucks, 5));
		tenTrucks.pop_front();
		copyTrucks = tenTrucks;
		std::cout << copyTrucks[1] << '\n';
		tenTrucks.print(std::cout);
		std::cout << copyTrucks.getByIndex(copyTrucks.find(Trucks(fiveTrucks, 5)));
		
		delete[] threeTrucks;
		delete[] fourTrucks;
		delete[] fiveTrucks;

	}
	catch(const std::logic_error& e)
	{
		std::cerr << e.what() << '\n';
	}
	catch(const std::out_of_range& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	return 0;
}

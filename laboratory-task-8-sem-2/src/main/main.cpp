#include "src/Library/Library.hpp"

int main()
{
	std::vector<std::string> authorsList;
	authorsList.push_back("FirstAuthor");
	authorsList.push_back("SecondAuthor");
	authorsList.push_back("ThirdAuthor");
	authorsList.push_back("FourthAuthor");
	authorsList.push_back("FifthAuthor");
	
	Book firstBook("First", authorsList, 25.6, 20000);
	Book secondBook("Second", authorsList, 28.4, 30000);
	Book thirdBook("Third", authorsList, 20.2, 10000);
	Book fourthBook("Fourh", authorsList, 21.2, 15000);
	Book fifthBook("Fifth", authorsList, 30.6, 100);
	
	Library schoolLibrary;
	schoolLibrary.addBook(firstBook);
	schoolLibrary.addBook(fourthBook);
	schoolLibrary.addBook(secondBook);
	schoolLibrary.addBook(fifthBook);
	schoolLibrary.addBook(thirdBook);
	
	std::cout << "First book:\n";
	schoolLibrary.searchBook("0000000000001").print();
	std::cout << '\n';

	schoolLibrary.deleteBook("0000000000002");
		
	schoolLibrary.addAuthor("0000000000003", "SixthAuthor");
	
	schoolLibrary.deleteAuthor("0000000000004", "FourthAuthor");

	schoolLibrary.print();

	std::cout << "Sorted by ISBN:\n";
	schoolLibrary.sortByISBN();
	schoolLibrary.print();

	std::cout << "Sorted by alphabet:\n";
	schoolLibrary.sortByNamesAlphabethical();
	schoolLibrary.print();

	return 0;
}

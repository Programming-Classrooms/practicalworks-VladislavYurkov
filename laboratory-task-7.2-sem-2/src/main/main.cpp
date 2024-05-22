#include "src/Library/Library.hpp"

int main()
{
	try
	{
	std::ifstream fileBooks("src/Resources/books.txt");
	Library books(fileBooks);
	fileBooks.close();
	books.findByTitle("Стихи");
	books.findByAuthor("Пушкин");
	Book captainDauther("5676366;Пушкин;Капитанская дочка;1965");
	books.addAuthor(captainDauther, "Pushkin");
	books.deleteAuthor(captainDauther, "Пушкин");
	books.findByTitle("Капитанская дочка");
	}
	catch(const std::invalid_argument& e)
	{
		std::cerr << e.what() << '\n';
	}
	catch(const std::logic_error& e)
	{
		std::cerr << e.what() << '\n';
	}
	return 0;
}

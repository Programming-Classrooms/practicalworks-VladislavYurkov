#include "Library.hpp"

std::vector<Book>::iterator Library::findByISBN
(const std::string& findingISBN)
{
    std::vector<Book>::iterator iter = books.begin();
    while (iter != books.end()) {
        if(iter->getISBN() == findingISBN) {
            return iter;
        }
        ++iter;
    }
    throw std::invalid_argument("There is no such book in a library!");
}

void Library::addBook(const Book& newBook)
{
    books.push_back(newBook);
}

Book Library::searchBook(const std::string& searchingISBN)
{
    Book foundedBook = *(findByISBN(searchingISBN));
    return foundedBook;
}

void Library::deleteBook(const std::string& searchingISBN)
{
    books.erase(findByISBN(searchingISBN));
}

void Library::print() const
{
    for (auto book : books) {
        book.print();
        std::cout << '\n';
    }
}

void Library::addAuthor(const std::string& ISBN, const std::string& newAuthor)
{
    std::vector<Book>::iterator foundedBook = findByISBN(ISBN);
    foundedBook->authorAdd(newAuthor);
}

void Library::deleteAuthor(const std::string& ISBN, const std::string& authorToDelete)
{
    findByISBN(ISBN)->authorDelete(authorToDelete);
}

bool ISBNcmp(const Book& lhs, const Book& rhs)
{
    return lhs.getISBN() <= rhs.getISBN();
}

bool alphabetCmp(const Book& lhs, const Book& rhs)
{
    return lhs.getTitle() <= rhs.getTitle();
}
void Library::sortByISBN()
{
    std::sort(books.begin(), books.end(), ISBNcmp);
}

void Library::sortByNamesAlphabethical()
{
    std::sort(books.begin(), books.end(), alphabetCmp);
}

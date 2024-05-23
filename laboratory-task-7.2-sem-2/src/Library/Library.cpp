#include "Library.hpp"

bool Library::isInLibrary(const Book& book)
{
    return books.find(book) != books.end();
}

Library::Library() {}

Library::Library(std::ifstream& fileIn)
{
    std::string line;
    while (std::getline(fileIn, line)) {
        this->bookAdd(Book(line));
    }
    
}

Library::~Library() {}

void Library::bookAdd(const Book& newBook)
{
    if (isInLibrary(newBook)) {
        std::cout << "That book is already in library\n";
    }
    books.insert(newBook);
}

void Library::bookRemove(const Book& bookToRemove)
{
    if(isInLibrary(bookToRemove)) {
        books.erase(bookToRemove);
    }
    else {
        throw std::invalid_argument("This book is not in library");
    }
}

void Library::findByTitle(const std::string& title)
{
    bool founded = false;
    for (auto item : books) {
        if (title == item.getTitle()) {
            std::cout << item << '\n';
            founded = true;
        }
    }
    if (!founded) {
        std::cout << "Book with that name is not founded\n";
    }
}

void Library::findByAuthor(const std::string& author)
{
    bool founded = false;
    for (auto item : books) {
        std::set<std::string> itemAuthors = item.getAuthors();
        if (itemAuthors.find(author) != itemAuthors.end()) {
            std::cout << item << '\n';
            founded = true;
        }
    }
    if (!founded) {
        std::cout << "Book with that author is not founded\n";
    }
}

void Library::addAuthor(Book& book, const std::string& author)
{
    if (!isInLibrary(book)) {
        throw std::invalid_argument("There is no such book in library!");
    }
    books.erase(book);
    book.addAuthor(author);
    books.insert(book);
}

void Library::deleteAuthor(Book& book, const std::string& author)
{
    if (!isInLibrary(book)) {
        throw std::invalid_argument("There is no such book in library!");
    }
    books.erase(book);
    book.deleteAuthor(author);
    books.insert(book);
}

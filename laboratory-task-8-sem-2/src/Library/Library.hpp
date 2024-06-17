#ifndef LIBRARY_HPP
#define LIBRARY_HPP
#include "src/Book/Book.hpp"


class Library
{
private:
    std::vector<Book> books;

    std::vector<Book>::iterator findByISBN(const std::string&);
public:
    Library() = default;
    ~Library() = default;
    
    void addBook(const Book&);
    Book searchBook(const std::string&);
    void deleteBook(const std::string&);

    void print() const;

    void addAuthor(const std::string&, const std::string&);
    void deleteAuthor(const std::string&, const std::string&);

    void sortByISBN();
    void sortByNamesAlphabethical();
};

#endif

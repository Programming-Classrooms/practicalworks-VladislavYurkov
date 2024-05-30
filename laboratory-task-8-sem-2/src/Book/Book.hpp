#ifndef BOOK_HPP
#define BOOK_HPP
#include <iostream>
#include <string>
#include <vector>

class Book
{
private:
    static size_t booksCounter;
    std::string ISBN;
    std::string title;
    std::vector<std::string> authors;
    double price;
    size_t count;
public:
    Book() = delete;
    Book(const Book&);
    Book(Book&&);
    Book(std::string, std::vector<std::string>, double, size_t);
    ~Book();

    Book& operator=(Book&&);

    std::string getISBN() const;
    std::string getTitle() const;

    void authorAdd(std::string);
    void authorDelete(std::string);

    void print() const;
};

#endif

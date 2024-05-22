#ifndef BOOK_HPP
#define BOOK_HPP
#include <iostream>
#include <set>
#include <string>
#include <vector>


class Book
{
private:
    size_t numberUDC;
    mutable std::set<std::string> authorsList;
    std::string title;
    int32_t publishingYear;
public:
    Book() = delete;
    Book(std::string);
    ~Book();

    std::string getTitle() const;
    size_t getNumberUDC() const;
    std::set<std::string> getAuthors() const;

    bool operator==(const Book&);

    void addAuthor(const std::string&);
    void deleteAuthor(const std::string&);

    friend std::ostream& operator<<(std::ostream&, const Book&);
};


#endif

#ifndef LIBRARY_HPP
#define LIBRARY_HPP
#include "src/Book/Book.hpp"
#include <fstream>

template<typename T>
struct TitleComp{
    constexpr bool operator()(const T& lhs, const T& rhs) const 
    {
        if (lhs.getTitle() != rhs.getTitle()) {
            return lhs.getTitle() < rhs.getTitle();
        }
        else {
            return lhs.getNumberUDC() < rhs.getNumberUDC();
        }
    }
};

class Library
{
private:
    std::set<Book, TitleComp<Book>> books;

    bool isInLibrary(const Book&);
public:
    Library();
    Library(std::ifstream&);
    ~Library();

    void bookAdd(const Book&);
    void bookRemove(const Book&);
    void findByTitle(const std::string&);
    void findByAuthor(const std::string&);
    void addAuthor(Book&, const std::string&);
    void deleteAuthor(Book&, const std::string&);
};


#endif

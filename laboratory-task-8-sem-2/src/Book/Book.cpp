#include "Book.hpp"

size_t Book::booksCounter = 0;

std::string numToISBN(size_t num)
{
    std::string IBSNnum = std::to_string(num);
    size_t IBSNnumLen = IBSNnum.length();
    if (IBSNnumLen > 13) {
        throw std::out_of_range("IBNS is longer then 13 numbers!");
    }
    while (IBSNnumLen != 13) {
        IBSNnum.insert(IBSNnum.begin(), '0');
        ++IBSNnumLen;
    }
    return IBSNnum;
}

Book::Book(std::string initTitle, 
           std::vector<std::string> initAuthors, 
           double initPrice, 
           size_t initCount) :
ISBN(numToISBN(++booksCounter)),
title(initTitle),
authors(initAuthors),
price(initPrice),
count(initCount)
{}

Book::Book(const Book& rhs) :
ISBN(rhs.ISBN),
title(rhs.title),
authors(rhs.authors),
price(rhs.price),
count(rhs.count)
{}

Book::Book(Book&& rhs) :
ISBN(rhs.ISBN),
title(rhs.title),
authors(rhs.authors),
price(rhs.price),
count(rhs.count)
{
    rhs.title = '\0';
    rhs.authors.clear();
    rhs.price = 0;
    rhs.count = 0;
}

Book::~Book(){};

Book& Book::operator=(Book&& rhs)
{
    ISBN = rhs.ISBN;
    rhs.ISBN = '\0';
    title = rhs.title;
    rhs.title = '\0';
    authors = rhs.authors;
    rhs.authors.clear();
    price = rhs.price;
    rhs.price = 0;
    count = rhs.count;
    rhs.count = 0;
    return *this;
}

std::string Book::getISBN() const
{
    return ISBN;
}

std::string Book::getTitle() const
{
    return title;
}

void Book::authorAdd(std::string newAuthor)
{
    if (std::find(authors.begin(),authors.end(), newAuthor) != authors.end()) {
        throw std::invalid_argument("This book already has this author!");
    }
    authors.push_back(newAuthor);
}

void Book::authorDelete(std::string authorToDelete)
{
    std::vector<std::string>::iterator authorToDeleteIter = std::find(authors.begin(),authors.end(), authorToDelete);
    if (authorToDeleteIter == authors.end()) {
        throw std::invalid_argument("There is no such author in this book!");
    }
    authors.erase(authorToDeleteIter);
}

void Book::print() const
{
    std::cout << "ISBN-13 " << ISBN << '\n';
    std::cout << "Title: \"" << title << "\"\n";
    std::cout << "Authors:\n";
    for (auto author : authors) {
        std::cout << author << '\n';
    }
    std::cout << "Price: " << price << '\n';
    std::cout << "Number of copies: " << count << '\n';
}

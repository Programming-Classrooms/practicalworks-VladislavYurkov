#include "Book.hpp"

Book::Book(std::string line)
{
    std::string::size_type begInd;
    std::string::size_type endInd;
    std::vector<std::string> words;

    begInd = line.find_first_not_of(";");
    while(begInd != std::string::npos) {
        endInd = line.find_first_of(";", begInd);
        if(endInd == std::string::npos) {
            endInd = line.length();
        }

        words.push_back(line.substr(begInd, endInd - begInd));

        begInd = line.find_first_not_of(";", endInd);
    }

    numberUDC = stoull(words[0]);

    std::string authors = words[1];
    begInd = authors.find_first_not_of(",");
    while (begInd != std::string::npos) {
        endInd = authors.find_first_of(",", begInd);
        if(endInd == std::string::npos) {
            endInd = authors.length();
        }

        authorsList.insert(authors.substr(begInd, endInd - begInd));

        begInd = authors.find_first_not_of(",", endInd);
    }
    
    title = words[2];

    publishingYear = stoi(words[3]);

}

Book::~Book() {}

std::string Book::getTitle() const
{
    return title;
}

size_t Book::getNumberUDC() const
{
    return numberUDC;
}

std::set<std::string> Book::getAuthors() const
{
    return authorsList;
}

bool Book::operator==(const Book& rhs)
{
    return (this->numberUDC == rhs.numberUDC) &&
    (this->title == rhs.title) &&
    (this->authorsList == rhs.authorsList) &&
    (this->publishingYear == rhs.publishingYear);
}

void Book::addAuthor(const std::string& newAuthor)
{
    if (authorsList.find(newAuthor) != authorsList.end()) {
        throw std::logic_error("This author is already in list!");
    }
    authorsList.insert(newAuthor);
}

void Book::deleteAuthor(const std::string& author)
{
    if (authorsList.find(author) == authorsList.end()) {
        throw std::invalid_argument("There is no such author in list!");
    }
    authorsList.erase(author);
}

std::ostream& operator<<(std::ostream& out, const Book& rhs)
{
    out << "UDC number: " << rhs.numberUDC << '\n';
    out << "Name: " << rhs.title << '\n';
    out << "Publishing year: " << rhs.publishingYear << '\n';
    out << "Authors:\n";
    for (auto author : rhs.authorsList) {
        out << author << '\n';
    }
    return out;
}

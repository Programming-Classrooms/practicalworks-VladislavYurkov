#include "Functions.hpp"

void checkFile(std::ifstream& fileIn)
{
    if (!fileIn.good()) {
        throw std::logic_error("File is not exist!");
    }
    if (!fileIn) {
        throw std::logic_error("File is not opened!");
    }
    if (fileIn.peek() == EOF) {
        throw std::logic_error("File is empty!");
    }
}

std::vector<std::string> readWordsFromFile(std::ifstream& in)
{
    std::vector<std::string> readed;

    std::string::size_type begInd;
    std::string::size_type endInd;

    std::string line;

    while (std::getline(in, line)) {
        begInd = line.find_first_not_of(" ");

        while (begInd != std::string::npos) {
            endInd = line.find_first_of(" ", begInd);
            if (endInd == std::string::npos) {
                endInd = line.length();
            }
            
            std::string word = line.substr(begInd, endInd - begInd);
            readed.push_back(word);

            begInd = line.find_first_not_of(" ", endInd);
        }
        
    }
    
    return readed;
}

void printWordsStartsWithSymbol(std::vector<std::string> rhs, char symbol)
{
    std::cout << "Elements starts with \'" << symbol << "\': ";
    for (auto item : rhs) {
        if (item[0] == symbol) {
            std::cout << item << ' ';
        }
    }
    std::cout << '\n';
}

void deleteWordsStartsWithSymbol(std::vector<std::string>& rhs, char symbol)
{
    for (size_t i = 0; i < rhs.size();) {
        if (rhs[i][0] == symbol) {
            rhs.erase(rhs.begin() + i);
        }
        else {
            ++i;
        }
    }
}

#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP
#include <vector>
#include <string>
#include <fstream>
#include <iostream>

void checkFile(std::ifstream&);

std::vector<std::string> readWordsFromFile(std::ifstream&);

template<typename T>
void printVector(std::vector<T> rhs) 
{
    std::cout << "Your vector: ";
    for (auto i : rhs) {
        std::cout << i << ' ';
    }
    std::cout << '\n';
}

void printWordsStartsWithSymbol(std::vector<std::string>, char);

void deleteWordsStartsWithSymbol(std::vector<std::string>&, char);

#endif

#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP
#include <iostream>
#include <vector>
#include <string>
#include <climits>

bool isInt(std::string);

std::vector<int> readInt();

template<typename T>
void printVector(std::vector<T> rhs) 
{
    std::cout << "Your vector: ";
    for (auto i : rhs) {
        std::cout << i << ' ';
    }
    std::cout << '\n';
}

int numbersSum(std::vector<int>);

size_t numbersCount(std::vector<int>);

int inputInt();

size_t eqNumbersCount(std::vector<int>, int);

bool greaterThen(int, int);

size_t suiteNumbersCount(std::vector<int>, bool (int, int), int);

void replaceNulls(std::vector<int>&);

void intervalInput(size_t&, size_t&);

void increaceByRange(std::vector<int>&);

void replaceEven(std::vector<int>&);

void deleteRepeat(std::vector<int>&);

#endif

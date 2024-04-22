#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP
#include <iostream>
#include <vector>
#include <string>
#include <climits>


bool isInt(std::string word)
{
    if ((word[0] > '9' || word[0] < '0') && word[0] != '-') {
        return false;
    }
    size_t wordLen = word.length();
    for (size_t i = 0; i < wordLen; ++i) {
        if (word[i] > '9' || word[i] < '0') {
            return false;
        }
    }
    return true;
}

std::vector<int> readInt()
{
    std::vector<int> readedVector;

    std::cout << "Input integers: ";
    std::string line;
    getline(std::cin, line);

    std::string::size_type begInd;
    std::string::size_type endInd;

    begInd = line.find_first_not_of(" ");

    while (begInd != std::string::npos) {
        endInd = line.find_first_of(" ", begInd);
        if (endInd == std::string::npos) {
            endInd = line.length();
        }
        
        std::string word = line.substr(begInd, endInd - begInd);

        if (!isInt(word)) {
            throw std::logic_error("Line has not only integers!");
        }
        
        readedVector.push_back(stoi(word));

        begInd = line.find_first_not_of(" ", endInd);
    }

    return readedVector;
}

template<typename T>
void printVector(std::vector<T> rhs) 
{
    std::cout << "Your vector: ";
    for (auto i : rhs) {
        std::cout << i << ' ';
    }
    std::cout << '\n';
}

int numbersSum(std::vector<int> rhs) 
{
    int sum = 0;
    for (auto i : rhs) {
        sum += i;
    }
    return sum;
}

size_t numbersCount(std::vector<int> rhs)
{
    return rhs.size();
}

int inputInt()
{
    std::string line;
    std::getline(std::cin, line);
    if (!isInt(line)) {
        throw std::logic_error("Inputed line is not a integer!");
    }

    return stoi(line);
}

size_t eqNumbersCount(std::vector<int> rhs, int target)
{
    size_t counter = 0;

    for (auto i : rhs) {
        if (i == target) {
            ++counter;
        }
    }

    return counter;
}

bool greaterThen(int lhs, int rhs)
{
    return lhs > rhs;
}

size_t suiteNumbersCount(std::vector<int> rhs, bool comp(int, int), int target) 
{
    size_t counter = 0;
    for (auto i : rhs) {
        if (comp(i, target)) {
            ++counter;
        }
    }
    return counter;
}

void replaceNulls(std::vector<int>& rhs)
{
    int average = numbersSum(rhs) / numbersCount(rhs);
    for (auto& i : rhs) {
        if (i == 0) {
            i = average;
        }
    }
}

void intervalInput(size_t& begInd, size_t& endInd)
{
    std::cout << "Input begin index: ";
    int temp = inputInt();
    if (temp < 0) {
        throw std::out_of_range("Negative index is not allowed!");
    }
    begInd = static_cast<size_t>(temp);
    std::cout << "Input end index: ";
    temp = inputInt();
    if (temp < 0) {
        throw std::out_of_range("Negative index is not allowed!");
    }
    endInd = static_cast<size_t>(temp);
    if (begInd > endInd) {
        throw std::logic_error("Begin index bigger than end index!");
    }
}

void increaceByRange(std::vector<int>& rhs)
{
    size_t begInd = 0;
    size_t endInd = 0;
    intervalInput(begInd, endInd);
    std::vector<int> range(rhs.begin() + begInd, rhs.begin() + endInd + 1);
    int increaceValue = numbersSum(range);
    for (auto& elem : rhs) {
        elem += increaceValue;
    }
}

void replaceEven(std::vector<int>& rhs)
{
    int min = INT_MAX;
    int max = INT_MIN;

    for (auto elem : rhs) {
        if (elem > max) {
            max = elem;
        }
        if (elem < min) {
            min = elem;
        }
    }
    
    int minMax = max - min;

    for (auto& elem : rhs) {
        if (elem % 2 == 0) {
            elem = minMax;
        }
    }
}

void deleteRepeat(std::vector<int>& rhs)
{
    for (size_t i = 0; i < rhs.size() - 1; ++i) {
        for (size_t j = i+1; j < rhs.size(); ++j) {
            if (rhs[i] == rhs[j]) {
                rhs.erase(rhs.begin() + j);
            }
        }
    }
}

#endif

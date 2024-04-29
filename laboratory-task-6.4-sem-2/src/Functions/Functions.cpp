#include "Functions.hpp"

size_t strToSize_t(std::string line)
{
    if (line.empty()) {
        throw std::logic_error("Input is empty!");
    }
    size_t lineSize = line.size();
    for (size_t i = 0; i < lineSize; ++i)
    {
        if (!(line[i] >= '0' && line[i] <= '9'))
        {
            throw std::invalid_argument("This is not a natural number!");
        }
    }
    return stoull(line);
}

void inputSize(size_t& rows, size_t& columns)
{
    std::string input;
    std::cout << "Input rows number: ";
    std::getline(std::cin, input);
    rows = strToSize_t(input);
    std::cout << "Input columns number: ";
    std::getline(std::cin, input);
    columns = strToSize_t(input);
}

void memAllocMtrx(std::vector<std::vector<int>>& mtrx, const size_t rows, const size_t columns)
{
    mtrx = std::vector<std::vector<int>>(rows);
    for (auto& row : mtrx) {
        row = std::vector<int>(columns);
    }
}

int strToInt(std::string line)
{
    if (line.empty()) {
        throw std::logic_error("Input is empty!");
    }
    bool first = true;
    for(auto item : line) {
        if (first) {
            if (item == '-') {
                continue;
            }
        }
        if (!(item >= '0' && item <= '9')) {
            throw std::invalid_argument("This is not an integer!");
        }
    }
    return stoi(line);
}

void inputInterval(int& lowerBound, int& upperBound)
{
    std::string input;
    std::cout << "Input left border: ";
    std::getline(std::cin, input);
    lowerBound =  strToInt(input);
    std::cout << "Input right border: ";
    std::getline(std::cin, input);
    upperBound = strToInt(input);
    if (lowerBound > upperBound) {
        throw std::logic_error("Border are swaped!");
    }
}

int randInt(int lowerBound, int upperBound)
{
    return rand() % (upperBound - lowerBound + 1) + lowerBound;
} 

void fillRandMtrx(std::vector<std::vector<int>>& mtrx, int lowerBound, int upperBound)
{
    srand(time(NULL));
    for (auto& row : mtrx) {
        for (auto& item : row) {
            item = randInt(lowerBound, upperBound);
        }
    }
}

void initMtrx(std::vector<std::vector<int>>& mtrx)
{
    size_t rows;
    size_t columns;
    int lowerBound;
    int upperBound;
    inputSize(rows, columns);
    inputInterval(lowerBound, upperBound);
    memAllocMtrx(mtrx, rows, columns);
    fillRandMtrx(mtrx, lowerBound, upperBound);
}

void printMtrx(std::vector<std::vector<int>> mtrx)
{
    for (auto row : mtrx) {
        for (auto item : row) {
            std::cout << item << ' ';
        }
        std::cout << '\n';
    }
}

void anihilateMax(std::vector<std::vector<int>>& mtrx)
{
    size_t maxRow = 0;
    size_t maxColumn = 0;
    int max = mtrx[0][0];
    size_t rows = mtrx.size();
    size_t columns = mtrx[0].size();
    for (size_t i = 0; i < rows; ++i) {
        for (size_t j = 0; j < columns; ++j) {
            if (mtrx[i][j] > max) {
                max = mtrx[i][j];
                maxRow = i;
                maxColumn = j;
            }
        }
    }
    
    mtrx.erase(mtrx.begin() + maxRow);
    for (auto& row : mtrx) {
        row.erase(row.begin() + maxColumn);
    }
}

int rowSum(std::vector<int> row) {
    int sum = 0;
    for (auto item : row) {
        sum += item;
    }
    return sum;
}

void sortRows(std::vector<std::vector<int>>& mtrx)
{
    size_t rows = mtrx.size();
    std::vector<int> rowsSum(rows);
    for (size_t i = 0; i < rows; ++i) {
        rowsSum[i] = rowSum(mtrx[i]);
    }
    for (size_t i = 0; i < rows - 1; ++i) {
        for (size_t j = 0; j < rows - 1 - i; ++j) {
            if (rowsSum[j] > rowsSum[j+1]) {
                std::swap(rowsSum[j], rowsSum[j+1]);
                std::swap(mtrx[j], mtrx[j+1]);
            }
        }
    }
}


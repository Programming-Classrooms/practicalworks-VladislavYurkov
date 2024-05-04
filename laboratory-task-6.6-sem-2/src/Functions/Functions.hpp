#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP
#include "src/Train/Train.hpp"
#include <fstream>

void readTrains(std::ifstream&, std::vector<Train>&);

template<typename T>
void printVect(const std::vector<T>& rhs) 
{
    for (const auto& item : rhs) {
        std::cout << item << '\n';
    }
}

bool departEarlier(const Train&, const Train&);

void sortByDepartment(std::vector<Train>&);

void inputTimeInterval(size_t&, size_t&);

std::string timeToStr(size_t);

void printTimeRange(const std::vector<Train>&, size_t, size_t);

void inputDestination(std::string&);

std::vector<Train> destTrains(const std::vector<Train>&, std::string);

void printFastTrains(const std::vector<Train>&);

void printFastestTrain(const std::vector<Train>&);

#endif

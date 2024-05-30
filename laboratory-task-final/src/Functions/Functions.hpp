#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP
#include <vector>
#include <fstream>
#include <map>
#include "src/BusRoute/BusRoute.hpp"

void fileToBusVect(std::vector<BusRoute>& routesVect, std::ifstream& fileIn);

void printRoutesVect(const std::vector<BusRoute>& routesVect);

void routesSort(std::vector<BusRoute>& routesVect);

void vectToMap(const std::vector<BusRoute>& routesVect, 
               std::map<size_t, BusRoute> routesMap);

#endif

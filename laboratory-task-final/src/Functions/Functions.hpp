#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP
#include <vector>
#include <fstream>
#include <map>
#include <set>
#include <algorithm>
#include "src/BusRoute/BusRoute.hpp"

void fileToBusVect(std::vector<BusRoute>& routesVect, std::ifstream& fileIn);

void printRoutesVect(const std::vector<BusRoute>& routesVect);

void routesSort(std::vector<BusRoute>& routesVect);

void vectToMap(const std::vector<BusRoute>& routesVect, 
               std::map<size_t, BusRoute>& routesMap);

void printRoutesMap(const std::map<size_t, BusRoute>& routesMap);

void printByRouteNum(const std::vector<BusRoute>& routesVect, size_t routeNumber);

void printDriversByMark(const std::vector<BusRoute>& routesVect, std::string mark);

size_t maxDiffMarks(const std::vector<BusRoute>& routesVect);

void deleteByKey(std::map<size_t, BusRoute>& routesMap, size_t key);

#endif

#include "Functions.hpp"

void fileToBusVect(std::vector<BusRoute>& routesVect, std::ifstream& fileIn)
{
    std::string line;
    while (std::getline(fileIn, line)) {
        routesVect.push_back(BusRoute(line));
    }
}

void printRoutesVect(const std::vector<BusRoute>& routesVect)
{
    for (auto busRoute : routesVect) {
        busRoute.print();
    }
}

bool routesCmp(const BusRoute& lhs, const BusRoute& rhs)
{
    if(lhs.getBusNumber() == rhs.getBusNumber()) {
        return lhs.getRouteNumber() <= rhs.getRouteNumber();
    }
    return lhs.getBusNumber() <= rhs.getBusNumber();
}

void routesSort(std::vector<BusRoute>& routesVect)
{
    std::sort(routesVect.begin(), routesVect.end(), routesCmp);
}

void vectToMap(const std::vector<BusRoute>& routesVect, 
               std::map<size_t, BusRoute>& routesMap)
{
    for (auto route : routesVect) {
        routesMap.emplace(route.getBusNumber(), route);
    }
}

void printRoutesMap(const std::map<size_t, BusRoute>& routesMap)
{
    for (auto route : routesMap) {
        route.second.print();
    }
}

void printByRouteNum(const std::vector<BusRoute>& routesVect, size_t routeNumber)
{
    std::cout << "Busses with route number " << routeNumber << ":\n";
    for (auto route : routesVect) {
        if (route.getRouteNumber() == routeNumber) {
            route.print();
        }
    }
}

void printDriversByMark(const std::vector<BusRoute>& routesVect, std::string mark)
{
    std::cout << "Drivers that work on " << mark << ":\n";
    for (auto route : routesVect) {
        if (route.getBusMark() == mark) {
            std::cout << route.getDriverSurname() << '\n';
        }
    }
}

size_t maxDiffMarks(const std::vector<BusRoute>& routesVect)
{
    std::map<size_t, std::set<std::string>> routesMap;
    for (auto route : routesVect) {
        routesMap[route.getRouteNumber()].insert(route.getBusMark());
    }
    size_t maxLen = 0;
    size_t maxRouteNum = 0; 
    for (auto route : routesMap) {
        if (route.second.size() > maxLen) {
            maxRouteNum = route.first;
            maxLen = route.second.size();
        }
    }
    return maxRouteNum;
}

void deleteByKey(std::map<size_t, BusRoute>& routesMap, size_t key)
{
    if (routesMap.find(key) == routesMap.end()) {
        throw std::invalid_argument("No route with such key!");
    }
    routesMap.erase(key);
}

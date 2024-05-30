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
            std::cout << route.getDriverSurname();
        }
    }
    std::cout << '\n';
}

#include "BusRoute.hpp"

BusRoute::BusRoute() :
routeNumber(0),
driverSurname("Noname"),
busNumber(0),
busMark("No mark")
{}

BusRoute::~BusRoute() {}

size_t strToSize_t(std::string word)
{
    for (char letter : word) {
        if (!((letter >= '0') && (letter <= '9'))) {
            throw std::logic_error("Error converting string to size_t!");
        }
    }
    return std::stoull(word);
}

BusRoute::BusRoute(const std::string& line)
{
    std::stringstream lineStream(line);
    std::string word;
    lineStream >> word;
    this->routeNumber = strToSize_t(word);
    lineStream >> word;
    this->driverSurname = word;
    lineStream >> word;
    this->busNumber = strToSize_t(word);
    lineStream >> word;
    this->busMark = word;
}

size_t BusRoute::getRouteNumber() const
{
    return routeNumber;
}

std::string BusRoute::getDriverSurname() const
{
    return driverSurname;
}

size_t BusRoute::getBusNumber() const
{
    return busNumber;
}

std::string BusRoute::getBusMark() const
{
    return busMark;
}

void BusRoute::print() const
{
    std::cout << routeNumber << ' ' << driverSurname << ' ' << busNumber << ' ' << busMark << '\n';
}

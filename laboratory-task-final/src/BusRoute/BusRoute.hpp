#ifndef BUSROUTE_HPP
#define BUSROUTE_HPP
#include <iostream>
#include <string>
#include <sstream>

class BusRoute
{
private:
    size_t routeNumber;
    std::string driverSurname;
    size_t busNumber;
    std::string busMark;
public:
    BusRoute();
    BusRoute(const std::string&);
    ~BusRoute();

    size_t getRouteNumber() const;
    std::string getDriverSurname() const;
    size_t getBusNumber() const;
    std::string getBusMark() const;

    void print() const;

};

#endif

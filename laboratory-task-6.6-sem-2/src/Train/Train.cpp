#include "Train.hpp"

Train::Train() :
trainNumber(0),
destination("No destination"),
type(TrainType::PASSENGER),
departureTime(0),
travelTime(0)
{}

Train::Train(std::string line)
{
    std::string::size_type begInd;
    std::string::size_type endInd;

    begInd = line.find_first_not_of(" ");
    endInd = line.find_first_of(" ", begInd);
    trainNumber = stoull(line.substr(begInd, endInd - begInd));

    begInd = line.find_first_not_of(" ", endInd);
    endInd = line.find_first_of(" ", begInd);
    destination = line.substr(begInd, endInd - begInd);

    begInd = line.find_first_not_of(" ", endInd);
    endInd = line.find_first_of(" ", begInd);
    if (line.substr(begInd, endInd - begInd) == "скорый") {
        type = TrainType::FAST;
    }
    else {
        type = TrainType::PASSENGER;
    }

    begInd = line.find_first_not_of(" ", endInd);
    endInd = line.find_first_of(" ", begInd);
    departureTime = stoull(line.substr(begInd, 2)) * 60 + stoull(line.substr(endInd - 2, 2));

    begInd = line.find_first_not_of(" ", endInd);
    endInd = line.length();
    travelTime = stoull(line.substr(begInd, 2)) * 60 + stoull(line.substr(endInd - 2, 2));
}

Train::~Train() {}

size_t Train::getTrainNumber() const
{
    return trainNumber;
}

std::string Train::getDestination() const
{
    return destination;
}

std::string Train::getType() const
{
    return ((type == TrainType::FAST) ? "скорый" : "пассажирский");
}

size_t Train::getDepartureTime() const
{
    return departureTime;
}

size_t Train::getTravelTime() const
{
    return travelTime;
}

std::string toMinutes(size_t time)
{
    std::string minutes;
    if ((time % 60) < 9) {
        minutes.append("0");
    }
    minutes.append(std::to_string(time % 60));
    return minutes;    
}

std::ostream& operator<<(std::ostream& out, const Train& rhs)
{
    out << rhs.trainNumber << ' ';
    out << rhs.destination << ' ';
    out << rhs.getType() << ' ';
    out << rhs.departureTime / 60 << ':' << toMinutes(rhs.departureTime)  << ' ';
    out << rhs.travelTime / 60 << ':' << toMinutes(rhs.travelTime);
    return out;
}

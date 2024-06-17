#ifndef TRAIN_HPP
#define TRAIN_HPP
#include <iostream>
#include <string>
#include <vector>

enum class TrainType
{
    PASSENGER,
    FAST,
};

class Train
{
private:
    size_t trainNumber;
    std::string destination;
    TrainType type;
    size_t departureTime;
    size_t travelTime;
public:
    Train();
    Train(std::string);
    virtual ~Train();

    size_t getTrainNumber() const;
    std::string getDestination() const;
    std::string getType() const;
    size_t getDepartureTime() const;
    size_t getTravelTime() const;

    friend std::ostream& operator<<(std::ostream&, const Train&);
};

std::string toMinutes(size_t);

#endif

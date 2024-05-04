#include "Functions.hpp"

void readTrains(std::ifstream& fileIn, std::vector<Train>& trainsArr)
{
    std::string line;
    while(std::getline(fileIn, line)) {
        trainsArr.push_back(Train(line));
    }
}

bool departEarlier(const Train& first, const Train& second)
{
    return first.getDepartureTime() <= second.getDepartureTime();
}

void sortByDepartment(std::vector<Train>& trainArr)
{
    std::sort(trainArr.begin(), trainArr.end(), departEarlier);
}

size_t strToTime(std::string timeStr)
{
    if (timeStr.size() != 5) {
        throw std::invalid_argument("Это не время в формате ЧЧ:ММ");
    }
    if (timeStr[2] != ':') {
        throw std::invalid_argument("Это не время в формате ЧЧ:ММ");
    }
    for (size_t i = 0; i < 5; ++i) {
        if (i == 2) {
            continue;
        }
        if (!isdigit(timeStr[i])) {
            throw std::invalid_argument("Это не время в формате ЧЧ:ММ");
        }
    }
    return stoull(timeStr.substr(0,2)) * 60 + stoull(timeStr.substr(3,2));
}

void inputTimeInterval(size_t& begin, size_t& end)
{
    std::string input;
    std::cout << "Введите начало временного промежутка: ";
    std::getline(std::cin, input);
    begin = strToTime(input);

    std::cout << "Введите конец временного промежутка: ";
    std::getline(std::cin, input);
    end = strToTime(input);
}

std::string timeToStr(size_t time)
{
    std::string timeStr;
    timeStr.append(std::to_string(time / 60));
    timeStr.append(":");
    timeStr.append(toMinutes(time));
    return timeStr;
}

void printTimeRange(const std::vector<Train>& trainArr, size_t begin, size_t end)
{
    bool isPrinted = false;
    for (const auto& item : trainArr) {
        if (item.getDepartureTime() >= begin && item.getDepartureTime() <= end) {
            std::cout << item << '\n';
            isPrinted = true;
        }
    }
    if (!isPrinted) {
        std::cout << "Таких поездов нет" << '\n';
    }
}

void inputDestination(std::string& destination)
{
    std::cout << "Введите пункт назначения: ";
    std::getline(std::cin, destination);
}

std::vector<Train> destTrains(const std::vector<Train>& trainArr, std::string destination)
{
    std::vector<Train> trainDestArr;
    for (const auto& item : trainArr) {
        if (item.getDestination() == destination) {
            trainDestArr.push_back(item);
        }
    }
    return trainDestArr;
}

void printFastTrains(const std::vector<Train>& trainArr)
{
    bool isPrinted = false;
    for (const auto& item : trainArr) {
        if (item.getType() == "скорый") {
            std::cout << item << '\n';
            isPrinted = true;
        }
    }
    if(!isPrinted) {
        std::cout << "Таких поездов нет" << '\n';
    }
}

void printFastestTrain(const std::vector<Train>& trainArr)
{
    if (trainArr.empty()) {
        std::cout << "Такого поезда нет" << '\n';
    }
    Train fastest = trainArr[0];

    for (const auto & item : trainArr) {
        if (item.getTravelTime() < fastest.getTravelTime()) {
            fastest = item;
        }
    }
    
    std::cout << fastest << '\n';
}

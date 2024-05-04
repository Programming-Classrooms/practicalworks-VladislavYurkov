#include "src/Functions/Functions.hpp"
#include "src/Train/Train.hpp"


int main()
{
	std::vector<Train> trainsArr;
	std::ifstream fileTrains("src/resources/Trains.txt");
	readTrains(fileTrains, trainsArr);
	sortByDepartment(trainsArr);
	std::cout << "Поезда отсортированы по времени отправления:" << '\n';
	printVect(trainsArr);
	size_t begin;
	size_t end;
	inputTimeInterval(begin, end);
	std::cout << "Поезда которые отправляются с " << timeToStr(begin) << " по " << timeToStr(end) << '\n';
	printTimeRange(trainsArr, begin, end);
	std::string destination;
	inputDestination(destination);
	std::vector<Train> trainDestArr = destTrains(trainsArr, destination);
	std::cout << "Поезда которые отпраляются в " << destination << ':' << '\n';
	printVect(trainDestArr);
	std::cout << "Скорые поезда которые отправляются в " << destination << ':' << '\n';
	printFastTrains(trainDestArr);
	std::cout << "Самый быстрый поезд который отпраляется в " << destination << ':' << '\n';
	printFastestTrain(trainDestArr);
	fileTrains.close();
	return 0;
}

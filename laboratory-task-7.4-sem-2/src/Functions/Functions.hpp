#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP
#include <iostream>
#include <fstream>
#include <set>
#include <map>
#include <string>
#include <random>

typedef std::set<std::string> fishList;
typedef std::map<std::string, fishList> fisherList;

void fillLake(fishList& lake)
{
    lake.insert("Carp");
	lake.insert("Salmon");
	lake.insert("Perch");
	lake.insert("Tuna");
	lake.insert("Clownfish");
	lake.insert("Catfish");
	lake.insert("Anchovy");
}

void giveFishesToFisher(fisherList& fishers, std::vector<std::string> lake, size_t catchedFishesNum, std::string name)
{
    size_t fishesTypesNum = lake.size();
    fishList buff;
    size_t randInd;
    for (size_t i = 0; i < catchedFishesNum; ++i) {
        randInd = rand() % fishesTypesNum;
        buff.insert(lake[randInd]);
    }
    fishers.insert_or_assign(name, buff);
}

void catchFishes(fisherList& fishers, const fishList& lake, size_t catchedFishesNum)
{
    srand(time(NULL)); 
    std::vector<std::string> lakeCpy(lake.begin(), lake.end());

    giveFishesToFisher(fishers, lakeCpy, catchedFishesNum, "First");
    giveFishesToFisher(fishers, lakeCpy, catchedFishesNum, "Second");
    giveFishesToFisher(fishers, lakeCpy, catchedFishesNum, "Third");

}

void fisherInfo(const fisherList& fishers, std::ofstream& fileOut, std::string name)
{
    fileOut << name << ": ";
    fishList::iterator currentFish = fishers.at(name).begin();
    fishList::iterator endIter = fishers.at(name).end();
    while (currentFish != endIter)
    {
        fileOut << *currentFish << ' ';
        ++currentFish;
    }
    fileOut << '\n';
}

void fishersInfo(const fisherList& fishers)
{
    std::ofstream fileOut("src/Recources/fishersInfo.txt");
    fisherInfo(fishers, fileOut, "First");
    fisherInfo(fishers, fileOut, "Second");
    fisherInfo(fishers, fileOut, "Third");
    fileOut.close();
}

void sameFishes(const fisherList& fishers)
{
    std::ofstream fileOut("src/Recources/sameFishes.txt");
    std::vector<std::string> same(fishers.at("First").begin(), fishers.at("First").end());
    
    for (auto item : fishers)
    {
        std::vector<std::string> itemVec(item.second.begin(), item.second.end());
        std::vector<std::string> buff(same);
        same.clear();
        std::set_intersection(
            itemVec.begin(), itemVec.end(),
            buff.begin(), buff.end(),
            std::back_inserter(same)
        );
    }

    for (auto item : same)
    {
        fileOut << item << ' ';
    }
    fileOut << '\n';
    fileOut.close();
    
}

void notCatched(const fishList& lake, const fisherList& fishers)
{
    std::ofstream fileOut("src/Recources/notCatched.txt");
    std::vector<std::string> stillInLake(lake.begin(), lake.end());
    for (auto item : fishers) {
        std::vector<std::string> buff;
        std::set_difference(
            stillInLake.begin(), stillInLake.end(),
            item.second.begin(), item.second.end(),
            std::back_inserter(buff)
        );
        stillInLake = buff;
    }
    for (auto item : stillInLake)
    {
        fileOut << item << ' ';
    }
    fileOut << '\n';
    fileOut.close();
}

#endif

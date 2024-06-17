#include "FruitTree.hpp"

FruitTree::FruitTree() :
Tree(),
harvestMass(0.0),
averageLifeTime(0.0)
{}

FruitTree::FruitTree(std::string initName, size_t initAge, TreeType initType, double initHarvestMass, double initAverageLifeTime) :
Tree(initName, initAge, initType),
harvestMass(initHarvestMass),
averageLifeTime(initAverageLifeTime)
{}

FruitTree::~FruitTree(){}

bool FruitTree::isDeciduous() const
{
    return (this->type == TreeType::DECIDUOUS);
}

void FruitTree::print() const
{
    std::cout << "Name: " << name << '\n';
    std::cout << "Age: " << age << '\n';
    std::cout << "Type: ";
    switch (type)
    {
    case TreeType::DECIDUOUS:
        std::cout << "deciduous\n";
        break;
    case TreeType::CONIFERUOS:
        std::cout << "coniferuos\n";
    }
    std::cout << "Harvest mass: " << harvestMass << '\n';
    std::cout << "Average life time: " << averageLifeTime << '\n'; 
}

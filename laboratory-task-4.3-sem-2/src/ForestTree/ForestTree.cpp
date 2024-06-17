#include "ForestTree.hpp"

ForestTree::ForestTree() : 
Tree(),
woodAmount(0)
{}

ForestTree::ForestTree(std::string initName, size_t initAge, TreeType initType, size_t initWoodAmount) :
Tree(initName, initAge, initType),
woodAmount(initWoodAmount)
{}

ForestTree::~ForestTree(){}

bool ForestTree::isDeciduous() const
{
    return (this->type == TreeType::DECIDUOUS);
}

void ForestTree::print() const
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
    std::cout << "Wood amount: " << woodAmount << '\n';
}

#include "ForestTree.hpp"

ForestTree::ForestTree() : 
Tree(),
woodAmount(0)
{}

ForestTree::~ForestTree(){}

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
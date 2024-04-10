#ifndef FRUITTREE_HPP
#define FRUITTREE_HPP
#include "src/Tree/Tree.hpp"

class FruitTree : Tree
{
private:
    double harvestMass;
    double averageLifeTime;
public:
    FruitTree();
    ~FruitTree() override;

    void print() const override;
};

#endif

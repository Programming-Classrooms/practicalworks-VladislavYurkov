#ifndef FRUITTREE_HPP
#define FRUITTREE_HPP
#include "src/Tree/Tree.hpp"

class FruitTree : public Tree
{
private:
    double harvestMass;
    double averageLifeTime;
public:
    FruitTree();
    FruitTree(std::string, size_t, TreeType, double, double);
    ~FruitTree() override;

    bool isDeciduous() const override;

    void print() const override;
};

#endif

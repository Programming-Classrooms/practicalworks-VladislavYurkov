#ifndef FORESTTREE_HPP
#define FORESTTREE_HPP
#include "src/Tree/Tree.hpp"

class ForestTree : Tree
{
private:
    size_t woodAmount;
public:
    ForestTree();
    ~ForestTree() override;

    void print() const override;
};

#endif

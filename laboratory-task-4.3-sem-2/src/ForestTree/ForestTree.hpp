#ifndef FORESTTREE_HPP
#define FORESTTREE_HPP
#include "src/Tree/Tree.hpp"

class ForestTree : public Tree
{
private:
    size_t woodAmount;
public:
    ForestTree();
    ForestTree(std::string, size_t, TreeType, size_t);
    ~ForestTree() override;

    bool isDeciduous() const override;

    void print() const override;
};

#endif

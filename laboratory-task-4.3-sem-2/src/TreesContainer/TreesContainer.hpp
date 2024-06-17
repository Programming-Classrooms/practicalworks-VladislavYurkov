#ifndef TREESCONTAINER_HPP
#define TREESCONTAINER_HPP
#include "src/Tree/Tree.hpp"
#include "src/FruitTree/FruitTree.hpp"
#include "src/ForestTree/ForestTree.hpp"
#include <vector>
#include <fstream>
#include <string>
#include <algorithm>

class TreesContainer
{
private:
    std::vector<Tree*> container;
public:
    TreesContainer();
    TreesContainer(size_t);
    TreesContainer(const TreesContainer&);
    TreesContainer(const char*);
    ~TreesContainer();

    void push_back(Tree*);

    size_t deciduousCount() const;
    size_t coniferuosCount() const;
    size_t forestCount() const;
    size_t fruitCount() const;

    void print() const;
    void sortedPrint() const;
};



#endif

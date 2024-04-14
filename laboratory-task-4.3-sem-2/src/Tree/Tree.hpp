#ifndef TREE_HPP
#define TREE_HPP
#include <iostream>
#include <string>


enum class TreeType
{
    DECIDUOUS,
    CONIFERUOS,
};

class Tree
{
protected:
    std::string name;
    size_t age;
    TreeType type;
public:
    Tree();
    Tree(std::string, size_t, TreeType);
    virtual ~Tree() = 0;

    bool virtual isDeciduous() const = 0;

    void virtual print() const = 0;

    friend bool compTrees(Tree*&, Tree*&);
};

#endif

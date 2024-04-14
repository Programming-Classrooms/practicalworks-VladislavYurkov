#include "Tree.hpp"

Tree::Tree() :
name("No name"),
age(0),
type(TreeType::CONIFERUOS)
{}

Tree::Tree(std::string initName, size_t initAge, TreeType initType) :
name(initName),
age(initAge),
type(initType)
{}

Tree::~Tree(){};

void Tree::print() const {};

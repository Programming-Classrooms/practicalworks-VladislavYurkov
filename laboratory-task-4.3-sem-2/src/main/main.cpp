#include "src/TreesContainer/TreesContainer.hpp"


int main()
{
	TreesContainer treesList("src/Resources/trees.txt");
	treesList.print();
	treesList.sortedPrint();
}

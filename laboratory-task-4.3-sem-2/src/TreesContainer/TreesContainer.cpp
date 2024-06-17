#include "TreesContainer.hpp"

TreesContainer::TreesContainer() :
container(0)
{}

TreesContainer::TreesContainer(size_t initSize) :
container(initSize)
{}

TreesContainer::TreesContainer(const TreesContainer& rhs) :
container(rhs.container.size())
{
    container = rhs.container;
}

void checkFile(std::ifstream& fileIn) {
    if(!fileIn.good()) {
        throw std::logic_error("File doesn't exist!");
    }
    if(!fileIn) {
        throw std::logic_error("File is not opened!");
    }
    if(fileIn.peek() == EOF) {
        throw std::logic_error("File is empty!");
    }
}

std::string getWord(std::string line, std::string::size_type& begInd, std::string::size_type& endInd) {
    endInd = line.find_first_of(" ", begInd);
    if(endInd == std::string::npos) {
        endInd = line.length();
    }
    std::string word = line.substr(begInd, endInd - begInd);
    begInd = line.find_first_not_of(" ", endInd);
    return word;
}

TreesContainer::TreesContainer(const char* path)
{
    std::string pathStr(path);
    std::ifstream fileIn(pathStr);
    checkFile(fileIn);

    std::string line;
    while (std::getline(fileIn, line))
    {
        std::string::size_type begInd = 0;
        std::string::size_type endInd = 0;

        begInd = line.find_first_not_of(" ");
        
        std::string initName = getWord(line, begInd, endInd);
        
        size_t initAge = stoull(getWord(line, begInd, endInd));

        std::string initTypeStr = getWord(line, begInd, endInd);
        TreeType initType;
        if(initTypeStr == "deciduous") {
            initType = TreeType::DECIDUOUS;
        } else if(initTypeStr == "coniferuos") {
            initType = TreeType::CONIFERUOS;
        } else {
            throw std::logic_error("File has wrong data!");
        }

        std::string buff = getWord(line, begInd, endInd);
        if (begInd == std::string::npos) {
            size_t initWoodAmount = stoull(buff);
            ForestTree* newForestTree = new ForestTree(initName, initAge, initType, initWoodAmount);
            this->push_back(newForestTree);
        }
        else {
            double initHarvestMass = stod(buff);
            double initAverageLifeTime = stod(getWord(line, begInd, endInd));
            if (begInd != std::string::npos)
            {
                throw std::logic_error("File has wrong data!");
            } 
            FruitTree* newFruitTree = new FruitTree(initName, initAge, initType, initHarvestMass, initAverageLifeTime);
            this->push_back(newFruitTree);
        }
    }
    

}

TreesContainer::~TreesContainer()
{}

void TreesContainer::push_back(Tree* tree)
{
    container.push_back(tree);
}

size_t TreesContainer::deciduousCount() const
{
    size_t counter = 0;
    size_t contSize = container.size();
    for (size_t i = 0; i < contSize; ++i)
    {
        if (container[i]->isDeciduous())
        {
            ++counter;
        }
    }
    return counter;
}

size_t TreesContainer::coniferuosCount() const
{
    return container.size() - this->deciduousCount();
}

size_t TreesContainer::forestCount() const
{
    size_t contSize = container.size();
    size_t counter = 0;
    for (size_t i = 0; i < contSize; ++i)
    {
        if (dynamic_cast<ForestTree*>(container[i])) {
            ++counter;
        }
    }
    return counter;
}

size_t TreesContainer::fruitCount() const
{
    return container.size() - this->forestCount();
}

bool compTrees(Tree* &lhs, Tree* &rhs) {
    if(lhs->name == rhs->name) {
        return lhs->age > rhs->age;
    }
    return lhs->name < rhs->name;
} 

void TreesContainer::print() const
{
    size_t contSize = container.size();
    for (size_t i = 0; i < contSize; ++i)
    {
        container[i]->print();
        std::cout << '\n';
    }
}

void TreesContainer::sortedPrint() const
{
    TreesContainer contCpy(*this);
    std::sort(contCpy.container.begin(), contCpy.container.end(), compTrees);
    contCpy.print();
}


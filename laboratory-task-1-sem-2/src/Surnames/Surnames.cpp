#include "Surnames.hpp"

bool isSur(std::string word)
{
    if (!(word[0] >= 'A' && word[0] <= 'Z')) {
        return false;
    }
    size_t wordSize = word.size();
    for (size_t i = 1; i < wordSize; ++i)
    {
        if (!isalnum(word[i])) {
            return false;
        }
    }
    return true;
    
}

void readSurnames(std::ifstream& in, std::string* &arr, size_t& arrSize)
{
    std::string line;
    std::string delims;
    getline(in, delims);
    while (getline(in, line)) {
        std::string::size_type begInd = line.find_first_not_of(delims);
        std::string::size_type endInd;


        while (begInd != std::string::npos) {
            endInd = line.find_first_of(delims, begInd);
            if (endInd == std::string::npos) {
                endInd = line.length();
            }
            std::string word = line.substr(begInd, endInd - begInd);
            if (isSur(word)) {
                arr[arrSize++] = word;
            }
            begInd = line.find_first_not_of(delims, endInd);
        }
    }
    
}

bool compareSurnames(const std::string& lhs, const std::string& rhs)
{
    size_t minSize = std::min(lhs.size(), rhs.size());
    for (size_t i = 0; i < minSize; ++i)
    {
        if (rhs[i] < lhs[i]) {
            return true;
        }
        if (rhs[i] > lhs[i]) {
            return false;
        }
    }
    return rhs.size() < lhs.size();
}

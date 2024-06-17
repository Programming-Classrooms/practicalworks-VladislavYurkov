#include "Numbers.hpp"

void checkFile(std::ifstream& fileIn)
{
    if (!fileIn.good()) {
		throw std::logic_error("File does not exist");
	}
	if (!fileIn) {
		throw std::logic_error("File is not opened");
	}
	if (fileIn.peek() == EOF) {
		throw std::logic_error("File is empty");
	}
}

bool isInt(std::string word)
{
    if (word[0] != '-' && !isdigit(word[0])) {
        return false;
    }
    size_t wordSize = word.size();
    for (size_t i = 1; i < wordSize; i++)
    {
        if (!isdigit(word[i])) {
            return false;
        }
    }
    return true;
    
}

void readInt(std::ifstream& in, int32_t* &arr, size_t& arrSize)
{
    arrSize = 0;
    std::string line;
    std::string delims;
    getline(in, delims);
    bool noInts = true;
    while (getline(in, line)) {
        std::string::size_type begInd = line.find_first_not_of(delims);
        std::string::size_type endInd;


        while (begInd != std::string::npos) {
            endInd = line.find_first_of(delims, begInd);
            if (endInd == std::string::npos) {
                endInd = line.length();
            }
            std::string word = line.substr(begInd, endInd - begInd);
            if (isInt(word)) {
                arr[arrSize++] = stol(word);
                noInts = false;
            }
            begInd = line.find_first_not_of(delims, endInd);
        }
    }
    if (noInts) {
        throw std::logic_error("There is no integers in file");
    }
}

void paritySort(int32_t* &arr, size_t arrSize)
{
    for (size_t i = 0; i < arrSize - 1; ++i) {
        for (size_t j = 0; j < arrSize - 1 - i; ++j) {
            if ((arr[j] & 1) && !(arr[j + 1] & 1)) {
                std::swap(arr[j],arr[j + 1]);
            }
        }
    }
}


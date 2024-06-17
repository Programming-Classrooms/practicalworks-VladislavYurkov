#ifndef NUMBERS_HPP
#define NUMBERS_HPP
#include <string>
#include <fstream>
#include <iostream>

void checkFile(std::ifstream&);

bool isInt(std::string);

void readInt(std::ifstream&, int32_t* &, size_t&);

template <typename arrType> void printArr(arrType* arr, size_t arrSize)
{
    for (size_t i = 0; i < arrSize; ++i)
    {
        std::cout << arr[i] << '\n';
    }
}

template <typename arrType> void copyArr(arrType* &dest, arrType* src, size_t arrSize)
{
    for (size_t i = 0; i < arrSize; ++i)
    {
        dest[i] = src[i];
    }
    
}

void paritySort(int32_t* &, size_t);

#endif

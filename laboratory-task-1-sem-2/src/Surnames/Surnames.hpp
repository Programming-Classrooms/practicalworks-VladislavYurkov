#ifndef SURNAMES_HPP
#define SURNAMES_HPP
#include <fstream>
#include <iostream>
#include <string.h>
#include <type_traits>

bool isSur(std::string);

void readSurnames(std::ifstream&, std::string* &, size_t&);

bool compareSurnames(const std::string&, const std::string&);

template <typename arrType>
void mergeSort(arrType* & arr, size_t left, size_t right, bool comparator(const arrType&, const arrType&))
{
    if (right != left) {
        if (right == left + 1) {
            if (comparator(arr[left], arr[right])) {
                std::swap(arr[left], arr[right]);
            }
        }
        else {
            size_t middle = left + (right - left) / 2;
            mergeSort(arr, left, middle, comparator);
            mergeSort(arr, middle + 1, right, comparator);
            arrType* buff = new arrType[right - left + 1];
            size_t pLeft = left;
            size_t pRight = middle + 1;
            size_t counter = 0;
            while (!(pLeft == middle + 1 && pRight == right + 1)) {
                if (pLeft == middle + 1) {
                    buff[counter++] = arr[pRight++];
                    continue;
                } 
                if (pRight == right + 1) {

                    buff[counter++] = arr[pLeft++];
                    continue;
                }
                if (comparator(arr[pLeft], arr[pRight])) {
                    buff[counter++] = arr[pRight++];
                }
                else {
                    buff[counter++] = arr[pLeft++];
                }
            }
            for (size_t i = 0; i <= right - left; ++i)
            {
                arr[left + i] = buff[i];
            }
            
        }
    }
}

#endif

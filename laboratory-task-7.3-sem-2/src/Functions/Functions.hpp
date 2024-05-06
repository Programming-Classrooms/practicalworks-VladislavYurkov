#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP
#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <locale>

void readWords(std::wifstream&, std::map<std::wstring, size_t>&);

void printWords(std::map<std::wstring, size_t>);

#endif

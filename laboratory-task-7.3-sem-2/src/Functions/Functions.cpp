#include "Functions.hpp"

std::wstring myToLower(std::wstring word) {
    std::wstring lower(word.begin(), word.end());
    for(size_t i = 0; i < lower.size(); ++i) {
        if (lower[i] >= L'А' && lower[i] <= L'Я') {
            lower[i] = lower[i] - L'А' + L'а';
        }
    }
    return lower;
}

void readWords(std::wifstream& fileIn, std::map<std::wstring, size_t>& wordsList)
{
    std::wstring::size_type begInd;
    std::wstring::size_type endInd;

    std::wstring line;
    std::wstring delims(L" ,.;:\"\'\t!$£%^&*(){}[]@#~/?");
    while (std::getline(fileIn, line)) {
        begInd = line.find_first_not_of(delims);

        while (begInd != std::wstring::npos) {
            endInd = line.find_first_of(delims, begInd);
            if(endInd == std::wstring::npos) {
                endInd = line.length();
            }

            std::wstring word = line.substr(begInd, endInd - begInd);
        
            ++wordsList[myToLower(word)];

            begInd = line.find_first_not_of(delims, endInd);
        }
    }
}

void printWords(std::map<std::wstring, size_t> wordsList)
{
    for(auto item : wordsList) {
        std::wcout << item.first << ' ' << item.second << '\n';
    }
}

#include "Functions.hpp"

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

            std::transform(word.cbegin(), word.cend(), word.begin(), towlower);

            ++wordsList[word];

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

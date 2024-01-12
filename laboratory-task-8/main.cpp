/*
    При написании программ использовать строки string.

    Словом, входящим в состав строки, назовём непрерывную
    последовательность символов, ограниченную символами–разделителями,
    началом и концом строки. Символы, относящиеся к разделителям, определяет
    пользователь, если иное не сказано в условии задачи. Если решить задачу
    невозможно, программа должна выдать соответствующее сообщение.

    15. Дана строка, слова в которой состоят из букв латинского алфавита и
    десятичных цифр. Остальные символы – разделители между словами.
    Получить новую строку, выполняя в заданной строке замены по следующему
    правилу. Все слова, имеющие длину менее 5 символов и состоящие только из
    цифр, заменяются словами, получаемыми из исходных путём дописывания
    ведущих нулей до получения длины слова, равной 5. Все слова, состоящие
    только из букв, заменяются словами, записанными в обратном порядке.
    Слова в новой строке должны разделяться ровно одним пробелом.
*/


#include <iostream>
#include <string>
#include <algorithm>


std::string findDelims(std::string line, size_t lineLength)
{
    std::string delims = "";
    for (size_t i = 0; i < lineLength; ++i) {
        if (!isdigit(line[i]) && !isalpha(line[i])) {
            if (delims.find_first_of(line[i]) == std::string::npos) {
                delims.push_back(line[i]);
            }
        }
    }
    return delims;
}

bool isNumberLessThanFiveSymbols(std::string word) {
    size_t wordLength = word.length();
    if(wordLength > 4) {
        return false;
    }
    for (size_t i = 0; i < wordLength; ++i) {
        if (!isdigit(word[i])) {
            return false;
        }
    }
    return true;
}

std::string tranformNumber(std::string word)
{
    std::string zeroLine = "0";
    while (word.length() < 5) {
        zeroLine.append(word);
        word = zeroLine;
        zeroLine = "0";
    }
    return word;
}

bool isOnlyAlphaWord(std::string word)
{
    size_t wordLength = word.length();
    for (size_t i = 0; i < wordLength; ++i) {
        if (!isalpha(word[i])) {
            return false;
        }
    }
    return true;
}

std::string reverseWord(std::string word)
{
    std::string reversedWord = word;
    std::reverse(reversedWord.begin(), reversedWord.end());
    return reversedWord;
}

std::string transformLine(std::string line, size_t lineLength, std::string delims)
{
    std::string newLine = "";

    size_t begInd = 0;
    size_t endInd = 0;

    begInd = line.find_first_not_of(delims);

    while (begInd != std::string::npos)
    {
        endInd = line.find_first_of(delims, begInd);

        std::string word = line.substr(begInd, endInd - begInd);
        
        std::string transformedWord = word;

        if (isNumberLessThanFiveSymbols(word)) {
            transformedWord = tranformNumber(word);
        }

        if (isOnlyAlphaWord(word)) {
            transformedWord = reverseWord(word);
        }

        begInd = line.find_first_not_of(delims, endInd);

        newLine.append(transformedWord);
        if (begInd != std::string::npos) {
            newLine.append(" ");
        }
    }
    return newLine;
}


int main()
{
    try {
        std::string line = "";

        std::cout << "Input string:\n";
        std::getline(std::cin, line);
        
        size_t lineLength = line.length();
        if (!lineLength) {
            throw std::runtime_error("Line is empty");
        }

        std::string delims = findDelims(line, lineLength);
        
        std::cout << transformLine(line, lineLength, delims);

    }
    catch (std::runtime_error e) {
        std::cerr << e.what() << '\n';
    }
    
    return 0;
}

/*
    15. Реализовать механизм скалярного умножения двух векторов с  практически неограниченной размерностью. 
    Большинство координат обоих  векторов равно нулю. Остальные координаты – данные типа int.  
    Гарантируется, что результат помещается в тип long. 
    Предусмотреть  организацию ввода-вывода как через консоль, так и через текстовые файлы. 

*/


#include <iostream>
#include <fstream>
#include <cstdio>
#include <vector>


bool inputFromFile(std::string inputAndOutputMethod) {
    if (inputAndOutputMethod != "1" && inputAndOutputMethod != "2") {
        throw std::runtime_error("Wrong input method");
    }
    return inputAndOutputMethod == "1";
}

void checkFile(std::ifstream& fileIn)
{
    if (fileIn.bad()) {
        throw std::runtime_error("File does not exist");
    }
    if (!fileIn) {
        throw std::runtime_error("File is not opened");
    }
    if (fileIn.peek() == EOF) {
        throw std::runtime_error("File is empty");
    }
}

bool isNumber (std::string word)
{
    if (word[0] != '-' && !isdigit(word[0])) {
        return false;
    }

    size_t wordLen = word.length();
    for (size_t i = 0; i < wordLen; ++i) {
        if (!isdigit(word[i])) {
            return false;
        }
    }

    return true;
}

std::vector<int> getVector()
{
    std::vector<int> someVector;

    std::string line;
    std::getline(std::cin, line);

    std::string::size_type begInd = 0;
    std::string::size_type endInd = 0;

    begInd = line.find_first_not_of(' ');

    while (begInd != std::string::npos) {
        endInd = line.find_first_of(' ', begInd);
        if(endInd == std::string::npos) {
            endInd = line.length();
        }

        std::string num = line.substr(begInd, endInd - begInd);

        if (!isNumber(num)) {
            throw std::runtime_error("Coordinates is not only numbers");
        }
        someVector.push_back(std::stoi(num));

        begInd = line.find_first_not_of(' ', endInd);
    }
    return someVector;
}

size_t multiplyVectors(std::vector<int> firstVector, std::vector<int> secondVector)
{
    size_t scalarMulti = 0;

    size_t vectorsSize = firstVector.size();
    for (size_t i = 0; i < vectorsSize; ++i) {
        scalarMulti += firstVector[i] * secondVector[i];
    }

    return scalarMulti;
}

int main()
{
    try {
        std::string inputAndOutputMethod;

        std::cout << "Choose input/output method\n";
        std::cout << "1.From/to file\n";
        std::cout << "2.From/to console\n";
        std::getline(std::cin, inputAndOutputMethod);

        bool workWithFiles = inputFromFile(inputAndOutputMethod);

        if (workWithFiles) {
            std::ifstream fileIn("input.txt");
            checkFile(fileIn);
            fileIn.close();

            std::ofstream fileOut("output.txt");
            fileIn.close();

            freopen("input.txt", "r", stdin);
            freopen("output.txt", "w", stdout);
            //Примечание:
            //Я оставил такие пути, однако, если вы работаете в VS Code, вам требуется заменить их на ../input.txt и ../output.txt
        }
        if (!workWithFiles) {
            std::cout << "Input first vector coordinates in one line\n";
        }
        std::vector<int> firstVector = getVector();
        
        if (!workWithFiles) {
            std::cout << "Input second vector coordinates in one line\n";
        }
        std::vector<int> secondVector = getVector();

        if (firstVector.size() != secondVector.size()) {
            throw std::runtime_error("Vectors have different dimensions");
        }

        long scalarMulti = multiplyVectors(firstVector, secondVector);

        std::cout << "Scalar multiplication = " << scalarMulti << '\n';
    }
    catch (std::runtime_error e) {
        std::cerr << e.what() << '\n';
    }
    
    return 0;
}

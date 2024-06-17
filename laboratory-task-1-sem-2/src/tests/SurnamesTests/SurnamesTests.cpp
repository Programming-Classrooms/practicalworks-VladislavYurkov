#include <stdexcept>
#include <gtest/gtest.h>
#include <fstream>
#include "src/Surnames/Surnames.hpp"

bool ascendingInt(const int& a, const int& b) {
    return a > b;
}

bool ascendingDouble(const double& a, const double& b) {
    return a > b;
}

bool ascendingString(const std::string& a, const std::string& b) {
    return a > b;
}

TEST(SURNAMES_TEST, MERGE_SORT) {
    int32_t* arrInt = new int32_t[5];
    arrInt[0] = 5;
    arrInt[1] = 2;
    arrInt[2] = 8;
    arrInt[3] = 1; 
    arrInt[4] = 4;
    mergeSort(arrInt, 0, 4, ascendingInt);
    double* arrDouble = new double[5];
    arrDouble[0] = 5.0;
    arrDouble[1] = 2.0;
    arrDouble[2] = 8.0;
    arrDouble[3] = 1.0; 
    arrDouble[4] = 4.0;
    mergeSort(arrDouble, 0, 4, ascendingDouble);
    std::string* arrString = new std::string[5];
    arrString[0] = "Las";
    arrString[1] = "Ksa";
    arrString[2] = "Ryd";
    arrString[3] = "Has"; 
    arrString[4] = "Jam";
    mergeSort(arrString, 0, 4, ascendingString);

    for (size_t i = 0; i < 4; ++i) {
        EXPECT_LE(arrInt[i], arrInt[i + 1]);
        EXPECT_LE(arrDouble[i], arrDouble[i + 1]);
        EXPECT_LE(arrString[i], arrString[i + 1]);
    }
}

TEST(SURNAMES_TEST, IS_SUR) {
    EXPECT_TRUE(isSur("Smith"));
    EXPECT_FALSE(isSur("john"));
    EXPECT_FALSE(isSur("123"));
    EXPECT_FALSE(isSur(""));
}

TEST(SURNAMES_TEST, READ_SURNAMES) {
    std::ofstream testFile("src/tests/SurnamesTests/ReadSurnames/test_read_surnames.txt");
    testFile << " \nSmith Doe Johnson" << std::endl;
    testFile.close();
    std::ifstream file("src/tests/SurnamesTests/ReadSurnames/test_read_surnames.txt");
    std::string* arr = new std::string[3];
    size_t arrSize = 0;
    EXPECT_NO_THROW(readSurnames(file, arr, arrSize));
    EXPECT_EQ(arrSize, 3);
    EXPECT_EQ(arr[0], "Smith");
    EXPECT_EQ(arr[1], "Doe");
    EXPECT_EQ(arr[2], "Johnson");
    delete[] arr;
    file.close();
}

TEST(SURNAMES_TEST, COMPARE_SURNAMES) {
    EXPECT_TRUE(compareSurnames("Smith", "Doe"));
    EXPECT_FALSE(compareSurnames("Doe", "Smith"));
    EXPECT_TRUE(compareSurnames("Johnson", "Doe"));
    EXPECT_FALSE(compareSurnames("Doe", "Johnson"));
    EXPECT_TRUE(compareSurnames("Doeb", "Doe"));
    EXPECT_FALSE(compareSurnames("Doe", "Doeb"));
}

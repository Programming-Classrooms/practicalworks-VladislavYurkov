#include <stdexcept>
#include <gtest/gtest.h>
#include "src/Numbers/Numbers.hpp"
#include <fstream>

std::string createPath(const char* relatedPath)
{
    std::string path("src/tests/NumbersTests/");
    path.append(relatedPath);
    return path;
}

TEST(NUMBERS_TEST, CHECK_FILE)
{
    std::ifstream normal(createPath("CheckFile/normal.txt"));
    std::ifstream notExist(createPath("CheckFile/notExists.txt"));
    std::ifstream notOpened(createPath("CheckFile/notOpened.txt"));
    notOpened.close();
    std::ifstream empty(createPath("CheckFile/empty.txt"));

    EXPECT_NO_THROW(checkFile(normal));
    EXPECT_THROW(checkFile(notExist), std::logic_error);
    EXPECT_THROW(checkFile(notOpened), std::logic_error);
    EXPECT_THROW(checkFile(empty), std::logic_error);
}

TEST(NUMBERS_TEST, IS_INT)
{
    std::string five("5");
    std::string minusFive("-5");
    std::string bigInt("1234567890");
    std::string notInt("2n3");
    std::string word("five");

    EXPECT_TRUE(isInt(five));
    EXPECT_TRUE(isInt(minusFive));
    EXPECT_TRUE(isInt(bigInt));
    EXPECT_FALSE(isInt(notInt));
    EXPECT_FALSE(isInt(word));
}

TEST(NUMBERS_TEST, READ_INT)
{
    std::ifstream posInt(createPath("ReadInt/posInt.txt"));
    std::ifstream negInt(createPath("ReadInt/negInt.txt"));
    std::ifstream diffInt(createPath("ReadInt/diffInt.txt"));
    std::ifstream notInt(createPath("ReadInt/notInt.txt"));

    size_t posIntSize = 10;
    int32_t* posIntArr = new int32_t[posIntSize];
    size_t negIntSize = 10;
    int32_t* negIntArr = new int32_t[negIntSize];
    size_t diffIntSize = 10;
    int32_t* diffIntArr = new int32_t[diffIntSize];
    size_t notIntSize = 10;
    int32_t* notIntArr;


    readInt(posInt, posIntArr, posIntSize);
    readInt(negInt, negIntArr, negIntSize);
    readInt(diffInt, diffIntArr, diffIntSize);
    EXPECT_THROW(readInt(notInt, notIntArr, notIntSize), std::logic_error);

    size_t expectPosIntSize = 6;
    int32_t* expectPosIntArr = new int32_t[expectPosIntSize];
    expectPosIntArr[0] = 34;
    expectPosIntArr[1] = 56;
    expectPosIntArr[2] = 8;
    expectPosIntArr[3] = 4324;
    expectPosIntArr[4] = 13;
    expectPosIntArr[5] = 123;
    size_t expectNegIntSize = 6;
    int32_t* expectNegIntArr = new int32_t[expectNegIntSize];
    expectNegIntArr[0] = -1;
    expectNegIntArr[1] = -1;
    expectNegIntArr[2] = -2;
    expectNegIntArr[3] = -4;
    expectNegIntArr[4] = -3;
    expectNegIntArr[5] = -1;
    size_t expectDiffIntSize = 5;
    int32_t* expectDiffIntArr = new int32_t[expectDiffIntSize];
    expectDiffIntArr[0] = 3;
    expectDiffIntArr[1] = -3;
    expectDiffIntArr[2] = 7;
    expectDiffIntArr[3] = 8;
    expectDiffIntArr[4] = -5;

    EXPECT_EQ(posIntSize, expectPosIntSize);
    EXPECT_EQ(negIntSize, expectNegIntSize);
    EXPECT_EQ(diffIntSize, expectDiffIntSize);

    for (size_t i = 0; i < posIntSize; ++i)
    {
        EXPECT_EQ(posIntArr[i], expectPosIntArr[i]);
    }
    for (size_t i = 0; i < negIntSize; ++i)
    {
        EXPECT_EQ(negIntArr[i], expectNegIntArr[i]);
    }
    for (size_t i = 0; i < diffIntSize; ++i)
    {
        EXPECT_EQ(diffIntArr[i], expectDiffIntArr[i]);
    }
    
}

TEST(NUMBERS_TEST, PARITY_SORT) {
    size_t arrSize = 5;
    int32_t* arr = new int32_t[arrSize];
    for (size_t i = 0; i < arrSize; ++i)
    {
        arr[i] = i + 1;
    }
    
    paritySort(arr, arrSize);
    EXPECT_EQ(arr[0], 2);
    EXPECT_EQ(arr[1], 4);    
    EXPECT_EQ(arr[2], 1);   
    EXPECT_EQ(arr[3], 3);
    EXPECT_EQ(arr[4], 5);
}

TEST(NUMBERS_TEST, COPY_ARR)
{
    int32_t* srcInt = new int32_t[5];
    srcInt[0] = 1;
    srcInt[1] = 2;
    srcInt[2] = 3;
    srcInt[3] = 4;
    srcInt[4] = 5;
    int32_t* destInt = new int32_t[5];

    double* srcDouble = new double[5];
    srcDouble[0] = 0.5;
    srcDouble[1] = 1.0;
    srcDouble[2] = 1.5;
    srcDouble[3] = 2.0;
    srcDouble[4] = 2.5;
    double* destDouble = new double[5];

    std::string* srcString = new std::string[5];
    srcString[0] = "One";
    srcString[1] = "Two";
    srcString[2] = "Three";
    srcString[3] = "Four";
    srcString[4] = "Five";
    std::string* destString = new std::string[5];

    copyArr(destInt, srcInt, 5);
    copyArr(destDouble, srcDouble, 5);
    copyArr(destString, srcString, 5);



    for (size_t i = 0; i < 5; ++i)
    {
        EXPECT_EQ(destInt[i], srcInt[i]);
        EXPECT_DOUBLE_EQ(destDouble[i], srcDouble[i]);
        EXPECT_STREQ(destString[i].c_str(), srcString[i].c_str());
    }
    
}

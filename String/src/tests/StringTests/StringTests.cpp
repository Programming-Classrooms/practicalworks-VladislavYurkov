#include <stdexcept>
#include <gtest/gtest.h>
#include "src/String/String.hpp"

TEST(CONSTRUCTOR_TEST, DEFAULT_CONSTRUCTOR)
{
    String obj;
    EXPECT_EQ(obj.getSize(), 0);
    EXPECT_STREQ(obj.c_str(), "");
}

TEST(CONSTRUCTOR_TEST, CHAR_POINTER_CONSTRUCTOR)
{
    String obj("Hello, world!");
    EXPECT_EQ(obj.getSize(), 13);
    EXPECT_STREQ(obj.c_str(), "Hello, world!");
}

TEST(CONSTRUCTOR_TEST, COPYING_CONSTRUCTOR)
{
    String obj("Hello");
    String objCpy;
    EXPECT_EQ(obj.getSize(), 5);
    EXPECT_STREQ(obj.c_str(), "Hello");
}

TEST(CONSTRUCTOR_TEST, MOVING_CONSTRUCTOR)
{
    String obj("String");
    String newObj(std::move(obj));
    EXPECT_EQ(obj.getSize(), 0);

}

TEST(CHANGE_STRING_TEST, PUSH_BACK)
{
    String obj("Hello, world");
    obj.push_back('!');
    EXPECT_STREQ(obj.c_str(), "Hello, world!");
}

TEST(CHANGE_STRING_TEST, APPEND_CHAR_POINTER)
{
    String obj("No ");
    obj.append("idea");
    EXPECT_STREQ(obj.c_str(), "No idea");
}

TEST(CHANGE_STRING_TEST, APPEND_STRING)
{
    String obj("Any ");
    String objSec("text");
    obj.append(objSec);
    EXPECT_STREQ(obj.c_str(), "Any text");
}

TEST(CHANGE_STRING_TEST, INSERT_CHAR_POINTER)
{
    String obj("Many ");
    obj.insert("stringscpy", 7);
    EXPECT_STREQ(obj.c_str(), "Many strings");
    EXPECT_ANY_THROW(obj.insert("str", 5));
}

TEST(CHANGE_STRING_TEST, INSERT_STRING)
{
    String obj("No ");
    String objSec("ideas");
    obj.insert(objSec, 4);
    EXPECT_STREQ(obj.c_str(), "No idea");
    EXPECT_ANY_THROW(obj.insert(objSec, 21));
}

TEST(CHANGE_STRING_TEST, REPLACE_WITH_CHAR_POINTER)
{
    String obj("Hello, world!");
    obj.replace("No",2);
    EXPECT_STREQ(obj.c_str(), "Nollo, world!");
    obj.replace("?", 1, 12);
    EXPECT_STREQ(obj.c_str(), "Nollo, world?");
    EXPECT_ANY_THROW(obj.replace("GUI", 12));
    EXPECT_ANY_THROW(obj.replace("NO GUI", 3, 20));
}

TEST(CHANGE_STRING_TEST, REPLACE_WITH_STRING)
{
    String obj("NOOOOOOO");
    String objSec("YESSSS");
    obj.replace(objSec, 3);
    EXPECT_STREQ(obj.c_str(), "YESOOOOO");
    obj.replace(objSec, 3, 3);
    EXPECT_STREQ(obj.c_str(), "YESYESOO");
    EXPECT_ANY_THROW(obj.replace(objSec, 12));
    EXPECT_ANY_THROW(obj.replace(objSec, 1, 12));
}

TEST(CHANGE_STRING_TEST, CLEAR)
{
    String obj("obj");
    obj.clear();
    EXPECT_EQ(obj.getSize(), 0);
    EXPECT_STREQ(obj.c_str(), "");
}

TEST(GETTERS_TEST, EMPTY)
{
    String obj;
    String fullObj("FULL");
    EXPECT_TRUE(obj.empty());
    EXPECT_FALSE(fullObj.empty());
}

TEST(GETTERS_TEST, C_STR)
{
    String obj("String");
    EXPECT_STREQ(obj.c_str(), "String");
}

TEST(GETTERS_TEST, GET_SIZE)
{
    String obj("Another");
    EXPECT_EQ(obj.getSize(), 7);
}

TEST(GETTERS_TEST, SUBSTR)
{
    String obj("DuckOfDucks");
    EXPECT_STREQ(obj.substr(4).c_str(), "Duck");
    EXPECT_STREQ(obj.substr(4, 6).c_str(), "Duck");
    EXPECT_ANY_THROW(obj.substr(20));
}

TEST(OPERATORS_TEST, PLUS_STRING)
{
    String first("First");
    String second("Second");
    String cat(first + second);
    EXPECT_STREQ(cat.c_str(), "FirstSecond");
}

TEST(OPERATORS_TEST, ASSIGMENT_STRING)
{
    String obj("Data");
    String objCpy;
    objCpy = obj;
    EXPECT_STREQ(objCpy.c_str(), "Data");
}

TEST(OPERATORS_TEST, SQUARE_BRACKETS)
{
    String obj("No Data");
    EXPECT_EQ(obj[3], 'D');
    EXPECT_ANY_THROW(obj[10]);
}

TEST(OPERATORS_TEST, COMPARISON_OPERATORS)
{
    String obj("equal");
    String eq("equal");
    String notEq("not equal");
    String less("abc");
    EXPECT_TRUE(obj == eq);
    EXPECT_TRUE(obj != notEq);
    EXPECT_TRUE(obj >= eq);
    EXPECT_TRUE(obj <= eq);
    EXPECT_TRUE(obj > less);
    EXPECT_TRUE(obj < notEq);
    EXPECT_TRUE(obj >= less);
    EXPECT_TRUE(obj <= notEq);
}

TEST(CONVERSION_OPERATORS_TEST, TO_STRING)
{
    String obj("Hello");
    EXPECT_STREQ(((std::string) obj).c_str(), "Hello");
}

TEST(CONVERSION_OPERATORS_TEST, TO_INT64_T)
{
    String obj("Nan");
    String chizlo("23");
    EXPECT_EQ((int64_t) chizlo, 23);
    EXPECT_ANY_THROW((int64_t) obj);
}

TEST(CONVERSION_OPERATORS, TO_DOUBLE)
{
    String obj("String");
    String chizlo("23");
    String point("45.34");
    EXPECT_DOUBLE_EQ((double) chizlo, 23.0);
    EXPECT_DOUBLE_EQ((double) point, 45.34);
    EXPECT_ANY_THROW((double) obj);
}

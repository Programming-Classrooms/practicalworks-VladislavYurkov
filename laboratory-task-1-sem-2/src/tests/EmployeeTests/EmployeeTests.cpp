#include <stdexcept>
#include <gtest/gtest.h>
#include "src/Employee/Employee.hpp"

TEST(EMPLOYEE_TEST, IS_POS_DIGIT)
{
    EXPECT_TRUE(isPosDigit(5));
    EXPECT_TRUE(isPosDigit(0));
    EXPECT_TRUE(isPosDigit(9));
    EXPECT_FALSE(isPosDigit(-5));
    EXPECT_FALSE(isPosDigit(-1));
}

TEST(EMPLOYEE_TEST, COMPARE_EMPLOYEES)
{
    Employee employee1 = {"Smith", 2};
    Employee employee2 = {"Smith", 5};
    EXPECT_TRUE(compareEmployees(employee1, employee2));
    
    Employee employee3 = {"Smith", 3};
    Employee employee4 = {"Johnson", 3};
    EXPECT_TRUE(compareEmployees(employee3, employee4));

    Employee employee5 = {"Johnson", 4};
    Employee employee6 = {"Johnson", 4};
    EXPECT_FALSE(compareEmployees(employee5, employee6));
}

//
// Created by cornelius on 4/11/19.
//

#include "Operation.h"
#include <gtest/gtest.h>

TEST(test_Add, ctor)
{
    Add testAdd;
    
    EXPECT_EQ(testAdd.getResult(), 0.0);
}

TEST(test_Add, get_type)
{
    Add testAdd;
    
    EXPECT_EQ(testAdd.getType(), operationType::ADD);
}

TEST(test_Add, set_operands_zero_zero)
{
    Add testAdd;
    double testFirst, testSecond;
    
    // pairs of operands to test:
    //      1)  0.0, 0.0
    //      2)  0.0, (+)
    //      3)  0.0, (-)
    //      4)  (+), 0.0
    //      5)  (+), (+)
    //      6)  (+), (-)
    //      7)  (-), 0.0
    //      8)  (-), (+)
    //      9)  (-), (-)
    //
    //      ^ each non-zero item should be tested with an integer value and
    //              a value with a decimal.
    
    //      1)  0.0, 0.0
    
    testFirst = 0.0;
    testSecond = 0.0;
    testAdd.setOperands(testFirst, testSecond);
    EXPECT_EQ(testAdd.getResult(), testFirst + testSecond);
}

TEST(test_Add, set_operands_zero_pos)
{
    Add testAdd;
    double testFirst, testSecond;
    
    testFirst = 0.0;
    testSecond = 5;
    testAdd.setOperands(testFirst, testSecond);
    EXPECT_EQ(testAdd.getResult(), testFirst + testSecond);
    
    testFirst = 0.0;
    testSecond = 12.6;
    testAdd.setOperands(testFirst, testSecond);
    EXPECT_EQ(testAdd.getResult(), testFirst + testSecond);
}

TEST(test_Add, set_operands_zero_neg)
{
    Add testAdd;
    double testFirst, testSecond;
    
    testFirst = 0.0;
    testSecond = -5;
    testAdd.setOperands(testFirst, testSecond);
    EXPECT_EQ(testAdd.getResult(), testFirst + testSecond);
    
    testFirst = 0.0;
    testSecond = -12.6;
    testAdd.setOperands(testFirst, testSecond);
    EXPECT_EQ(testAdd.getResult(), testFirst + testSecond);
}

TEST(test_Add, set_operands_pos_zero)
{
    Add testAdd;
    double testFirst, testSecond;
    
    testFirst = 10;
    testSecond = 0.0;
    testAdd.setOperands(testFirst, testSecond);
    EXPECT_EQ(testAdd.getResult(), testFirst + testSecond);
    
    testFirst = 10.237;
    testSecond = 0.0;
    testAdd.setOperands(testFirst, testSecond);
    EXPECT_EQ(testAdd.getResult(), testFirst + testSecond);
}

TEST(test_Add, set_operands_pos_pos)
{
    Add testAdd;
    double testFirst, testSecond;
    
    testFirst = 10;
    testSecond = 24;
    testAdd.setOperands(testFirst, testSecond);
    EXPECT_EQ(testAdd.getResult(), testFirst + testSecond);
    
    testFirst = 10.237;
    testSecond = 55.5;
    testAdd.setOperands(testFirst, testSecond);
    EXPECT_EQ(testAdd.getResult(), testFirst + testSecond);
}

TEST(test_Add, set_operands_pos_neg)
{
    Add testAdd;
    double testFirst, testSecond;
    
    testFirst = 10;
    testSecond = -24;
    testAdd.setOperands(testFirst, testSecond);
    EXPECT_EQ(testAdd.getResult(), testFirst + testSecond);
    
    testFirst = 10.237;
    testSecond = -55.5;
    testAdd.setOperands(testFirst, testSecond);
    EXPECT_EQ(testAdd.getResult(), testFirst + testSecond);
}

TEST(test_Add, set_operands_neg_zero)
{
    Add testAdd;
    double testFirst, testSecond;
    
    testFirst = -10;
    testSecond = 0;
    testAdd.setOperands(testFirst, testSecond);
    EXPECT_EQ(testAdd.getResult(), testFirst + testSecond);
    
    testFirst = -10.237;
    testSecond = 0.0;
    testAdd.setOperands(testFirst, testSecond);
    EXPECT_EQ(testAdd.getResult(), testFirst + testSecond);
}

TEST(test_Add, set_operands_neg_pos)
{
    Add testAdd;
    double testFirst, testSecond;
    
    testFirst = -10;
    testSecond = 24;
    testAdd.setOperands(testFirst, testSecond);
    EXPECT_EQ(testAdd.getResult(), testFirst + testSecond);
    
    testFirst = -10.237;
    testSecond = 55.5;
    testAdd.setOperands(testFirst, testSecond);
    EXPECT_EQ(testAdd.getResult(), testFirst + testSecond);
}

TEST(test_Add, set_operands_neg_neg)
{
    Add testAdd;
    double testFirst, testSecond;
    
    testFirst = -10;
    testSecond = -24;
    testAdd.setOperands(testFirst, testSecond);
    EXPECT_EQ(testAdd.getResult(), testFirst + testSecond);
    
    testFirst = -10.237;
    testSecond = -55.5;
    testAdd.setOperands(testFirst, testSecond);
    EXPECT_EQ(testAdd.getResult(), testFirst + testSecond);
}

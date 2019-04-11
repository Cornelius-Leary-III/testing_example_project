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

TEST(test_Add, set_operands)
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
    
    //      2)  0.0, (+)
    
    testFirst = 0.0;
    testSecond = 5;
    testAdd.setOperands(testFirst, testSecond);
    EXPECT_EQ(testAdd.getResult(), testFirst + testSecond);
    
    testFirst = 0.0;
    testSecond = 12.6;
    testAdd.setOperands(testFirst, testSecond);
    EXPECT_EQ(testAdd.getResult(), testFirst + testSecond);
    
    //      3)  0.0, (-)
    
    testFirst = 0.0;
    testSecond = -5;
    testAdd.setOperands(testFirst, testSecond);
    EXPECT_EQ(testAdd.getResult(), testFirst + testSecond);
    
    testFirst = 0.0;
    testSecond = -12.6;
    testAdd.setOperands(testFirst, testSecond);
    EXPECT_EQ(testAdd.getResult(), testFirst + testSecond);
    
    //      4)  (+), 0.0
    
    testFirst = 10;
    testSecond = 0.0;
    testAdd.setOperands(testFirst, testSecond);
    EXPECT_EQ(testAdd.getResult(), testFirst + testSecond);
    
    testFirst = 10.237;
    testSecond = 0.0;
    testAdd.setOperands(testFirst, testSecond);
    EXPECT_EQ(testAdd.getResult(), testFirst + testSecond);
    
    //      5)  (+), (+)
    
    testFirst = 10;
    testSecond = 24;
    testAdd.setOperands(testFirst, testSecond);
    EXPECT_EQ(testAdd.getResult(), testFirst + testSecond);
    
    testFirst = 10.237;
    testSecond = 55.5;
    testAdd.setOperands(testFirst, testSecond);
    EXPECT_EQ(testAdd.getResult(), testFirst + testSecond);
    
    //      6)  (+), (-)
    
    testFirst = 10;
    testSecond = -24;
    testAdd.setOperands(testFirst, testSecond);
    EXPECT_EQ(testAdd.getResult(), testFirst + testSecond);
    
    testFirst = 10.237;
    testSecond = -55.5;
    testAdd.setOperands(testFirst, testSecond);
    EXPECT_EQ(testAdd.getResult(), testFirst + testSecond);
    
    //      7)  (-), 0.0
    
    testFirst = -10;
    testSecond = 0.0;
    testAdd.setOperands(testFirst, testSecond);
    EXPECT_EQ(testAdd.getResult(), testFirst + testSecond);
    
    testFirst = -10.237;
    testSecond = 0.0;
    testAdd.setOperands(testFirst, testSecond);
    EXPECT_EQ(testAdd.getResult(), testFirst + testSecond);
    
    //      8)  (-), (+)
    
    testFirst = -10;
    testSecond = 24;
    testAdd.setOperands(testFirst, testSecond);
    EXPECT_EQ(testAdd.getResult(), testFirst + testSecond);
    
    testFirst = -10.237;
    testSecond = 55.5;
    testAdd.setOperands(testFirst, testSecond);
    EXPECT_EQ(testAdd.getResult(), testFirst + testSecond);
    
    //      9)  (-), (-)
    
    testFirst = -10;
    testSecond = -24;
    testAdd.setOperands(testFirst, testSecond);
    EXPECT_EQ(testAdd.getResult(), testFirst + testSecond);
    
    testFirst = -10.237;
    testSecond = -55.5;
    testAdd.setOperands(testFirst, testSecond);
    EXPECT_EQ(testAdd.getResult(), testFirst + testSecond);
}


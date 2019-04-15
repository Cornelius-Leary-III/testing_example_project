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

TEST(test_Add, compute_zero_zero)
{
    Add testAdd;
    
    
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
    
    double testFirst = 0.0;
    double testSecond = 0.0;
    testAdd.setOperands(testFirst, testSecond);
    EXPECT_EQ(testAdd.getResult(), testFirst + testSecond);
}

TEST(test_Add, compute_zero_pos)
{
    Add testAdd;
    
    double testFirst = 0.0;
    double testSecond = 5;
    testAdd.setOperands(testFirst, testSecond);
    EXPECT_EQ(testAdd.getResult(), testFirst + testSecond);
    
    testFirst = 0.0;
    testSecond = 12.6;
    testAdd.setOperands(testFirst, testSecond);
    EXPECT_EQ(testAdd.getResult(), testFirst + testSecond);
}

TEST(test_Add, compute_zero_neg)
{
    Add testAdd;
    
    double testFirst = 0.0;
    double testSecond = -5;
    testAdd.setOperands(testFirst, testSecond);
    EXPECT_EQ(testAdd.getResult(), testFirst + testSecond);
    
    testFirst = 0.0;
    testSecond = -12.6;
    testAdd.setOperands(testFirst, testSecond);
    EXPECT_EQ(testAdd.getResult(), testFirst + testSecond);
}

TEST(test_Add, compute_pos_zero)
{
    Add testAdd;
    
    double testFirst = 10;
    double testSecond = 0.0;
    testAdd.setOperands(testFirst, testSecond);
    EXPECT_EQ(testAdd.getResult(), testFirst + testSecond);
    
    testFirst = 10.237;
    testSecond = 0.0;
    testAdd.setOperands(testFirst, testSecond);
    EXPECT_EQ(testAdd.getResult(), testFirst + testSecond);
}

TEST(test_Add, compute_pos_pos)
{
    Add testAdd;
    
    double testFirst = 10;
    double testSecond = 24;
    testAdd.setOperands(testFirst, testSecond);
    EXPECT_EQ(testAdd.getResult(), testFirst + testSecond);
    
    testFirst = 10.237;
    testSecond = 55.5;
    testAdd.setOperands(testFirst, testSecond);
    EXPECT_EQ(testAdd.getResult(), testFirst + testSecond);
}

TEST(test_Add, compute_pos_neg)
{
    Add testAdd;
    
    double testFirst = 10;
    double testSecond = -24;
    testAdd.setOperands(testFirst, testSecond);
    EXPECT_EQ(testAdd.getResult(), testFirst + testSecond);
    
    testFirst = 10.237;
    testSecond = -55.5;
    testAdd.setOperands(testFirst, testSecond);
    EXPECT_EQ(testAdd.getResult(), testFirst + testSecond);
}

TEST(test_Add, compute_neg_zero)
{
    Add testAdd;
    
    double testFirst = -10;
    double testSecond = 0;
    testAdd.setOperands(testFirst, testSecond);
    EXPECT_EQ(testAdd.getResult(), testFirst + testSecond);
    
    testFirst = -10.237;
    testSecond = 0.0;
    testAdd.setOperands(testFirst, testSecond);
    EXPECT_EQ(testAdd.getResult(), testFirst + testSecond);
}

TEST(test_Add, compute_neg_pos)
{
    Add testAdd;
    
    double testFirst = -10;
    double testSecond = 24;
    testAdd.setOperands(testFirst, testSecond);
    EXPECT_EQ(testAdd.getResult(), testFirst + testSecond);
    
    testFirst = -10.237;
    testSecond = 55.5;
    testAdd.setOperands(testFirst, testSecond);
    EXPECT_EQ(testAdd.getResult(), testFirst + testSecond);
}

TEST(test_Add, compute_neg_neg)
{
    Add testAdd;
    
    double testFirst = -10;
    double testSecond = -24;
    testAdd.setOperands(testFirst, testSecond);
    EXPECT_EQ(testAdd.getResult(), testFirst + testSecond);
    
    testFirst = -10.237;
    testSecond = -55.5;
    testAdd.setOperands(testFirst, testSecond);
    EXPECT_EQ(testAdd.getResult(), testFirst + testSecond);
}

TEST(test_Subtract, ctor)
{
    Subtract testSubtract;
    
    EXPECT_EQ(testSubtract.getResult(), 0.0);
}

TEST(test_Subtract, get_type)
{
    Subtract testSubtract;
    
    EXPECT_EQ(testSubtract.getType(), operationType::SUBTRACT);
}

TEST(test_Subtract, compute_zero_zero)
{
    Subtract testSubtract;
    
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
    
    double testFirst = 0.0;
    double testSecond = 0.0;
    testSubtract.setOperands(testFirst, testSecond);
    EXPECT_EQ(testSubtract.getResult(), testFirst - testSecond);
}

TEST(test_Subtract, compute_zero_pos)
{
    Subtract testSubtract;
    
    double testFirst = 0.0;
    double testSecond = 5;
    testSubtract.setOperands(testFirst, testSecond);
    EXPECT_EQ(testSubtract.getResult(), testFirst - testSecond);
    
    testFirst = 0.0;
    testSecond = 12.6;
    testSubtract.setOperands(testFirst, testSecond);
    EXPECT_EQ(testSubtract.getResult(), testFirst - testSecond);
}

TEST(test_Subtract, compute_zero_neg)
{
    Subtract testSubtract;
    
    double testFirst = 0.0;
    double testSecond = -5;
    testSubtract.setOperands(testFirst, testSecond);
    EXPECT_EQ(testSubtract.getResult(), testFirst - testSecond);
    
    testFirst = 0.0;
    testSecond = -12.6;
    testSubtract.setOperands(testFirst, testSecond);
    EXPECT_EQ(testSubtract.getResult(), testFirst - testSecond);
}

TEST(test_Subtract, compute_pos_zero)
{
    Subtract testSubtract;
    
    double testFirst = 10;
    double testSecond = 0.0;
    testSubtract.setOperands(testFirst, testSecond);
    EXPECT_EQ(testSubtract.getResult(), testFirst - testSecond);
    
    testFirst = 10.237;
    testSecond = 0.0;
    testSubtract.setOperands(testFirst, testSecond);
    EXPECT_EQ(testSubtract.getResult(), testFirst - testSecond);
}

TEST(test_Subtract, compute_pos_pos)
{
    Subtract testSubtract;
    
    double testFirst = 10;
    double testSecond = 24;
    testSubtract.setOperands(testFirst, testSecond);
    EXPECT_EQ(testSubtract.getResult(), testFirst - testSecond);
    
    testFirst = 10.237;
    testSecond = 55.5;
    testSubtract.setOperands(testFirst, testSecond);
    EXPECT_EQ(testSubtract.getResult(), testFirst - testSecond);
}

TEST(test_Subtract, compute_pos_neg)
{
    Subtract testSubtract;
    
    double testFirst = 10;
    double testSecond = -24;
    testSubtract.setOperands(testFirst, testSecond);
    EXPECT_EQ(testSubtract.getResult(), testFirst - testSecond);
    
    testFirst = 10.237;
    testSecond = -55.5;
    testSubtract.setOperands(testFirst, testSecond);
    EXPECT_EQ(testSubtract.getResult(), testFirst - testSecond);
}

TEST(test_Subtract, compute_neg_zero)
{
    Subtract testSubtract;
    
    double testFirst = -10;
    double testSecond = 0;
    testSubtract.setOperands(testFirst, testSecond);
    EXPECT_EQ(testSubtract.getResult(), testFirst - testSecond);
    
    testFirst = -10.237;
    testSecond = 0.0;
    testSubtract.setOperands(testFirst, testSecond);
    EXPECT_EQ(testSubtract.getResult(), testFirst - testSecond);
}

TEST(test_Subtract, compute_neg_pos)
{
    Subtract testSubtract;
    
    double testFirst = -10;
    double testSecond = 24;
    testSubtract.setOperands(testFirst, testSecond);
    EXPECT_EQ(testSubtract.getResult(), testFirst - testSecond);
    
    testFirst = -10.237;
    testSecond = 55.5;
    testSubtract.setOperands(testFirst, testSecond);
    EXPECT_EQ(testSubtract.getResult(), testFirst - testSecond);
}

TEST(test_Subtract, compute_neg_neg)
{
    Subtract testSubtract;
    
    double testFirst = -10;
    double testSecond = -24;
    testSubtract.setOperands(testFirst, testSecond);
    EXPECT_EQ(testSubtract.getResult(), testFirst - testSecond);
    
    testFirst = -10.237;
    testSecond = -55.5;
    testSubtract.setOperands(testFirst, testSecond);
    EXPECT_EQ(testSubtract.getResult(), testFirst - testSecond);
}

TEST(test_Multiply, ctor)
{
    Multiply testMultiply;
    
    EXPECT_EQ(testMultiply.getResult(), 0.0);
}

TEST(test_Multiply, get_type)
{
    Multiply testMultiply;
    
    EXPECT_EQ(testMultiply.getType(), operationType::MULTIPLY);
}

TEST(test_Multiply, compute_zero_zero)
{
    Multiply testMultiply;
    
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
    
    double testFirst = 0.0;
    double testSecond = 0.0;
    testMultiply.setOperands(testFirst, testSecond);
    EXPECT_EQ(testMultiply.getResult(), testFirst * testSecond);
}

TEST(test_Multiply, compute_zero_pos)
{
    Multiply testMultiply;
    
    double testFirst = 0.0;
    double testSecond = 5;
    testMultiply.setOperands(testFirst, testSecond);
    EXPECT_EQ(testMultiply.getResult(), testFirst * testSecond);
    
    testFirst = 0.0;
    testSecond = 12.6;
    testMultiply.setOperands(testFirst, testSecond);
    EXPECT_EQ(testMultiply.getResult(), testFirst * testSecond);
}

TEST(test_Multiply, compute_zero_neg)
{
    Multiply testMultiply;
    
    double testFirst = 0.0;
    double testSecond = -5;
    testMultiply.setOperands(testFirst, testSecond);
    EXPECT_EQ(testMultiply.getResult(), testFirst * testSecond);
    
    testFirst = 0.0;
    testSecond = -12.6;
    testMultiply.setOperands(testFirst, testSecond);
    EXPECT_EQ(testMultiply.getResult(), testFirst * testSecond);
}

TEST(test_Multiply, compute_pos_zero)
{
    Multiply testMultiply;
    
    double testFirst = 10;
    double testSecond = 0.0;
    testMultiply.setOperands(testFirst, testSecond);
    EXPECT_EQ(testMultiply.getResult(), testFirst * testSecond);
    
    testFirst = 10.237;
    testSecond = 0.0;
    testMultiply.setOperands(testFirst, testSecond);
    EXPECT_EQ(testMultiply.getResult(), testFirst * testSecond);
}

TEST(test_Multiply, compute_pos_pos)
{
    Multiply testMultiply;
    
    double testFirst = 10;
    double testSecond = 24;
    testMultiply.setOperands(testFirst, testSecond);
    EXPECT_EQ(testMultiply.getResult(), testFirst * testSecond);
    
    testFirst = 10.237;
    testSecond = 55.5;
    testMultiply.setOperands(testFirst, testSecond);
    EXPECT_EQ(testMultiply.getResult(), testFirst * testSecond);
}

TEST(test_Multiply, compute_pos_neg)
{
    Multiply testMultiply;
    
    double testFirst = 10;
    double testSecond = -24;
    testMultiply.setOperands(testFirst, testSecond);
    EXPECT_EQ(testMultiply.getResult(), testFirst * testSecond);
    
    testFirst = 10.237;
    testSecond = -55.5;
    testMultiply.setOperands(testFirst, testSecond);
    EXPECT_EQ(testMultiply.getResult(), testFirst * testSecond);
}

TEST(test_Multiply, compute_neg_zero)
{
    Multiply testMultiply;
    
    double testFirst = -10;
    double testSecond = 0;
    testMultiply.setOperands(testFirst, testSecond);
    EXPECT_EQ(testMultiply.getResult(), testFirst * testSecond);
    
    testFirst = -10.237;
    testSecond = 0.0;
    testMultiply.setOperands(testFirst, testSecond);
    EXPECT_EQ(testMultiply.getResult(), testFirst * testSecond);
}

TEST(test_Multiply, compute_neg_pos)
{
    Multiply testMultiply;
    
    double testFirst = -10;
    double testSecond = 24;
    testMultiply.setOperands(testFirst, testSecond);
    EXPECT_EQ(testMultiply.getResult(), testFirst * testSecond);
    
    testFirst = -10.237;
    testSecond = 55.5;
    testMultiply.setOperands(testFirst, testSecond);
    EXPECT_EQ(testMultiply.getResult(), testFirst * testSecond);
}

TEST(test_Multiply, compute_neg_neg)
{
    Multiply testMultiply;
    
    double testFirst = -10;
    double testSecond = -24;
    testMultiply.setOperands(testFirst, testSecond);
    EXPECT_EQ(testMultiply.getResult(), testFirst * testSecond);
    
    testFirst = -10.237;
    testSecond = -55.5;
    testMultiply.setOperands(testFirst, testSecond);
    EXPECT_EQ(testMultiply.getResult(), testFirst * testSecond);
}

TEST(test_Divide, ctor)
{
    Divide testDivide;
    
    EXPECT_EQ(testDivide.getResult(), 1.0);
}

TEST(test_Divide, get_type)
{
    Divide testDivide;
    
    EXPECT_EQ(testDivide.getType(), operationType::DIVIDE);
}

TEST(test_Divide, compute_zero_zero)
{
    Divide testDivide;
    
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
    
    double testFirst = 0.0;
    double testSecond = 0.0;
    testDivide.setOperands(testFirst, testSecond);
    EXPECT_THROW(testDivide.getResult(), DivideByZeroException);
}

TEST(test_Divide, compute_zero_pos)
{
    Divide testDivide;
    
    double testFirst = 0.0;
    double testSecond = 5;
    testDivide.setOperands(testFirst, testSecond);
    EXPECT_EQ(testDivide.getResult(), testFirst / testSecond);
    
    testFirst = 0.0;
    testSecond = 12.6;
    testDivide.setOperands(testFirst, testSecond);
    EXPECT_EQ(testDivide.getResult(), testFirst / testSecond);
}

TEST(test_Divide, compute_zero_neg)
{
    Divide testDivide;
    
    double testFirst = 0.0;
    double testSecond = -5;
    testDivide.setOperands(testFirst, testSecond);
    EXPECT_EQ(testDivide.getResult(), testFirst / testSecond);
    
    testFirst = 0.0;
    testSecond = -12.6;
    testDivide.setOperands(testFirst, testSecond);
    EXPECT_EQ(testDivide.getResult(), testFirst / testSecond);
}

TEST(test_Divide, compute_pos_zero)
{
    Divide testDivide;
    
    double testFirst = 10;
    double testSecond = 0.0;
    testDivide.setOperands(testFirst, testSecond);
    EXPECT_THROW(testDivide.getResult(), DivideByZeroException);
    
    testFirst = 10.237;
    testSecond = 0.0;
    testDivide.setOperands(testFirst, testSecond);
    EXPECT_THROW(testDivide.getResult(), DivideByZeroException);
}

TEST(test_Divide, compute_pos_pos)
{
    Divide testDivide;
    
    double testFirst = 10;
    double testSecond = 24;
    testDivide.setOperands(testFirst, testSecond);
    EXPECT_EQ(testDivide.getResult(), testFirst / testSecond);
    
    testFirst = 10.237;
    testSecond = 55.5;
    testDivide.setOperands(testFirst, testSecond);
    EXPECT_EQ(testDivide.getResult(), testFirst / testSecond);
}

TEST(test_Divide, compute_pos_neg)
{
    Divide testDivide;
    
    double testFirst = 10;
    double testSecond = -24;
    testDivide.setOperands(testFirst, testSecond);
    EXPECT_EQ(testDivide.getResult(), testFirst / testSecond);
    
    testFirst = 10.237;
    testSecond = -55.5;
    testDivide.setOperands(testFirst, testSecond);
    EXPECT_EQ(testDivide.getResult(), testFirst / testSecond);
}

TEST(test_Divide, compute_neg_zero)
{
    Divide testDivide;
    
    double testFirst = -10;
    double testSecond = 0;
    testDivide.setOperands(testFirst, testSecond);
    EXPECT_THROW(testDivide.getResult(), DivideByZeroException);
    
    testFirst = -10.237;
    testSecond = 0.0;
    testDivide.setOperands(testFirst, testSecond);
    EXPECT_THROW(testDivide.getResult(), DivideByZeroException);
}

TEST(test_Divide, compute_neg_pos)
{
    Divide testDivide;
    
    double testFirst = -10;
    double testSecond = 24;
    testDivide.setOperands(testFirst, testSecond);
    EXPECT_EQ(testDivide.getResult(), testFirst / testSecond);
    
    testFirst = -10.237;
    testSecond = 55.5;
    testDivide.setOperands(testFirst, testSecond);
    EXPECT_EQ(testDivide.getResult(), testFirst / testSecond);
}

TEST(test_Divide, compute_neg_neg)
{
    Divide testDivide;
    
    double testFirst = -10;
    double testSecond = -24;
    testDivide.setOperands(testFirst, testSecond);
    EXPECT_EQ(testDivide.getResult(), testFirst / testSecond);
    
    testFirst = -10.237;
    testSecond = -55.5;
    testDivide.setOperands(testFirst, testSecond);
    EXPECT_EQ(testDivide.getResult(), testFirst / testSecond);
}

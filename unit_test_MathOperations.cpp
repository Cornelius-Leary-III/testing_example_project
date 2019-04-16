//
// Created by cornelius on 4/11/19.
//

#include "MathOperations.h"
#include <gtest/gtest.h>

TEST(test_MathOperations, ctor_default)
{
    MathOperations testMathOperations;
    
    EXPECT_TRUE(testMathOperations.getSetOfRequestedOperations().empty());
}

TEST(test_MathOperations, request_single_operation_Add)
{
    MathOperations testMathOperations;
    
    testMathOperations.requestOperation(4.5, 3.3, operationType::ADD);
    
    auto listOfRequestedOperations = testMathOperations.getSetOfRequestedOperations();
    EXPECT_EQ(listOfRequestedOperations.size(), 1);
    EXPECT_EQ(listOfRequestedOperations.front()->getResult(), 7.8);
    EXPECT_NO_THROW(listOfRequestedOperations.front()->getResult());
    EXPECT_EQ(listOfRequestedOperations.front()->getType(), operationType::ADD);
}

TEST(test_MathOperations, request_single_operation_Subtract)
{
    MathOperations testMathOperations;
    
    testMathOperations.requestOperation(4.5, 1.9, operationType::SUBTRACT);
    
    auto listOfRequestedOperations = testMathOperations.getSetOfRequestedOperations();
    EXPECT_EQ(listOfRequestedOperations.size(), 1);
    EXPECT_EQ(listOfRequestedOperations.front()->getResult(), 2.6);
    EXPECT_NO_THROW(listOfRequestedOperations.front()->getResult());
    EXPECT_EQ(listOfRequestedOperations.front()->getType(), operationType::SUBTRACT);
}

TEST(test_MathOperations, request_single_operation_Multiply)
{
    MathOperations testMathOperations;
    
    testMathOperations.requestOperation(4, 12, operationType::MULTIPLY);
    
    auto listOfRequestedOperations = testMathOperations.getSetOfRequestedOperations();
    EXPECT_EQ(listOfRequestedOperations.size(), 1);
    EXPECT_EQ(listOfRequestedOperations.front()->getResult(), 48);
    EXPECT_NO_THROW(listOfRequestedOperations.front()->getResult());
    EXPECT_EQ(listOfRequestedOperations.front()->getType(), operationType::MULTIPLY);
}

TEST(test_MathOperations, request_single_operation_Divide)
{
    MathOperations testMathOperations;
    
    testMathOperations.requestOperation(4.5, 2, operationType::DIVIDE);
    
    auto listOfRequestedOperations = testMathOperations.getSetOfRequestedOperations();
    EXPECT_EQ(listOfRequestedOperations.size(), 1);
    EXPECT_EQ(listOfRequestedOperations.front()->getResult(), 2.25);
    EXPECT_NO_THROW(listOfRequestedOperations.front()->getResult());
    EXPECT_EQ(listOfRequestedOperations.front()->getType(), operationType::DIVIDE);
}

TEST(test_MathOperations, request_single_operation_Remainder)
{
    MathOperations testMathOperations;
    
    testMathOperations.requestOperation(8, 5, operationType::REMAINDER);
    
    auto listOfRequestedOperations = testMathOperations.getSetOfRequestedOperations();
    EXPECT_EQ(listOfRequestedOperations.size(), 1);
    EXPECT_EQ(listOfRequestedOperations.front()->getResult(), 3);
    EXPECT_NO_THROW(listOfRequestedOperations.front()->getResult());
    EXPECT_EQ(listOfRequestedOperations.front()->getType(), operationType::REMAINDER);
}

TEST(test_MathOperations, request_single_operation_Exponentiate)
{
    MathOperations testMathOperations;
    
    testMathOperations.requestOperation(4, 2, operationType::POWER);
    
    auto listOfRequestedOperations = testMathOperations.getSetOfRequestedOperations();
    EXPECT_EQ(listOfRequestedOperations.size(), 1);
    EXPECT_EQ(listOfRequestedOperations.front()->getResult(), 16);
    EXPECT_NO_THROW(listOfRequestedOperations.front()->getResult());
    EXPECT_EQ(listOfRequestedOperations.front()->getType(), operationType::POWER);
}


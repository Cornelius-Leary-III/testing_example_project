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
}


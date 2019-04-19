//
// Created by cornelius on 4/16/19.
//

#include "MathOperations.h"
#include <gtest/gtest.h>

TEST(integration_test, three_operations_same_type)
{
    MathOperations testMathOps;
    
    testMathOps.requestOperation(1, 5, operationType::ADD);
    testMathOps.requestOperation(2, 9, operationType::ADD);
    testMathOps.requestOperation(3, -4, operationType::ADD);
    
    auto outputRequestedOpsList = testMathOps.getSetOfRequestedOperations();
    EXPECT_EQ(outputRequestedOpsList.size(), 3);
    
    auto outputIter = outputRequestedOpsList.begin();
    EXPECT_NO_THROW((*outputIter)->getResult());
    EXPECT_EQ((*outputIter)->getResult(), 1 + 5);
    EXPECT_EQ((*outputIter)->getType(), operationType::ADD);
    
    EXPECT_NO_THROW((*(++outputIter))->getResult());
    EXPECT_EQ((*outputIter)->getResult(), 2 + 9);
    EXPECT_EQ((*outputIter)->getType(), operationType::ADD);
    
    EXPECT_NO_THROW((*(++outputIter))->getResult());
    EXPECT_EQ((*outputIter)->getResult(), 3 + -4);
    EXPECT_EQ((*outputIter)->getType(), operationType::ADD);
    
    EXPECT_EQ(testMathOps.getOperationCount(operationType::ADD), 3);
    EXPECT_EQ(testMathOps.getOperationCount(operationType::SUBTRACT), 0);
    EXPECT_EQ(testMathOps.getOperationCount(operationType::MULTIPLY), 0);
    EXPECT_EQ(testMathOps.getOperationCount(operationType::DIVIDE), 0);
    EXPECT_EQ(testMathOps.getOperationCount(operationType::REMAINDER), 0);
    EXPECT_EQ(testMathOps.getOperationCount(operationType::POWER), 0);
}

TEST(integration_test, three_operations_different_types)
{
    MathOperations testMathOps;
    
    testMathOps.requestOperation(1, 5, operationType::ADD);
    testMathOps.requestOperation(2, 9, operationType::POWER);
    testMathOps.requestOperation(3, -4, operationType::SUBTRACT);
    
    auto outputRequestedOpsList = testMathOps.getSetOfRequestedOperations();
    EXPECT_EQ(outputRequestedOpsList.size(), 3);
    
    auto outputIter = outputRequestedOpsList.begin();
    EXPECT_NO_THROW((*outputIter)->getResult());
    EXPECT_EQ((*outputIter)->getResult(), 1 + 5);
    EXPECT_EQ((*outputIter)->getType(), operationType::ADD);
    
    EXPECT_NO_THROW((*(++outputIter))->getResult());
    EXPECT_EQ((*outputIter)->getResult(), 512);
    EXPECT_EQ((*outputIter)->getType(), operationType::POWER);
    
    EXPECT_NO_THROW((*(++outputIter))->getResult());
    EXPECT_EQ((*outputIter)->getResult(), 3 - -4);
    EXPECT_EQ((*outputIter)->getType(), operationType::SUBTRACT);
    
    EXPECT_EQ(testMathOps.getOperationCount(operationType::ADD), 1);
    EXPECT_EQ(testMathOps.getOperationCount(operationType::SUBTRACT), 1);
    EXPECT_EQ(testMathOps.getOperationCount(operationType::MULTIPLY), 0);
    EXPECT_EQ(testMathOps.getOperationCount(operationType::DIVIDE), 0);
    EXPECT_EQ(testMathOps.getOperationCount(operationType::REMAINDER), 0);
    EXPECT_EQ(testMathOps.getOperationCount(operationType::POWER), 1);
}

TEST(integration_test, three_operations_different_types_with_op_ctor)
{
    auto firstOp = new Remainder();
    firstOp->setOperands(9, 4);
    
    MathOperations testMathOps(firstOp);
    
    testMathOps.requestOperation(1, 5, operationType::ADD);
    testMathOps.requestOperation(2, 9, operationType::POWER);
    testMathOps.requestOperation(3, -4, operationType::SUBTRACT);
    
    auto outputRequestedOpsList = testMathOps.getSetOfRequestedOperations();
    EXPECT_EQ(outputRequestedOpsList.size(), 4);
    
    auto outputIter = outputRequestedOpsList.begin();
    EXPECT_NO_THROW((*outputIter)->getResult());
    EXPECT_EQ((*outputIter)->getResult(), 1);
    EXPECT_EQ((*outputIter)->getType(), operationType::REMAINDER);
    
    EXPECT_NO_THROW((*(++outputIter))->getResult());
    EXPECT_EQ((*outputIter)->getResult(), 1 + 5);
    EXPECT_EQ((*outputIter)->getType(), operationType::ADD);
    
    EXPECT_NO_THROW((*(++outputIter))->getResult());
    EXPECT_EQ((*outputIter)->getResult(), 512);
    EXPECT_EQ((*outputIter)->getType(), operationType::POWER);
    
    EXPECT_NO_THROW((*(++outputIter))->getResult());
    EXPECT_EQ((*outputIter)->getResult(), 3 - -4);
    EXPECT_EQ((*outputIter)->getType(), operationType::SUBTRACT);
    
    EXPECT_EQ(testMathOps.getOperationCount(operationType::ADD), 1);
    EXPECT_EQ(testMathOps.getOperationCount(operationType::SUBTRACT), 1);
    EXPECT_EQ(testMathOps.getOperationCount(operationType::MULTIPLY), 0);
    EXPECT_EQ(testMathOps.getOperationCount(operationType::DIVIDE), 0);
    EXPECT_EQ(testMathOps.getOperationCount(operationType::REMAINDER), 1);
    EXPECT_EQ(testMathOps.getOperationCount(operationType::POWER), 1);
}

TEST(integration_test, three_operations_different_types_with_op_ctor_set_operands_thrice)
{
    auto firstOp = new Remainder();
    firstOp->setOperands(19, 4);
    firstOp->setOperands(7, 2);
    
    MathOperations testMathOps(firstOp);
    
    firstOp->setOperands(15, 8);
    
    testMathOps.requestOperation(1, 5, operationType::ADD);
    testMathOps.requestOperation(2, 9, operationType::POWER);
    testMathOps.requestOperation(3, -4, operationType::SUBTRACT);
    
    auto outputRequestedOpsList = testMathOps.getSetOfRequestedOperations();
    EXPECT_EQ(outputRequestedOpsList.size(), 4);
    
    auto outputIter = outputRequestedOpsList.begin();
    EXPECT_NO_THROW((*outputIter)->getResult());
    EXPECT_EQ((*outputIter)->getResult(), 7);
    EXPECT_NE((*outputIter)->getResult(), 1);
    EXPECT_NE((*outputIter)->getResult(), 3);
    EXPECT_EQ((*outputIter)->getType(), operationType::REMAINDER);
    
    EXPECT_NO_THROW((*(++outputIter))->getResult());
    EXPECT_EQ((*outputIter)->getResult(), 1 + 5);
    EXPECT_EQ((*outputIter)->getType(), operationType::ADD);
    
    EXPECT_NO_THROW((*(++outputIter))->getResult());
    EXPECT_EQ((*outputIter)->getResult(), 512);
    EXPECT_EQ((*outputIter)->getType(), operationType::POWER);
    
    EXPECT_NO_THROW((*(++outputIter))->getResult());
    EXPECT_EQ((*outputIter)->getResult(), 3 - -4);
    EXPECT_EQ((*outputIter)->getType(), operationType::SUBTRACT);
}

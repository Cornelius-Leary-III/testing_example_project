//
// Created by cornelius on 4/11/19.
//

#include "MathOperations.h"

MathOperations::MathOperations()
        : requestedOperations{},
          operationCount{{operationType::ADD,       0},
                         {operationType::SUBTRACT,  0},
                         {operationType::MULTIPLY,  0},
                         {operationType::DIVIDE,    0},
                         {operationType::REMAINDER, 0},
                         {operationType::POWER,     0}}
{
}

MathOperations::MathOperations(Operation* firstOperation)
        : requestedOperations{firstOperation},
          operationCount{{operationType::ADD,       0},
                         {operationType::SUBTRACT,  0},
                         {operationType::MULTIPLY,  0},
                         {operationType::DIVIDE,    0},
                         {operationType::REMAINDER, 0},
                         {operationType::POWER,     0}}
{
    auto type = firstOperation->getType();
    
    incrementOperationCount(type);
}

string MathOperations::getSummaryOfOperations()
{
    stringstream ss;
    
    ss << "\n\nThe # of addition operations: \t"
       << getOperationCount(operationType::ADD) << endl;
    
    ss << "The # of subtraction operations: \t"
       << getOperationCount(operationType::SUBTRACT) << endl;
    
    ss << "The # of multiplication operations: \t"
       << getOperationCount(operationType::MULTIPLY) << endl;
    
    ss << "The # of division operations: \t"
       << getOperationCount(operationType::DIVIDE) << endl;
    
    ss << "The # of division-remainder operations: \t"
       << getOperationCount(operationType::REMAINDER) << endl;
    
    ss << "The # of exponentiation operations: \t"
       << getOperationCount(operationType::POWER) << endl;
    
    return ss.str();
}

vector<Operation*>& MathOperations::getSetOfRequestedOperations()
{
    return requestedOperations;
}

int MathOperations::getOperationCount(operationType operation)
{
    auto findOperationIter = operationCount.find(operation);
    
    if (findOperationIter != operationCount.end())
    {
        return findOperationIter->second;
    }
    
    return 0;
}

void MathOperations::requestOperation(double first,
                                      double second,
                                      operationType operationToPerform)
{
    switch (operationToPerform)
    {
        case ADD:
        {
            createAddOperation(first, second);
            break;
        }
        
        case SUBTRACT:
        {
            createSubtractOperation(first, second);
            break;
        }
        
        case MULTIPLY:
        {
            createMultiplyOperation(first, second);
            break;
        }
        
        case DIVIDE:
        {
            createDivideOperation(first, second);
            break;
        }
        
        case REMAINDER:
        {
            createRemainderOperation(first, second);
            break;
        }
        
        case POWER:
        {
            createPowerOperation(first, second);
            break;
        }
    }
}

void MathOperations::createAddOperation(double firstOperand, double secondOperand)
{
    auto newOperation = new Add();
    newOperation->setOperands(firstOperand, secondOperand);
    
    requestedOperations.push_back(newOperation);
    
    incrementOperationCount(operationType::ADD);
}

void MathOperations::createSubtractOperation(double firstOperand, double secondOperand)
{
    auto newOperation = new Subtract();
    newOperation->setOperands(firstOperand, secondOperand);
    
    requestedOperations.push_back(newOperation);
    
    incrementOperationCount(operationType::SUBTRACT);
}

void MathOperations::createMultiplyOperation(double firstOperand, double secondOperand)
{
    auto newOperation = new Multiply();
    newOperation->setOperands(firstOperand, secondOperand);
    
    requestedOperations.push_back(newOperation);
    
    incrementOperationCount(operationType::MULTIPLY);
}

void MathOperations::createDivideOperation(double firstOperand, double secondOperand)
{
    auto newOperation = new Divide();
    newOperation->setOperands(firstOperand, secondOperand);
    
    requestedOperations.push_back(newOperation);
    
    incrementOperationCount(operationType::DIVIDE);
}

void MathOperations::createRemainderOperation(double firstOperand, double secondOperand)
{
    auto newOperation = new Remainder();
    newOperation->setOperands(firstOperand, secondOperand);
    
    requestedOperations.push_back(newOperation);
    
    incrementOperationCount(operationType::REMAINDER);
}

void MathOperations::createPowerOperation(double firstOperand, double secondOperand)
{
    auto newOperation = new Exponentiate();
    newOperation->setOperands(firstOperand, secondOperand);
    
    requestedOperations.push_back(newOperation);
    
    incrementOperationCount(operationType::POWER);
}

void MathOperations::incrementOperationCount(operationType operation)
{
    auto findOperationIter = operationCount.find(operation);
    
    if (findOperationIter != operationCount.end())
    {
        ++(findOperationIter->second);
    }
}




















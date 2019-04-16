//
// Created by cornelius on 4/11/19.
//

#include "MathOperations.h"

MathOperations::MathOperations()
        : requestedOperations{}
{
}

MathOperations::MathOperations(Operation* firstOperation)
        : requestedOperations{firstOperation}
{
}

vector<Operation*>& MathOperations::getSetOfRequestedOperations()
{
    return requestedOperations;
}

void MathOperations::requestOperation(double first,
                                      double second,
                                      operationType operationToPerform)
{
    switch (operationToPerform)
    {
        case ADD:
        {
            auto newOperation = new Add();
            newOperation->setOperands(first, second);
            
            requestedOperations.push_back(newOperation);
            break;
        }
        
        case SUBTRACT:
        {
            auto newOperation = new Subtract();
            newOperation->setOperands(first, second);
            
            requestedOperations.push_back(newOperation);
            break;
        }
        
        case MULTIPLY:
        {
            auto newOperation = new Multiply();
            newOperation->setOperands(first, second);
            
            requestedOperations.push_back(newOperation);
            break;
        }
        
        case DIVIDE:
        {
            auto newOperation = new Divide();
            newOperation->setOperands(first, second);
            
            requestedOperations.push_back(newOperation);
            break;
        }
        
        case REMAINDER:
        {
            auto newOperation = new Remainder();
            newOperation->setOperands(first, second);
            
            requestedOperations.push_back(newOperation);
            break;
        }
        
        case POWER:
        {
            auto newOperation = new Exponentiate();
            newOperation->setOperands(first, second);
            
            requestedOperations.push_back(newOperation);
            break;
        }
    }
}
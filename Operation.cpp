//
// Created by cornelius on 4/11/19.
//

#include "Operation.h"

Add::Add()
        : firstValue{0.0}, secondValue{0.0}
{
}

double Add::getResult()
{
    return firstValue + secondValue;
}

operationType Add::getType()
{
    return operationType::ADD;
}

void Add::setOperands(double first, double second)
{
    firstValue = first;
    secondValue = second;
}
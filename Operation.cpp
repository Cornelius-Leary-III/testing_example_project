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

Subtract::Subtract()
        : firstValue{0.0}, secondValue{0.0}
{
}

double Subtract::getResult()
{
    return firstValue - secondValue;
}

operationType Subtract::getType()
{
    return operationType::SUBTRACT;
}

void Subtract::setOperands(double first, double second)
{
    firstValue = first;
    secondValue = second;
}

Multiply::Multiply()
        : firstValue{0.0}, secondValue{0.0}
{
}

double Multiply::getResult()
{
    return firstValue * secondValue;
}

operationType Multiply::getType()
{
    return operationType::MULTIPLY;
}

void Multiply::setOperands(double first, double second)
{
    firstValue = first;
    secondValue = second;
}

const char* DivideByZeroException::what() noexcept
{
    return "Cannot divide by zero (0).";
}

Divide::Divide()
        : firstValue{1.0}, secondValue{1.0}
{
}

double Divide::getResult()
{
    if (secondValue == 0.0)
    {
        throw DivideByZeroException();
    }
    
    return firstValue / secondValue;
}

operationType Divide::getType()
{
    return operationType::DIVIDE;
}

void Divide::setOperands(double first, double second)
{
    firstValue = first;
    secondValue = second;
}
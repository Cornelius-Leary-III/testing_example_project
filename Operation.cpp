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

Remainder::Remainder()
        : firstValue{1.0}, secondValue{1.0}
{
}

double Remainder::getResult()
{
    if (secondValue == 0.0)
    {
        throw DivideByZeroException();
    }
    
    return fmod(firstValue, secondValue);
}

operationType Remainder::getType()
{
    return operationType::REMAINDER;
}

void Remainder::setOperands(double first, double second)
{
    firstValue = first;
    secondValue = second;
}

const char* ExponentiationException::what() noexcept
{
    return "(See std::pow(x, y) documentation)\nCannot have (-)# base and non-int exponent.";
}

Exponentiate::Exponentiate()
        : base{1}, power{1}
{
}

double Exponentiate::getResult()
{
    if (base < 0.0 && isfinite(base) && power != 0.0)
    {
        double wholeNumberComponent;
        double decimalComponent = modf(base, &wholeNumberComponent);
        
        if (decimalComponent != 0.000000)
        {
            throw ExponentiationException();
        }
    }
    
    return pow(base, power);
}

operationType Exponentiate::getType()
{
    return operationType::POWER;
}

void Exponentiate::setOperands(double first, double second)
{
    base = first;
    power = second;
}
//
// Created by cornelius on 4/11/19.
//

#ifndef TESTING_EXAMPLE_PROJECT_OPERATION_H
#define TESTING_EXAMPLE_PROJECT_OPERATION_H

#include <bits/exception.h>
#include <cmath>

using std::exception;
using std::fmod;
using std::pow;
using std::isfinite;

enum operationType
{
    ADD,
    SUBTRACT,
    MULTIPLY,
    DIVIDE,
    REMAINDER,
    POWER
};

class Operation
{
public:
    
    virtual ~Operation() = default;
    virtual double getResult() = 0;
    virtual operationType getType() = 0;
    virtual void setOperands(double first, double second) = 0;
};

class Add : public Operation
{
public:
    
    Add();
    ~Add() = default;
    
    double getResult();
    operationType getType();
    
    void setOperands(double first, double second);

private:
    
    double firstValue;
    double secondValue;
};

class Subtract : public Operation
{
public:
    
    Subtract();
    ~Subtract() = default;
    
    double getResult();
    operationType getType();
    
    void setOperands(double first, double second);

private:
    
    double firstValue;
    double secondValue;
};

class Multiply : public Operation
{
public:
    
    Multiply();
    ~Multiply() = default;
    
    double getResult();
    operationType getType();
    
    void setOperands(double first, double second);

private:
    
    double firstValue;
    double secondValue;
};

class DivideByZeroException : public std::exception
{
public:
    
    const char* what() noexcept;
};

class Divide : public Operation
{
public:
    
    Divide();
    ~Divide() = default;
    
    double getResult();
    operationType getType();
    
    void setOperands(double first, double second);

private:
    
    double firstValue;
    double secondValue;
};

class Remainder : public Operation
{
public:
    
    Remainder();
    ~Remainder() = default;
    
    double getResult();
    operationType getType();
    
    void setOperands(double first, double second);

private:
    
    double firstValue;
    double secondValue;
};

class ExponentiationNANException : public std::exception
{
public:
    
    const char* what() noexcept;
};

class Exponentiate : public Operation
{
public:
    
    Exponentiate();
    ~Exponentiate() = default;
    
    double getResult();
    operationType getType();
    
    void setOperands(double first, double second);

private:
    
    double base;
    double power;
};

#endif //TESTING_EXAMPLE_PROJECT_OPERATION_H

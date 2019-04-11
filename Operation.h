//
// Created by cornelius on 4/11/19.
//

#ifndef TESTING_EXAMPLE_PROJECT_OPERATION_H
#define TESTING_EXAMPLE_PROJECT_OPERATION_H

enum operationType
{
    ADD,
    SUBTRACT,
    MULTIPLY,
    DIVIDE,
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


#endif //TESTING_EXAMPLE_PROJECT_OPERATION_H

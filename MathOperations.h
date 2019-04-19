//
// Created by cornelius on 4/11/19.
//

#ifndef TESTING_EXAMPLE_PROJECT_MATHOPERATIONS_H
#define TESTING_EXAMPLE_PROJECT_MATHOPERATIONS_H

#include "Operation.h"
#include <vector>
#include <string>
#include <sstream>
#include <map>
#include <iostream>

using std::vector;
using std::string;
using std::stringstream;
using std::map;
using std::pair;
using std::make_pair;
using std::cout;
using std::endl;

class MathOperations
{
public:
    MathOperations();
    explicit MathOperations(Operation* firstOperation);
    
    ~MathOperations() = default;
    
    void requestOperation(double first,
                          double second,
                          operationType operationToPerform);
    
    string getSummaryOfOperations();
    int getOperationCount(operationType operation);
    vector<Operation*>& getSetOfRequestedOperations();

private:
    void createAddOperation(double firstOperand, double secondOperand);
    void createSubtractOperation(double firstOperand, double secondOperand);
    void createMultiplyOperation(double firstOperand, double secondOperand);
    void createDivideOperation(double firstOperand, double secondOperand);
    void createRemainderOperation(double firstOperand, double secondOperand);
    void createPowerOperation(double firstOperand, double secondOperand);
    
    void incrementOperationCount(operationType operation);

private:
    vector<Operation*> requestedOperations;
    map<operationType, int> operationCount;
};


#endif //TESTING_EXAMPLE_PROJECT_MATHOPERATIONS_H

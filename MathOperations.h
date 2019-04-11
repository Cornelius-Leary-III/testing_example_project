//
// Created by cornelius on 4/11/19.
//

#ifndef TESTING_EXAMPLE_PROJECT_MATHOPERATIONS_H
#define TESTING_EXAMPLE_PROJECT_MATHOPERATIONS_H

#include "Operation.h"

#include <vector>

using std::vector;

class MathOperations
{
public:
    
    MathOperations();
    
    virtual ~MathOperations();
    
    virtual void requestOperation(double first, double second, operationType operationToPerform);

private:
    
    vector<Operation> requestedOperations;
    
};


#endif //TESTING_EXAMPLE_PROJECT_MATHOPERATIONS_H

//
// Created by cornelius on 4/11/19.
//

#ifndef TESTING_EXAMPLE_PROJECT_MATHOPERATIONS_H
#define TESTING_EXAMPLE_PROJECT_MATHOPERATIONS_H

#include "Operation.h"
#include <vector>
#include <string>
#include <sstream>

using std::vector;
using std::string;
using std::stringstream;

class MathOperations
{
public:
    
    MathOperations();
    
    explicit MathOperations(Operation* firstOperation);
    
    ~MathOperations() = default;
    
    void requestOperation(double first,
                          double second,
                          operationType operationToPerform);
    
    vector<Operation*>& getSetOfRequestedOperations();
    
private:
    
    vector<Operation*> requestedOperations;
};


#endif //TESTING_EXAMPLE_PROJECT_MATHOPERATIONS_H

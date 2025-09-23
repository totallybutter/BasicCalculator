#pragma once
#include <string>
#include "../include/ops.h"

class Calculator {
public:
    // op is the operation of choice that is given by the user 
    // a and b are both numeric input values given by the user
    // out will be the final calculated output value 
    // On success, the function returns true and writes to 'out' variable.
    // On error (e.g. divide by zero), the function returns false and sets 'error' and it's error text.
    
    bool compute(Operation op, double a, double b, double& out, std::string& error) const;
};

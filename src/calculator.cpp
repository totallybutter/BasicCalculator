#include "../include/calculator.h"

bool Calculator::compute(Operation op, double a, double b, double& out, std::string& error) const 
{
    switch (op) 
    {
        case Operation::Add: 
            out = a + b; 
            return true;
        case Operation::Sub: 
            out = a - b; 
            return true;
        case Operation::Mul: 
            out = a * b; 
            return true;
        case Operation::Div:
            if (b == 0) 
            { 
                error = "Division by zero is not allowed."; return false; 
            }
            out = a / b; 
            return true;
    }
    error = "Unknown operation.";
    return false;
}

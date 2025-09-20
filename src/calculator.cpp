#include "../include/calculator.h"
#include <cmath>
#include <limits>

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
                error = "Division by zero is not allowed.\n"; return false; 
            }
            out = a / b; 
            return true;
        case Operation::Pow:
            out = std::pow(a,b);
            if (!std::isfinite(out)) 
            { 
                error = "Result not finite."; 
                return false; 
            }
            return true;
        case Operation::Sqrt:
            if (a < 0)
            {
                error = "Square root of a negative number is not allowed.";
                return false;
            }
            out = std::sqrt(a);
            return true;
    }
    error = "Unknown operation.";
    return false;
}

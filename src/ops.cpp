#include "../include/ops.h"

bool isUnary(Operation op) 
{
    return op == Operation::Sqrt;
}

bool parseOperation(char c, Operation& out, std::string& error) 
{
    switch (c) 
    {
        case '+': 
            out = Operation::Add; 
            return true;

        case '-': 
            out = Operation::Sub; 
            return true;

        case '*': 
            out = Operation::Mul; 
            return true;

        case '/': 
            out = Operation::Div; 
            return true;

        case '^': 
            out = Operation::Pow; 
            return true;

        case '?': 
            out = Operation::Sqrt; 
            return true;

        default:
            error = "Invalid operator. Use one of (+, -, *, /, ^, ?).";
            return false;
    }
}

char toSymbol(Operation op) 
{
    return static_cast<char>(op);
}

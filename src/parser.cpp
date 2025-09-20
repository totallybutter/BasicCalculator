#include "../include/parser.h"
#include <sstream>

bool Parser::parseNumber(const std::string& s, double& out) const 
{
    std::stringstream ss(s);
    ss >> out;
    return !ss.fail() && ss.eof();
}

bool Parser::parseOperation(char c, Operation& out, std::string& error) const 
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
        default:  
            error = "Invalid operator. Use one of (+, -, *, /)."; 
            return false;
    }
}
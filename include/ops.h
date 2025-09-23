#pragma once
#include <string>

enum class Operation : char {
    Add  = '+',
    Sub  = '-',
    Mul  = '*',
    Div  = '/',
    Pow  = '^',
    Sqrt = '?'
};

//Helper functions
bool isUnary(Operation op);
bool parseOperation(char c, Operation& out, std::string& error);
char toSymbol(Operation op);

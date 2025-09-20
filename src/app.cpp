#include "../include/app.h"
#include <iostream>

const char* App::symbol(Operation op) 
{
    switch (op) {
        case Operation::Add: 
            return "+";
        case Operation::Sub: 
            return "-";
        case Operation::Mul: 
            return "*";
        case Operation::Div: 
            return "/";
        case Operation::Pow: 
            return "^";
        case Operation::Sqrt: 
            return "?";    
    }
    return "??";
}

void App::printExpr(double a, Operation op, double b, double result) 
{
    if(op == Operation::Sqrt)
    {
        std::cout << "sqrt(" << a << ") = " << result << "\n\n";
    }
    else
    {
        std::cout << a << " " << symbol(op) << " " << b << " = " << result << "\n\n";
    }
}

int App::run() 
{

    std::cout << "=== Basic Calculator ===\n(Type 'exit' at any time to quit)\n\n";

    while (true) 
    {
        std::string s1, s2, opStr;
        double a, b, result;
        std::string err;
        Operation op;

        // First number (or exit)
        std::cout << "Enter first number: ";

        if (!(std::cin >> s1) || (s1 == "exit")) 
            break; //If there is a stream error or end of file break, fail safe or user wants to exit
        
        if (!parser_.parseNumber(s1, a)) 
        { 
            std::cout << "Invalid number. Try again.\n\n"; 
            continue; 
        }

        // Operator (or exit)
        std::cout << "Enter operation (+, -, *, /, ^, ? for sqrt): ";

        if (!(std::cin >> opStr) || (opStr == "exit")) 
            break;

        if (opStr.size() != 1 || !parser_.parseOperation(opStr[0], op, err)) 
        {
            if (err.empty()) 
                err = "Invalid operator. Use one of (+, -, *, /, ^, ?).\n";

            std::cout << err << "\n\n";
            continue;
        }

        if (op == Operation::Sqrt) //if the operation is a square root
        {
            if (!calc_.compute(op, a, 0.0, result, err)) 
            {
                std::cout << "Error: " << err << "\n\n";
                continue;
            }
            printExpr(a, op, 0.0, result);
            continue;                     // <-- don't ask for a second number
        }

        // Second number (or exit)
        std::cout << "Enter second number: ";
        if (!(std::cin >> s2) || s2 == "exit") 
            break;

        if (!parser_.parseNumber(s2, b)) 
        { 
            std::cout << "Invalid number. Try again.\n\n"; 
            continue; 
        }

        // Compute
        if (!calc_.compute(op, a, b, result, err)) 
        {
            std::cout << "Error: " << err << "\n\n";
            continue;
        }

        // Show full expression
        printExpr(a, op, b, result);
    }

    return 0;
}

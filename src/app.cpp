#include "../include/app.h"
#include <iostream>
#include <sstream>


void App::printExpr(double a, Operation op, double b, double result) 
{
    std::cout << exprString(a,op,b,result) << "\n\n";
}
std::string App::exprString(double a, Operation op, double b, double result) 
{
    std::ostringstream os;
    if (op == Operation::Sqrt) 
    {
        os << "sqrt(" << a << ") = " << result;
    } else {
        os << a << " " << toSymbol(op) << " " << b << " = " << result;
    }
    return os.str();
}

bool App::handleCommand(const std::string& input) {
    if (input == "history") {
        printHistory();
        return true; 
    }
    if (input == "clear") {
        clearHistory();
        return true;
    }
    return false; 
}

void App::recordHistory(const std::string& line) 
{
    if (line.empty()) 
        return;
    if (history_.size() >= historyLimit) 
    {
        // simple ring buffer behavior: drop the oldest
        history_.erase(history_.begin());
    }

    history_.push_back(line);
}

void App::printHistory() const 
{
    if (history_.empty()) 
    {
        std::cout << "(history is empty)\n\n";
        return;
    }

    std::cout << "--- History (" << history_.size() << ") ---\n";  // shows the size of history stored

    for (std::size_t i = 0; i < history_.size(); ++i) //print out all stored history
    {
        std::cout << i + 1 << ") " << history_[i] << "\n";
    }
    std::cout << "-------------------------\n\n";
}

void App::clearHistory() 
{
    history_.clear();
    std::cout << "History cleared.\n\n";
}


int App::run() 
{
    //Calculator basic instructions
    std::cout << "=== Basic Calculator ===\n\n"
          << "Commands:\n"
          << "  exit    -> quit the program at any time\n"
          << "  history -> show all previous calculations\n"
          << "  clear   -> clear the history\n\n"
          << "Operations:\n"
          << "  +   addition\n"
          << "  -   subtraction\n"
          << "  *   multiplication\n"
          << "  /   division\n"
          << "  ^   exponentiation\n"
          << "  ?   square root (unary, no second number)\n\n";
 
    while (true) 
    {
        std::string s1, s2;
        char opChar;
        double a, b = 0.0, result;
        std::string err;
        Operation op;

        // First number (or exit)
        std::cout << "Enter first number: ";

        if (!(std::cin >> s1) || (s1 == "exit")) 
            break; //If there is a stream error or end of file break, fail safe or user wants to exit
        
        if (handleCommand(s1))
            continue;

        if (!parser_.parseNumber(s1, a)) 
        { 
            std::cout << "Invalid number. Try again.\n\n"; 
            continue; 
        }

        // Operator (or exit)
        std::cout << "Enter operation (+, -, *, /, ^, ? for sqrt): ";

        if (!(std::cin >> opChar)) 
            break;

        if (!parseOperation(opChar, op, err)) 
        {
            std::cout << err << "\n\n";
            continue;
        }

        if (isUnary(op)) //if the operation is a square root
        {
            if (!calc_.compute(op, a, 0.0, result, err)) 
            {
                std::cout << "Error: " << err << "\n\n";
                continue;
            }
            printExpr(a, op, 0.0, result);
            recordHistory(exprString(a, op, 0.0, result));
            continue;                     // <-- don't ask for a second number
        }

        // Second number (or exit)
        std::cout << "Enter second number: ";
        if (!(std::cin >> s2) || s2 == "exit") 
            break;

        if (handleCommand(s2))
            continue;
            
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
        recordHistory(exprString(a, op, b, result));
    }

    return 0;
}

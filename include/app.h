#pragma once
#include <string>
#include <vector>
 #include "ops.h"
#include "calculator.h"
#include "parser.h"

// The purpose of the app manages the command line interface loop
// This is the only place that does the input and output prompts or print
// It uses the parser to validate the inputs and Calculator to compute.
// It also allows 'exit' at operator prompt by reading a string

class App {
public:
    // Runs the interactive calculator. Returns 0 on normal exit.
    int run();

private:
    Calculator calc_;
    Parser parser_;

    // History Calculator Functionality
    std::vector<std::string> history_; // This stores the final result in here
    static constexpr std::size_t historyLimit = 100; //cap the limit of how much it can store
    void recordHistory(const std::string& line);
    void printHistory() const;
    void clearHistory();

    // Normal Calculator Functionality
    //This is to format the final calculation in away that it is easy for the user to read.
    static void printExpr(double a, Operation op, double b, double result);
    static std::string exprString(double a, Operation op, double b, double result); // for history

    bool handleCommand(const std::string& input);
};

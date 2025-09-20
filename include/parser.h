#pragma once
#include <string>
#include "calculator.h"

// It allows App to focused on control flow.
// Creates a structured format for the program to use

class Parser {
public:
    // Parses a string into a double using stringstreams (no exceptions).
    bool parseNumber(const std::string& s, double& out) const;

    // Parses a single-char operator into Operation. Returns false with error if invalid.
    bool parseOperation(char c, Operation& out, std::string& error) const;
};

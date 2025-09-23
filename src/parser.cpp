#include "../include/parser.h"
#include <sstream>

bool Parser::parseNumber(const std::string& s, double& out) const 
{
    std::stringstream ss(s);
    ss >> out;
    return !ss.fail() && ss.eof();
}

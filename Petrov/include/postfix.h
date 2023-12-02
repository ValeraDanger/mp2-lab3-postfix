#pragma once

#include <string>
#include <vector>
#include <utility>
#include <map>
#include "stack.h"

class TArithmeticExpression {
private:
    std::string infix;
    std::string postfix;

    std::vector<char> lexemes;
    std::map<char, int> priority;
    std::map<char, double> operands;

    void parse();
    void toPostfix();

public:
    TArithmeticExpression(std::string expression = "");

    std::string getInfix() const { return infix; }
    std::string getPostfix() const { return postfix; }

    std::vector<char> getOperands() const;
    double calculate();
};
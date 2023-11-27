#include <iostream>
#include <string>
#include "postfix.h"

int main() {
	std::string expression = "((2+7)/2)-(2+4)/2";  // -1
	double res = 0.0;

	//std::cout << "Enter expression: ";
	//std::getline(std::cin, expression);
	TArithmeticExpression postfix(expression);
	std::cout << expression << std::endl;
	std::cout << "Expression: " << postfix.getInfix() << std::endl;
	std::cout << "Postfix: " << postfix.getPostfix() << std::endl;
	res = postfix.calculate();
	std::cout << "Result: " << res << std::endl;

	return 0;
}

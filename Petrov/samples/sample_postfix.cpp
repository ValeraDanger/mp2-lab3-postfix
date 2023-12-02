#include <iostream>
#include <string>
#include "postfix.h"

int main() {
	std::string expression = "(8+7+0-3*4)/7+3*4"; 
	double res = 0.0;

	TArithmeticExpression postfix(expression);
	std::cout << expression << std::endl;
	std::cout << "Expression: " << postfix.getInfix() << std::endl;
	std::cout << "Postfix: " << postfix.getPostfix() << std::endl;
	res = postfix.calculate();
	std::cout << "Result: " << res << std::endl;

	return 0;
}

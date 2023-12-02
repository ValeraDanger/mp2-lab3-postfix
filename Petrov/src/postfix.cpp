#include "postfix.h"

void TArithmeticExpression::parse() {
	for (char c : infix) {
		lexemes.push_back(c);
	}
}

void TArithmeticExpression::toPostfix() {
	parse();
	Stack<char> stack;
	char stackItem;

	for (char item : lexemes) {
		switch (item) {
		case '(':
			stack.push(item);
			break;

		case ')':
			stackItem = stack.top();
			stack.pop();
			while (stackItem != '(') {
				postfix += stackItem;
				stackItem = stack.top();
				stack.pop();
			}
			break;

		case '+': case '-': case '*': case '/':
			while (!stack.isEmpty()) {
				stackItem = stack.top();
				stack.pop();
				if (priority[item] <= priority[stackItem]) {
					postfix += stackItem;
				}
				else {
					stack.push(stackItem);
					break;
				}
			}
			stack.push(item);
			break;

		default:
			operands.insert({ item, item - '0'});  //converting <char> item to <int>
			postfix += item;
			break;
		}
	}
	while (!stack.isEmpty()) {
		stackItem = stack.top();
		stack.pop();
		postfix += stackItem;
	}

}

TArithmeticExpression::TArithmeticExpression(std::string expression) : infix(expression) {
	priority = { { '+', 1}, {  '-', 1}, { '*', 2}, { '/', 2}, { '(', 0 } };
	toPostfix();
}

std::vector<char> TArithmeticExpression::getOperands() const {
	std::vector<char> op;
	for (const auto& item : operands) {
		op.push_back(item.first);
	}
	return op;
}

double TArithmeticExpression::calculate() {
	Stack<double> stack;
	double leftOperand, rightOperand;

	for (char lexem : postfix) {
		switch (lexem) {
		case '+':
			rightOperand = stack.top();
			stack.pop();
			leftOperand = stack.top();
			stack.pop();
			stack.push(leftOperand + rightOperand);
			break;
		case '-':
			rightOperand = stack.top();
			stack.pop();
			leftOperand = stack.top();
			stack.pop();
			stack.push(leftOperand - rightOperand);
			break;
		case '*':
			rightOperand = stack.top();
			stack.pop();
			leftOperand = stack.top();
			stack.pop();
			stack.push(leftOperand * rightOperand);
			break;
		case '/':
			rightOperand = stack.top();
			stack.pop();
			leftOperand = stack.top();
			stack.pop();
			stack.push(leftOperand / rightOperand);
			break;

		default:
			std::cout << operands[lexem] << std::endl;
			stack.push(operands[lexem]);
			//std::cout << stack << std::endl;
			break;
		}
	}

	return stack.top();
}
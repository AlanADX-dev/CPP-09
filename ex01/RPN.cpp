#include "RPN.hpp"

int RPNCalculator::evaluate(const std::string& expression)
{
	std::stack<int> operands;

	std::istringstream iss(expression);
	std::string token;

	while (iss >> token)
	{
		if (isdigit(token[0]))
		{
			int operand;
			std::istringstream(token) >> operand;
			operands.push(operand);
		}
		else if (isOperator(token))
		{
			if (operands.size() < 2)
			{
				std::cerr << "Error\n";
				return 0;
			}
			int operand2 = operands.top(); operands.pop();
			int operand1 = operands.top(); operands.pop();
			int result = makeOperation(token, operand1, operand2);
			operands.push(result);
		}
		else
		{
			std::cerr << "Error\n";
			return 0;
		}
	}

	if (operands.size() != 1) {
		std::cerr << "Error\n";
		return 0;
	}

	return operands.top();
}

bool RPNCalculator::isOperator(const std::string& token)
{
	return token == "+" || token == "-" || token == "*" || token == "/";
}

int RPNCalculator::makeOperation(const std::string& op, int operand1, int operand2)
{
	if (op == "+") return operand1 + operand2;
	if (op == "-") return operand1 - operand2;
	if (op == "*") return operand1 * operand2;
	if (op == "/") {
		if (operand2 == 0)
		{
			std::cerr << "Error\n";
			return 0;
		}
		return operand1 / operand2;
	}
	return 0;
}

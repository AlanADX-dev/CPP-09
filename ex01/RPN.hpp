#ifndef RPN_HPP
#define RPN_HPP

#include <string>
#include <stack>
#include <iostream>
#include <sstream>
#include <stdexcept>

class RPNCalculator {

	private:
		static bool isOperator(const std::string& token);
		static int makeOperation(const std::string& op, int operand1, int operand2);

	public:
		static int evaluate(const std::string& expression);

};

#endif

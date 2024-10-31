#ifndef RPN_HPP
#define RPN_HPP

#include <stack>
#include <string>

class RPN
{
private:
	std::stack<int> _stack;

	bool isOperator(const std::string &token) const;
	int performOperation(const std::string &op, int a, int b) const;

public:
	RPN();
	RPN(const RPN &other);
	RPN &operator=(const RPN &other);
	~RPN();

	int evaluate(const std::string &expression);
};

#endif

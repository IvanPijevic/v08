#include "app.h"

namespace vsite::oop::v8
{
	int input_num(std::istream& is)
	{
		int number;
		is >> number;
		if (is.fail())
		{
			throw not_number();
		}

		return number;
	}

	char input_op(std::istream& is)
	{
		char op;
		std::string str = "+-*/";

		is >> op;
		if (str.find(op) == std::string::npos)
			throw not_operator();

		return op;
	}

	double calc(int n1, char op, int n2)
	{
		switch (op)
		{
		case '+':
			return n1 + n2;

		case '-':
			return n1 - n2;

		case '*':
			return n1 * n2;

		case '/':
			if (n2 == 0) {
				throw divide_zero();
			}
			return static_cast<double>(n1) / n2;

		default:
			throw not_operator();
		}
	}
}
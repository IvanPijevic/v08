#pragma once

#include <string>
#include <iostream>

namespace vsite::oop::v8
{
	int input_num(std::istream& is);

	char input_op(std::istream& is);

	double calc(int n1, char op, int n2);

	class base_exception
	{
	public:
		virtual std::string message() const = 0;
		virtual ~base_exception() = default;

		//protected:
		//	std::string errorMsg;
	};

	class not_operator : public base_exception
	{
	public:
		std::string message() const override
		{
			return "Operator error";
		}
	};

	class not_number : public base_exception
	{
	public:
		std::string message() const override
		{
			return "Number error";
		}
	};

	class divide_zero : public base_exception
	{
	public:
		std::string message() const override
		{
			return "Zero error";
		}
	};
}
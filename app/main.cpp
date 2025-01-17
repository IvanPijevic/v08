#include "app.h"

// read and evaluate expression inside endless loop 
// break after first exception (use one catch clause), show error description

using namespace vsite::oop::v8;

enum class State
{
	RUN, STOP
};

int main()
{
	State programState = State::RUN;

	while (programState != State::STOP)
	{
		try
		{
			int n1 = input_num(std::cin);
			char op = input_op(std::cin);
			int n2 = input_num(std::cin);
			float out = calc(n1, op, n2);

			std::cout << n1 << op << n2 << '=' << out;
		}

		catch (const base_exception& exception)
		{
			std::cout << exception.message();
			break;
		}
	}
}

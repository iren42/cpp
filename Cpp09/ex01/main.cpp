#include "RPN.hpp"

int	main(int ac, char *av[])
{
	try
	{
		if (ac != 2)
			throw std::runtime_error(ERR_ARG);
		if (RPN::parse(av[1]) == false)
			throw std::runtime_error(ERR_NOT_A_RPN_EXPR);
		RPN rpn;
		std::cout << rpn.calc(av[1]) << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
		return (1);
	}
	return (0);
}

#include "RPN.hpp"

//		std::cout << << std::endl;
RPN::~RPN()
{
	std::cout << "RPN Destructor called" << std::endl;
}

RPN::RPN()
{
	std::cout << "RPN Default constructor called" << std::endl;

}


RPN::RPN(const RPN &other)
{
	std::cout << "RPN Copy constructor called" << std::endl;
	(*this) = other;
}

RPN &RPN::operator=(const RPN &other)
{
	std::cout << "RPN Copy assignment constructor called" << std::endl;
	return (*this);
}

int	RPN::calc(const char* s)
{
	return (0);
}

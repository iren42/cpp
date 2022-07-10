#ifndef BRAIN_HPP 
# define BRAIN_HPP

#include <iostream>
//# define DEBUG

class Brain
{
	protected:
		std::string	ideas[100];

	public:
		~Brain();
		Brain();
		Brain(const Brain &other);
		Brain &operator = (const Brain &other);


};

#endif

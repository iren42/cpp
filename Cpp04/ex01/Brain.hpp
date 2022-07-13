#ifndef BRAIN_HPP 
# define BRAIN_HPP

#include <iostream>
#include <cstdlib>
#include <ctime>
//# define DEBUG

class Brain
{
	private:
		std::string	ideas[100];

	public:
		~Brain();
		Brain();
		Brain(const Brain &other);
		Brain &operator = (const Brain &other);

};

#endif

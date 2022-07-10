#ifndef DOG_HPP
# define DOG_HPP

#include <iostream>
#include "Animal.hpp"
//# define DEBUG

class Dog: public Animal
{

	public:
		~Dog();
		Dog();
		Dog(const Dog &other);
		Dog &operator = (const Dog &other);
		void	makeSound(void) const;
};

#endif

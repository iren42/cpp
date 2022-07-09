#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>
//# define DEBUG

class Animal
{
	protected:
		std::string	type;

	public:
		virtual ~Animal();
		Animal();
		Animal(const Animal &other);
		Animal &operator = (const Animal &other);

		std::string		getType(void) const;
		virtual void	makeSound(void) const;
};

#endif

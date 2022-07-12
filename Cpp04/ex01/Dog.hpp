#ifndef DOG_HPP
# define DOG_HPP

# include <iostream>
# include "Animal.hpp"
# include "Brain.hpp"

//# define DEBUG

class Dog: public Animal
{
	private:
		Brain	*brain;

	public:
		virtual ~Dog();
		Dog();
		Dog(const Dog &other);
		Dog &operator = (const Dog &other);
		void	makeSound(void) const;
};

#endif

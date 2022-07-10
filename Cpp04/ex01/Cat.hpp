#ifndef CAT_HPP
# define CAT_HPP

#include <iostream>
#include "Animal.hpp"
#include "Brain.hpp"
//# define DEBUG

class Cat: public Animal
{
	private:
		Brain	*brain;

	public:
		~Cat();
		Cat();
		Cat(const Cat &other);
		Cat &operator = (const Cat &other);
		void	makeSound(void) const;
};

#endif

#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

#include <iostream>
#include "WrongAnimal.hpp"
//# define DEBUG

class WrongCat: public WrongAnimal
{

	public:
		~WrongCat();
		WrongCat();
		WrongCat(const WrongCat &other);
		WrongCat &operator = (const WrongCat &other);
		void	makeSound(void) const;
};

#endif

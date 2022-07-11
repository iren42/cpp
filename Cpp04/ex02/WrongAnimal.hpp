#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

#include <iostream>
//# define DEBUG

class WrongAnimal
{
	protected:
		std::string	type;

	public:
		virtual ~WrongAnimal();
		WrongAnimal();
		WrongAnimal(const WrongAnimal &other);
		WrongAnimal &operator = (const WrongAnimal &other);

		std::string		getType(void) const;
		void	makeSound(void) const;
};

#endif

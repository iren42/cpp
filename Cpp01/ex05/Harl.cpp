/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isabelle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 17:22:39 by isabelle          #+#    #+#             */
/*   Updated: 2022/07/05 19:17:44 by isabelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

// Constructor
Harl::Harl()
{
#ifdef DEBUG
	std::cerr << "Harl created" << std::endl;
#endif
}

// Destructor
Harl::~Harl()
{
#ifdef DEBUG
	std::cerr << "Harl destroyed" << std::endl;
#endif
}

// Functions
void	Harl::debug(void)
{
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl;
}

void	Harl::warning(void)
{
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
}

void	Harl::info(void)
{
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void	Harl::error(void)
{
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void	Harl::complain(std::string level)
{
	/*	
		Same thing as:
		void	(Harl::*harlFunction[4])() = {
		&Harl::debug, &Harl::warning, &Harl::info, &Harl::error
		};
	 */
	typedef void(Harl::*harlFunction)();
	int					i;
	const std::string	levels[] = {
		"DEBUG", "WARNING", "INFO", "ERROR"
	};
	const harlFunction	functions[] = {
		&Harl::debug, &Harl::warning, &Harl::info, &Harl::error
	};

	i = 0;
	while (i < 4)
	{
		if (level == levels[i])
		{
			(this->*functions[i])();
			break ;
		}
		i++;
	}
}

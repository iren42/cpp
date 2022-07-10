/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isabelle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 23:18:40 by isabelle          #+#    #+#             */
/*   Updated: 2022/07/10 16:33:36 by iren             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>
#include <limits>
#include <cctype>

#include "Contact.hpp"


class	PhoneBook
{
	private:
		Contact	c[8];
		int		nbContacts;

	public:
		void	add();
		void	search();
		void	exit();
		PhoneBook();
		~PhoneBook();

};

#endif

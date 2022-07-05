/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isabelle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 23:18:40 by isabelle          #+#    #+#             */
/*   Updated: 2022/07/02 21:55:13 by isabelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>
#include <cstdlib>
#include <limits>
#include <cctype>

#include "Contact.hpp"

using namespace std;


class	PhoneBook
{
	private:
		Contact	c[8];
		int		nbContacts;

	public:
		void	add();
		void	search();
		void	exit();
		PhoneBook(): nbContacts(0){};
//		~PhoneBook();

};

#endif

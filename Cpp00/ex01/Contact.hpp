/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isabelle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 23:15:43 by isabelle          #+#    #+#             */
/*   Updated: 2022/07/02 18:40:39 by isabelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>

using namespace std;

class	Contact
{
	private:
		string	firstname;
		string	lastname;
		string	nickname;
		int		phoneNumber;
		string	secret;

	public:
		Contact();
		~Contact();
		void	setFirstname(string newName);
		void	setLastname(string newName);
		void	setNickname(string newName);
		void	setPhoneNumber(int newNb);
		void	setSecret(string newSecret);
		string	getFirstname();
		string	getLastname();
		string	getNickname();
		string	getSecret();
		int		getPhoneNumber();
		void	display();
};

#endif

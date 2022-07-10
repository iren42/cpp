/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isabelle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 23:15:43 by isabelle          #+#    #+#             */
/*   Updated: 2022/07/10 16:17:03 by iren             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>

class	Contact
{
	private:
		std::string	firstname;
		std::string	lastname;
		std::string	nickname;
		std::string	secret;
		unsigned long int	phoneNumber;

	public:
		Contact();
		~Contact();
		void		setFirstname(std::string newName);
		void		setLastname(std::string newName);
		void		setNickname(std::string newName);
		void		setPhoneNumber(unsigned long int newNb);
		void		setSecret(std::string newSecret);
		std::string	getFirstname();
		std::string	getLastname();
		std::string	getNickname();
		std::string	getSecret();
		unsigned long int	getPhoneNumber();
		void		display();
};

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: likong <likong@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 11:29:10 by likong            #+#    #+#             */
/*   Updated: 2024/09/26 09:53:13 by likong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <iostream>
#include <iomanip>

class Contact{
	private:
		std::string	_firstName;
		std::string	_lastName;
		std::string	_nickName;
		std::string	_phoneNumber;
		std::string	_darkestSecret;
		enum field{
			FIRSTNAME, LASTNAME, NICKNAME, PHONENUMBER, DARKESTSECRET	
		};
	
	public:
		Contact();
		std::string	getFirstName();
		std::string	getLastName();
		std::string	getNickName();

		void	printPrompt(int i);
		void	addContent(int i, std::string &str);
		void	printContact();
};

#endif

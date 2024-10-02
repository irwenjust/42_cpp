/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: likong <likong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 11:28:33 by likong            #+#    #+#             */
/*   Updated: 2024/10/01 20:35:28 by likong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook{
	private:
		Contact		contacts[8];
		int			_amount;
		int			_oldestContact;

		std::string	limitStr(const std::string &str);
		void		getContact(int index);
		void		displayAll();
	
	public:
		PhoneBook();
		void		addContact();
		void		searchContact(PhoneBook &phoneBook);
};

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: likong <likong@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 11:28:33 by likong            #+#    #+#             */
/*   Updated: 2024/09/26 09:54:15 by likong           ###   ########.fr       */
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
	
	public:
		PhoneBook();
		void		addContact();
		void		displayAll();
		std::string	limitStr(const std::string &str);
		void		searchContact(PhoneBook &phoneBook);
		void		getContact(int index);
};

#endif

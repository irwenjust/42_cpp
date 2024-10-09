/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: likong <likong@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 12:42:43 by likong            #+#    #+#             */
/*   Updated: 2024/10/08 18:54:29 by likong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>

class Brain{
	private:
		std::string _ideas[100];

	public:
		Brain();
		Brain(const Brain &other);
		~Brain();

		Brain	&operator = (const Brain &other);
};

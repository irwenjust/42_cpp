/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replaceFile.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: likong <likong@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 21:20:55 by likong            #+#    #+#             */
/*   Updated: 2024/09/30 10:50:09 by likong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

class ReplaceFile{
	private:
		std::string	_filename;
		std::string	_s1;
		std::string	_s2;
		std::string	_orignlContent;

		int	readFile(void);
		int	writeFile(const std::string &content);
	
	public:
		ReplaceFile(const std::string &filename,
					const std::string &s1,
					const std::string &s2,
					std::string	_orignlContent);
		int	replace(void);
};

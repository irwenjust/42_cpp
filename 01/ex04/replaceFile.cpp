/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replaceFile.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: likong <likong@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 21:20:43 by likong            #+#    #+#             */
/*   Updated: 2024/09/30 10:50:28 by likong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "replaceFile.hpp"

ReplaceFile::ReplaceFile(const std::string &filename, const std::string &s1,
						const std::string &s2, std::string	_orignlContent):
						_filename(filename), _s1(s1), _s2(s2), _orignlContent(_orignlContent){}

int	ReplaceFile::readFile(void){
	std::ifstream	inFile(this->_filename);
	if (!inFile){
		std::cout << "Unable to open this file\n";
		return 1;
	}
	std::stringstream	content;
	content << inFile.rdbuf();
	this->_orignlContent = content.str();
	return 0;
}

int	ReplaceFile::writeFile(const std::string &content){
	std::ofstream	outFile(this->_filename + ".replace");
	if (!outFile){
		std::cout << "Unable to create this file\n";
		return 1;
	}
	outFile << content;
	return 0;
}

int	ReplaceFile::replace(){
	std::string	newContent;
	size_t	i = 0;
	
	if (readFile())
		return 1;
	if (this->_orignlContent == ""){
		std::cout << "The source file is empty\n";
		return 1;
	}
	while (1){
		size_t	pos = _orignlContent.find(_s1, i);
		if (pos == std::string::npos)
			break ;
		try{
			newContent.append(_orignlContent, i, pos - i);
		}
		catch(const std::exception& e){
			std::cerr << "String length error: " << e.what() << '\n';
			return 1;
		}
		newContent += _s2;
		i = pos + _s1.length();
	}
	try{
			newContent.append(_orignlContent, i, std::string::npos);
		}
		catch(const std::exception& e){
			std::cerr << "String length error: " << e.what() << '\n';
			return 1;
		}
	if (writeFile(newContent))
		return 1;
	return 0;
}

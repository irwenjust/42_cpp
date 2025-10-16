/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: likong <likong@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 10:21:10 by likong            #+#    #+#             */
/*   Updated: 2025/10/15 10:21:10 by likong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "whatever.hpp"
#include <iostream>

int	main(void) {
	std::cout << "\n----------Int----------\n\n";
	
	int a = 2;
	int b = 3;
	
	::swap( a, b );
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min(a, b) = " << ::min( a, b ) << std::endl;
	std::cout << "max(a, b) = " << ::max( a, b ) << std::endl;
	
	std::cout << "\n----------String----------\n\n";
	std::string c = "chaine1";
	std::string d = "chaine2";
	
	::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min(c, d) = " << ::min( c, d ) << std::endl;
	std::cout << "max(c, d) = " << ::max( c, d ) << std::endl;

	std::cout << "\n----------Float----------\n\n";
	float e = -5.3f;
	float f = 3.6f;
	
	::swap( e, f );
	std::cout << "e = " << e << ", f = " << f << std::endl;
	std::cout << "min(e, f) = " << ::min( e, f ) << std::endl;
	std::cout << "max(e, f) = " << ::max( e, f ) << std::endl;

	std::cout << "\n----------Char----------\n\n";
	char g = 'A';
	char h = 'B';
	
	::swap( g, h );
	std::cout << "g = " << g << ", h = " << h << std::endl;
	std::cout << "min(g, h) = " << ::min( g, h ) << std::endl;
	std::cout << "max(g, h) = " << ::max( g, h ) << std::endl;

	return (0);
}
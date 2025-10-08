#include "whatever.hpp"
#include <iostream>

#define BLUE "\033[34m"
#define WHITE "\033[0m"

int	main(void) {
	std::cout << BLUE << "\n----------Test----------\n\n" << WHITE;
	
	std::cout << BLUE << "\n----------Int----------\n\n" << WHITE;
	
	int a = 2;
	int b = 3;
	
	::swap( a, b );
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min(a, b) = " << ::min( a, b ) << std::endl;
	std::cout << "max(a, b) = " << ::max( a, b ) << std::endl;
	
	std::cout << BLUE << "\n----------String----------\n\n" << WHITE;
	std::string c = "chaine1";
	std::string d = "chaine2";
	
	::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min(c, d) = " << ::min( c, d ) << std::endl;
	std::cout << "max(c, d) = " << ::max( c, d ) << std::endl;

	std::cout << BLUE << "\n----------Float----------\n\n" << WHITE;
	float e = -5.3f;
	float f = 3.6f;
	
	::swap( e, f );
	std::cout << "e = " << e << ", f = " << f << std::endl;
	std::cout << "min(e, f) = " << ::min( e, f ) << std::endl;
	std::cout << "max(e, f) = " << ::max( e, f ) << std::endl;

	std::cout << BLUE << "\n----------Char----------\n\n" << WHITE;
	char g = 'A';
	char h = 'B';
	
	::swap( g, h );
	std::cout << "g = " << g << ", h = " << h << std::endl;
	std::cout << "min(g, h) = " << ::min( g, h ) << std::endl;
	std::cout << "max(g, h) = " << ::max( g, h ) << std::endl;

	//std::cout << BLUE << "\n----------Diff type----------\n\n" << WHITE;
	//::swap(a, d);
	//std::cout << "a = " << a << ", d = " << d << std::endl;
	//std::cout << "min(a, d) = " << ::min( a, d ) << std::endl;
	//std::cout << "max(a, d) = " << ::max( a, d ) << std::endl;

	std::cout << BLUE << "\n----------Testing Done----------\n\n" << WHITE;
	return (0);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: likong <likong@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 18:23:20 by likong            #+#    #+#             */
/*   Updated: 2024/10/02 16:49:36 by likong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main( void ) {
    Fixed a;
    Fixed const b( 10 );
    Fixed const c( 42.42f );
    Fixed const d( b );

    a = Fixed( 1234.4321f );

    std::cout << "a is " << a << std::endl;
    std::cout << "b is " << b << std::endl;
    std::cout << "c is " << c << std::endl;
    std::cout << "d is " << d << std::endl;
    
    std::cout << "a is " << a.toInt() << " as integer" << std::endl;
    std::cout << "b is " << b.toInt() << " as integer" << std::endl;
    std::cout << "c is " << c.toInt() << " as integer" << std::endl;
    std::cout << "d is " << d.toInt() << " as integer" << std::endl;

    Fixed   e(8388607);
    Fixed   f(0.00390625f);
    Fixed   g(8388607.5f);
    Fixed   h(8388607.00390625f);

    std::cout << "e is " << e << std::endl;
    std::cout << "f is " << f << std::endl;
    std::cout << "g is " << g << std::endl;
    std::cout << std::fixed << std::setprecision(6) << "h is " << h << std::endl;
    
    std::cout << "e is " << e.toInt() << " as integer" << std::endl;
    std::cout << "f is " << f.toInt() << " as integer" << std::endl;
    std::cout << "g is " << g.toInt() << " as integer" << std::endl;
    std::cout << "h is " << h.toInt() << " as integer" << std::endl;

    std::cout << "e is " << e.toFloat() << " as floater" << std::endl;
    std::cout << "f is " << f.toFloat() << " as floater" << std::endl;
    std::cout << "g is " << g.toFloat() << " as floater" << std::endl;
    std::cout << "h is " << h.toFloat() << " as floater" << std::endl;
    return 0;
}

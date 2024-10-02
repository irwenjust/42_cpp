/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: likong <likong@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 18:23:33 by likong            #+#    #+#             */
/*   Updated: 2024/10/02 16:49:58 by likong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class Fixed{
    private:
        int                 _value;
        static const int    _fract_bits;

    public:
        Fixed();
        Fixed(const Fixed &other);
        Fixed   &operator=(const Fixed &number); 
        ~Fixed();

        int     getRawBits(void) const;
        void    setRawBits(int const raw);
};

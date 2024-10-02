/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: likong <likong@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 13:48:55 by likong            #+#    #+#             */
/*   Updated: 2024/10/02 16:49:52 by likong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Fixed.hpp"

class Point{
	private:
		const Fixed	x;
		const Fixed	y;
	
	public:
		Point();
		Point(const float x_value, const float y_value);
		Point(const Point &other);
		~Point();

		Point	&operator = (const Point &point);

		Fixed	getX() const;
		Fixed	getY() const;
};

bool bsp(Point const a, Point const b, Point const c, Point const point);

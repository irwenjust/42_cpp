/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: likong <likong@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 13:48:42 by likong            #+#    #+#             */
/*   Updated: 2024/10/02 16:49:51 by likong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point(): x(), y(){}

Point::Point(const float x_value, const float y_value): x(x_value), y(y_value){}

Point::Point(const Point &other): x(other.x), y(other.y){}

Point::~Point(){}

Point	&Point::operator = (const Point &point){
	(void)point;
	return (*this);
}

Fixed	Point::getX() const{
	return (this->x);
}

Fixed	Point::getY() const{
	return (this->y);
}

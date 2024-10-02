/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: likong <likong@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 13:49:05 by likong            #+#    #+#             */
/*   Updated: 2024/10/02 16:49:46 by likong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Fixed edgePoint(const Point& a, const Point& b, const Point& c){
	return ((a.getX() - c.getX()) * (b.getY() - c.getY())
			- (b.getX() - c.getX()) * (a.getY() - c.getY()));
}
bool	bsp(Point const a, Point const b, Point const c, Point const point)
{
	Fixed edgeABP = edgePoint(a, b, point);
	Fixed edgeBCP = edgePoint(b, c, point);
	Fixed edgeCAP = edgePoint(c, a, point);

	//Check the edge for each of cases
	std::cout << "ABP: " << edgeABP << std::endl;
	std::cout << "BCP: " << edgeBCP << std::endl;
	std::cout << "CAP: " << edgeCAP << std::endl;

	bool onEdge = (edgeABP == 0 || edgeBCP == 0 || edgeCAP == 0);
	bool inside = ((edgeABP > 0 && edgeBCP > 0 && edgeCAP > 0)
					|| (edgeABP < 0 && edgeBCP < 0 && edgeCAP < 0));
	return inside && !onEdge;
}

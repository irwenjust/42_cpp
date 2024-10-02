/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: likong <likong@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 18:23:20 by likong            #+#    #+#             */
/*   Updated: 2024/10/02 16:52:17 by likong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

bool bsp(Point const a, Point const b, Point const c, Point const point);

static void	checkPoint(Point const a, Point const b, Point const c,
			Point const test, const std::string &testName){
	if (bsp(a, b, c, test))
		std::cout << "Point " << testName << " is in the triangle\n";
	else
		std::cout << "Point " << testName << " is not in the triangle\n";
}

int main(void){
	Point	a(0.0f, 0.0f);
	Point	b(1.0f, 0.0f);
	Point	c(0.0f, 1.0f);
	Point	test1(0.49f, 0.49f);
	Point	test2(0.01f, 0.01f);
	Point	test3(0.5f, 0.5f);
	Point	test4(0.51f, 0.51f);
	Point	test5(1.0f, 0.0f);
	Point	test6(0.0f, 1.0f);

	checkPoint(a, b, c, test1, "test1");
	checkPoint(a, b, c, test2, "test2");
	checkPoint(a, b, c, test3, "test3");
	checkPoint(a, b, c, test4, "test4");
	checkPoint(a, b, c, test5, "test5");
	checkPoint(a, b, c, test6, "test6");

	return 0;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   line_intersection.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: mminkjan <mminkjan@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/03 16:31:11 by mminkjan       #+#    #+#                */
/*   Updated: 2020/02/04 12:21:37 by mminkjan      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

t_point	line_intersection(t_point p0, t_point p1, t_point p2, t_point p3)
{
	int		A_ray;
	int		B_ray;
	int		C_ray;
	int		A_wall;
	int		B_wall;
	int		C_wall;
	int		denominator;
	t_point	intersection;

	intersection.x = 0;
	intersection.y = 0;
	A_ray = p1.y - p0.y;
	B_ray = p0.x - p1.x;
	C_ray = A_wall * p0.x + B_ray * p0.y;
	A_wall = p3.y - p2.y;
	A_wall = p2.x - p3.x;
	C_wall = A_wall * p2.x + B_wall * p2.y;
	denominator = A_wall * B_wall - C_wall * B_wall;
	if (denominator == 0)
		return (intersection);
	intersection.x = (b2 * c1 - b1 * c2) / denominator;
	intersection.y = (a1 * c2 - a2 * b1) / denominator;
	return (intersection);
}

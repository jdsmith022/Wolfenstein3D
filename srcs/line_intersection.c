/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   line_intersection.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: mminkjan <mminkjan@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/03 16:31:11 by mminkjan       #+#    #+#                */
/*   Updated: 2020/02/05 13:41:56 by jesmith       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

t_point	line_intersection(t_point r_start, t_point r_end,
			t_point w_start, t_point w_end)
{
	int				denominator;
	t_point			intersection;
	t_intersection	p;

	intersection.x = 0;
	intersection.y = 0;
	p.a_ray = r_end.y - r_start.y;
	p.b_ray = r_start.x - r_end.x;
	p.c_ray = a_ray * r_start.x + b_ray * r_start.y;
	p.a_wall = w_end.y - w_start.y;
	p.b_wall = w_start.x - w_end.x;
	p.c_wall = a_wall * w_start.x + b_wall * w_start.y;
	denominator = A_ray * b_wall - a_wall * b_ray;
	if (denominator == 0)
		return (intersection);
	intersection.x = (p.b_wall * p.c_ray - p.b_ray * p.c_wall) / denominator;
	intersection.y = (p.a_ray * p.c_wall - p.a_wall * p.c_ray) / denominator;
	return (intersection);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   find_intersect.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: mminkjan <mminkjan@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/28 14:44:47 by mminkjan       #+#    #+#                */
/*   Updated: 2020/04/02 12:43:47 by Malou         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

static t_point		calculate_intersect_point(t_point start_a, t_point start_b,
						t_point slope_a, t_point slope_b)
{
	t_point			intersect;
	double			denominator;
	double			t;
	double			s;

	intersect.x = NAN;
	intersect.y = NAN;
	denominator = (-slope_b.x * slope_a.y + slope_a.x * slope_b.y);
	if ((int)denominator == 0)
		return (intersect);
	s = (-slope_a.y * (start_a.x - start_b.x) + slope_a.x * \
		(start_a.y - start_b.y)) / denominator;
	t = (slope_b.x * (start_a.y - start_b.y) - slope_b.y * \
		(start_a.x - start_b.x)) / denominator;
	if (s > 0 && s < 1 && t > 0 && t < 1)
	{
		intersect.x = start_a.x + (t * slope_a.x);
		intersect.y = start_a.y + (t * slope_a.y);
	}
	intersect.x = fabs(intersect.x);
	intersect.y = fabs(intersect.y);
	return (intersect);
}

t_point				find_intersection_point(t_point start_a, t_point end_a,
						t_point start_b, t_point end_b)
{
	t_point			slope_a;
	t_point			slope_b;

	slope_a.x = end_a.x - start_a.x;
	slope_a.y = end_a.y - start_a.y;
	slope_b.x = end_b.x - start_b.x;
	slope_b.y = end_b.y - start_b.y;
	return (calculate_intersect_point(start_a, start_b, slope_a, slope_b));
}

static double		find_intersect_distance(t_point intersect,
						t_item ray, double angle)
{
	double			distance;

	if (fabs(intersect.x - ray.start.x) > fabs(intersect.y - (int)ray.start.y))
		distance = (intersect.x - ray.start.x) / cos(angle);
	else
		distance = (intersect.y - ray.start.y) / sin(angle);
	return (distance);
}

t_point				find_intersect(t_wolf *wolf, t_item ray, double angle)
{
	t_point			intersect;
	t_point			min_intersect;
	t_item			*object;
	double			distance;
	double			min_distance;

	object = wolf->item;
	min_distance = INFINITY;
	while (object != NULL)
	{
		intersect = find_intersection_point(ray.start, ray.end,\
			object->start, object->end);
		distance = find_intersect_distance(intersect, ray, angle);
		if (distance < min_distance && distance > 0)
		{
			min_distance = distance;
			min_intersect.x = intersect.x;
			min_intersect.y = intersect.y;
			min_intersect.obj_dist = distance;
			min_intersect.texture = object->texture;
			min_intersect.dir = object->dir;
			// draw_ray(wolf, ray.start, intersect, 0xfc03ad);// red
		}
		object = object->next;
	}
	return (min_intersect);
}

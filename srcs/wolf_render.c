/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   wolf_render.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: mminkjan <mminkjan@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/10 18:48:15 by mminkjan       #+#    #+#                */
/*   Updated: 2020/02/11 12:30:43 by mminkjan      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

t_point			ray_intersection(t_wolf *wolf)
{
	t_object	*object;
	t_point		intersect;
	t_point		min_intersect;
	double		distance;
	double		min_distance;

	object = wolf->object;
	min_distance = wolf->win_width;
	while (object != NULL)
	{
		intersect = line_intersection(wolf->pos, wolf->dir,\
		object->start, object->end);
		wolf->form.delta_x = intersect.x - wolf->pos.x;
		wolf->form.delta_y = intersect.y - wolf->pos.y;
		distance = sqrt(wolf->form.delta_x + wolf->form.delta_y);
		if (distance < min_distance)
		{
			min_distance = distance;
			min_intersect = intersect;
		}
		object = object->next;
	}
	return (min_intersect);
}

void	line_render(t_wolf *wolf)
{
	t_point		ray;
	t_point 	intersection;
	// t_object	object;

	ray = set_ray(wolf)
	intersection = ray_intersection(wolf);
}

int		wolf_render(t_wolf *wolf)
{
	line_render(wolf);
	mlx_hook(wolf->win_ptr, 2, 0, key_events, wolf);
	mlx_hook(wolf->win_ptr, 17, 0, wolf_success_exit, wolf);
	return (0);
}

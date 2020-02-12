/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   wolf_render.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: mminkjan <mminkjan@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/10 18:48:15 by mminkjan       #+#    #+#                */
/*   Updated: 2020/02/12 17:56:25 by mminkjan      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

t_point			ray_intersection(t_wolf *wolf)
{
	t_item		*item;
	t_point		intersect;
	t_point		min_intersect;
	double		distance;
	double		min_distance;

	item = wolf->item;
	min_distance = INFINITY;
	while (item != NULL)
	{
		intersect = line_intersection(wolf->pos, wolf->ray,\
		item->start, item->end);
		wolf->form.delta_x = intersect.x - wolf->pos.x;
		wolf->form.delta_y = intersect.y - wolf->pos.y;
		distance = sqrt(wolf->form.delta_x + wolf->form.delta_y);
		if (distance < min_distance)
		{
			min_distance = distance;
			min_intersect = intersect;
			min_intersect.texture = item->texture;
		}
		item = item->next;
	}
	return (min_intersect);
}

void	ray_render(t_wolf *wolf)
{
	t_point		ray;
	t_point		intersect;
	int			x;
	double		camera_x;

	x = 0;
	while (x < WIDTH)
	{
		camera_x = 2 * x / (double)WIDTH - 1;
		wolf->ray.x = wolf->dir.x + wolf->plane.x * camera_x * wolf->max_ray;
		wolf->ray.y = wolf->dir.y + wolf->plane.y * camera_x * wolf->max_ray;
		intersect = ray_intersection(wolf);
		draw_collllllllumn(wolf, intersect);
		x++;
	}
}

int		wolf_render(t_wolf *wolf)
{
	ray_render(wolf);
	mlx_hook(wolf->win_ptr, 2, 0, key_events, wolf);
	mlx_hook(wolf->win_ptr, 17, 0, wolf_success_exit, wolf);
	return (0);
}

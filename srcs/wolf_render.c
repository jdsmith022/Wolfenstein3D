/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   wolf_render.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: mminkjan <mminkjan@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/10 18:48:15 by mminkjan       #+#    #+#                */
/*   Updated: 2020/02/18 12:44:29 by jesmith       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

t_item			calculate_wall_distance(t_wolf *wolf,
					t_point intersect, double camera_x)
{
	t_item		wall;
	double		wall_dist;
	double		intersect_dist;
	double		cam_dist;
	double		h;

	cam_dist = fabs(intersect.x - camera_x);
	intersect_dist = sqrt(wolf->form.delta_x + wolf->form.delta_y);
	wall_dist = fabs(intersect_dist * intersect_dist + cam_dist * cam_dist);
	wall_dist = sqrt(wall_dist);
	// wall_dist = (wolf->pos.y - camera_x) / wolf->ray.y;
	h = wolf->wall_height / wall_dist;
	wall.start.y = -h / 2 + wall_dist / 2;
	wall.end.y = h / 2 + wall_dist / 2;
	wall.texture = intersect.texture;
	// printf("start = %f | end = %f\n", wall.start.y, wall.end.y);
	return (wall);
}

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
		// printf("while %f, %f\n", item->start.x, item->start.y);
		intersect = line_intersection(wolf->pos, wolf->ray,\
		item->start, item->end);
		wolf->form.delta_x = sqrt(1 + (intersect.y * intersect.y) / (intersect.x * intersect.x));//fabs(1 / intersect.x - wolf->pos.x); 
		wolf->form.delta_y = sqrt(1 + (intersect.x * intersect.x) / (intersect.y * intersect.y));//fabs(1 / intersect.y - wolf->pos.y); //
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
	t_point		intersect;
	t_item		wall;
	int			x;
	double		camera_x;

	x = 0;
	while (x < WIDTH)
	{
		camera_x = 2 * x / (double)WIDTH - 1;
		wolf->ray.x = wolf->dir.x + wolf->plane.x * camera_x * wolf->max_ray;
		wolf->ray.y = wolf->dir.y + wolf->plane.y * camera_x * wolf->max_ray;
		intersect = ray_intersection(wolf);
		wall = calculate_wall_distance(wolf, intersect, camera_x);
		draw_column(wolf, wall, x);
		x++;
	}
}

int		wolf_render(t_wolf *wolf)
{
	ray_render(wolf);
	mlx_hook(wolf->win_ptr, 2, 0, key_events, wolf);
	mlx_hook(wolf->win_ptr, 17, 0, wolf_success_exit, wolf);
	mlx_put_image_to_window(wolf->mlx_ptr,
		wolf->win_ptr, wolf->image_ptr, 0, 0);
	return (0);
}

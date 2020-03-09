/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   wolf_engine.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: jesmith <jesmith@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/19 11:40:53 by jesmith        #+#    #+#                */
/*   Updated: 2020/03/09 14:35:14 by jesmith       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

static void			project_on_plane(t_wolf *wolf, t_point intersect,
	t_project *plane, int x)
{
	double			height;

	intersect.obj_dist *= cos(wolf->ray_angle * x - FOV / 2);
	if (intersect.obj_dist < 20)
		wolf->bound = 1;
	height = wolf->wall_height / intersect.obj_dist * wolf->dist_to_plane;
	plane->y_start = HEIGHT / 2 - height / 2;
	plane->y_end = HEIGHT / 2 + height / 2;
}

double		clamp_angle(double angle)
{
	if (angle > 360 * (PI / 180))
		angle -= 360 * (PI / 180);
	else if (angle < 0)
		angle += 360 * (PI / 180);
	return (angle);
}

static void			wolf_render(t_wolf *wolf)
{
	double		angle;
	t_item		ray;
	t_project	plane;
	int			x;

	x = 0;
	angle = wolf->dir_angle - (FOV / 2);
	ray.start.x = wolf->pos.x;
	ray.start.y = wolf->pos.y;
	while (x < WIDTH)
	{
		angle = clamp_angle(angle);
		ray.end.x = ray.start.x + wolf->max_ray * cos(angle);
		ray.end.y = ray.start.y + wolf->max_ray * sin(angle);
		wolf->intersect = find_intersect(wolf, ray, wolf->height, angle);
		project_on_plane(wolf, wolf->intersect, &plane, x);
		// draw_column(wolf, plane, x);
		angle += wolf->ray_angle;
		x++;
	}
}

int				wolf_engine(t_wolf *wolf)
{
	wolf_render(wolf);
	mlx_key(wolf);
	mlx_mouse(wolf);
	flat_draw(wolf);
	// mlx_put_image_to_window(wolf->mlx_ptr,
	// 	wolf->win_ptr, wolf->image_ptr, 0, 0);
	ft_bzero(wolf->addr_str, (wolf->bits_ppixel / 8) * HEIGHT * WIDTH);
	return (0);
}

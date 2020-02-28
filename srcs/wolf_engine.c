/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   wolf_engine.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: jesmith <jesmith@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/19 11:40:53 by jesmith        #+#    #+#                */
/*   Updated: 2020/02/28 16:53:32 by mminkjan      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

static double		correct_distortion(t_wolf *wolf, double angle,
						double distance, int x)
{
	double a;
	double c;
	double b;
	(void)angle;
	(void)wolf;

	a = (WIDTH / 2 - x) * (WIDTH / 2 - x);
	c = distance * distance;
	b = c - a;
	return (sqrt(b));
}

static double		clerp_angle(double angle)
{
	if (angle > 360 * (PI / 180))
		angle -= 360 * (PI / 180);
	else if (angle < 0)
		angle += 360 * (PI / 180);
	return (angle);
}

static void			wolf_render(t_wolf *wolf)
{
	double		ray_angle;
	double		angle;
	t_item		ray;
	t_point		intersect;
	t_height	plane_project;
	int			x;
	double		height;

	x = 0;
	ray_angle = FOV / WIDTH;
	angle = wolf->dir_angle - (FOV / 2);
	while (x < WIDTH)
	{
		angle = clerp_angle(angle);
		ray.start.x = wolf->pos.x;
		ray.start.y = wolf->pos.y;
		ray.end.x = ray.start.x + wolf->max_ray * cos(angle);
		ray.end.y = ray.start.y + wolf->max_ray * sin(angle);
		if (ray.start.x == ray.end.x || ray.start.y == ray.end.y)
		{
			ray.end.y = 600;
			ray.end.x = 1200;
		}
		angle += ray_angle;
		intersect = find_intersect(wolf, ray, wolf->height, angle);
		intersect.obj_dist = correct_distortion(wolf, angle, intersect.obj_dist, x);
		height = wolf->wall_height / intersect.obj_dist * 255;
		plane_project.y_start = wolf->wall_height / 2 - height / 2;
		plane_project.y_end = wolf->wall_height / 2 + height / 2;
		draw_column(wolf, plane_project, x);
		x++;
	}
}

int				wolf_engine(t_wolf *wolf)
{
	wolf_render(wolf);
	mlx_key(wolf);
	mlx_mouse(wolf);
	flat_draw(wolf);
	mlx_put_image_to_window(wolf->mlx_ptr,
		wolf->win_ptr, wolf->image_ptr, 0, 0);
	ft_bzero(wolf->addr_str, (wolf->bits_ppixel / 8) * HEIGHT * WIDTH);
	return (0);
}

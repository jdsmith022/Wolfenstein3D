/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   wolf_render.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: jesmith <jesmith@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/19 11:40:53 by jesmith        #+#    #+#                */
/*   Updated: 2020/02/26 13:29:59 by mminkjan      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

static t_point		calculate_intersect(t_point start_a, t_point start_b,
						t_point slope_a, t_point slope_b)
{
	t_point		intersect;
	double		denominator;
	double		t;
	double		s;

	intersect.x = NAN;
	intersect.y = NAN;
	denominator = (-slope_b.x * slope_a.y + slope_a.x * slope_b.y);
	if (denominator == 0)
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
	return (intersect);
}

static t_point		intersect_point(t_point start_a, t_point end_a,
						t_point start_b, t_point end_b)
{
	t_point intersect;
	t_point slope_a;
	t_point slope_b;

	intersect.x = 0;
	intersect.y = 0;
	slope_a.x = end_a.x - start_a.x;
	slope_a.y = end_a.y - start_a.y;
	slope_b.x = end_b.x - start_b.x;
	slope_b.y = end_b.y - start_b.y;
	return (calculate_intersect(start_a, start_b, slope_a, slope_b));
}

static t_point		find_intersect(t_wolf *wolf, t_item ray, int prev_height, double angle)
{
	t_point intersect;
	t_point	min_intersect;
	t_item	*object;
	double	distance;
	double	min_distance;

	(void)prev_height;
	object = wolf->item;
	min_distance = INFINITY;
	while (object != NULL)
	{
		intersect = \
			intersect_point(ray.start, ray.end, object->start, object->end);
		if (angle < wolf->dir_angle)
			distance = fabs(ray.start.x - intersect.x) / cos(-angle);
		else
			distance = fabs(ray.start.x - intersect.x) / cos(angle);
		if (distance < min_distance)
		{
			min_distance = distance;
			min_intersect.x = intersect.x;
			min_intersect.y = intersect.y;
			min_intersect.obj_dist = distance;
			min_intersect.texture = object->texture;
			draw_ray(wolf, ray.start, intersect, 0xfc03ad);// red
		}
		object = object->next;
	}
	return (min_intersect);
}

static double		clerp_angle(double angle)
{
	if (angle > 360 * (PI / 180))
		angle -= 360 * (PI / 180);
	else if (angle < 0)
		angle += 360 * (PI / 180);
	return (angle);
}

static void			render_wolf(t_wolf *wolf)
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
		angle += ray_angle;
		intersect = find_intersect(wolf, ray, wolf->height, angle);
		// if (angle < wolf->dir_angle)
		// 	intersect.obj_dist *= cos(-angle);
		// else
		// 	intersect.obj_dist *= cos(-angle);
		height = wolf->wall_height / intersect.obj_dist * 255;
		plane_project.y_start = wolf->wall_height / 2 - height / 2;
		plane_project.y_end = wolf->wall_height / 2 + height / 2;
		draw_column(wolf, plane_project, x);
		x++;
	}
}

int				wolf_render(t_wolf *wolf)
{
	render_wolf(wolf);
	mlx_key(wolf);
	mlx_mouse(wolf);
	flat_draw(wolf);
	mlx_put_image_to_window(wolf->mlx_ptr,
		wolf->win_ptr, wolf->image_ptr, 0, 0);
	ft_bzero(wolf->addr_str, (wolf->bits_ppixel / 8) * HEIGHT * WIDTH);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   wolf_render.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: jesmith <jesmith@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/19 11:40:53 by jesmith        #+#    #+#                */
/*   Updated: 2020/02/25 13:55:37 by jesmith       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

// static	t_height	intersect_distance(t_wolf *wolf,
// 						t_item ray, t_point intersect)
// {
// 	double		difference;
// 	double		plane_x;
// 	double		obj_dist;
// 	double		height;
// 	t_height	camera_plane;

// 	(void)wolf;
// 	difference = ray.start.x - intersect.x;
// 	plane_x = ray.start.x + difference;
// 	obj_dist = intersect.obj_dist * intersect.obj_dist - plane_x * plane_x;
// 	obj_dist = sqrt(obj_dist);
// 	// if (intersect.texture < 5)
// 	height = obj_dist * 0.577F;//wolf->wall_height / (obj_dist / 1.5);
// 	// else
// 	// 	height = wolf->obj_height
// 	camera_plane.y_start = -height / 2 + (obj_dist / 2 + wolf->player.y);
// 	camera_plane.y_end = height / 5 + (obj_dist / 5 - wolf->player.y);
// 	camera_plane.texture = intersect.texture;
// 	return (camera_plane);
// }

// static	double		ray_distance(t_item ray, t_point intersect)
// {
// 	double	distance;

// 	distance = fabs(ray.start.x - intersect.x) / cos(FOV / WIDTH);
	// double	delta_x;
	// double	delta_y;
	// double	delta_pwr_x;
	// double	delta_pwr_y;

	// delta_x = fabs(intersect.x - ray.start.x);
	// delta_y = fabs(intersect.y - ray.start.y);
	// delta_pwr_x = delta_x * delta_x;
	// delta_pwr_y = delta_y * delta_y;
	// distance = sqrt(delta_pwr_x + delta_pwr_y);
// 	return (distance);
// }

// static t_point		intersect_point(t_point r_start, t_point r_end,
// 						t_point o_start, t_point o_end, t_wolf *wolf)
// {
// 	// t_form	calc;
// 	t_point intersect;
// 	// double	angle;
// 	// double	denominator;

// 	intersect.x = 0;
// 	intersect.y = 0;
// 	double r_x;
// 	double r_y;
// 	double o_x;
// 	double o_y;

// 	r_x = r_end.x - r_start.x;
// 	r_y = r_end.y - r_start.y;
// 	o_x = o_end.x - o_start.x;
// 	o_y = o_end.y - o_start.y;

// 	double t;
// 	double s;

// 	s = (-r_y * (r_start.x - o_start.x) + r_x * (r_start.y - o_start.y)) / (-o_x * r_y + r_x * o_y);
// 	t = ( o_x * (r_start.y - o_start.y) - o_y * (r_start.x - o_start.x)) / (-o_x * r_y + r_x * o_y);
// 	if (s >= 0 && s <= 1 && t >= 0 && t <= 1)
// 	{
// 		intersect.x = r_start.x + (t * r_x);
// 		intersect.y = r_start.y + (t * r_y);
// 	}
// 	draw_ray(wolf, r_start, intersect, 0xfc03ad);// red
// 	return (intersect);
// 	// (void)wolf;
// 	// angle = wolf->dir_angle - (FOV / 2);
// 	// calc.a_ray = r_end.y - r_start.y;
// 	// calc.b_ray = r_end.x - r_start.x;
// 	// calc.c_ray = calc.a_ray * r_start.x + calc.b_ray * r_start.y;
// 	// calc.a_obj = o_end.y - o_start.y;
// 	// calc.b_obj = o_start.x - o_end.x;
// 	// calc.c_obj = calc.a_obj * o_start.x + calc.b_obj * o_start.y;
// 	// denominator = calc.a_ray * calc.b_obj - calc.a_obj * calc.b_ray;
// 	// if (denominator == 0)
// 	// 	return (intersect);
// 	// intersect.x = (calc.b_obj * calc.c_ray - calc.b_ray * calc.c_obj) / denominator;
// 	// intersect.y = (calc.a_ray * calc.c_obj - calc.a_obj * calc.c_ray) / denominator;
// 	return (intersect);
// }

static double		find_line_slope(t_point start, t_point end)
{
	if (start.x == end.x)
		return (NAN);
	return ((start.y - end.y) / (start.x - end.x));
}

static t_point		intersect_point(t_point startA, t_point endA,
						t_point startB, t_point endB, t_wolf *wolf)
{
	double slopeA;
	double	slopeB;
	// (void)wolf;
	t_point intersect;
	slopeA = find_line_slope(startA, endA);
	slopeB = find_line_slope(startB, endB);
	if (slopeA == slopeB)
	{
		intersect.x = NAN;
		intersect.y = NAN;
	}
	else if (slopeA == NAN && slopeB != NAN)
	{
		intersect.x = startA.x;
		intersect.y = (startA.x - startB.x) * slopeB + startB.y;
	}
	else if (slopeA != NAN && slopeB == NAN)
	{
		intersect.x = startB.x;
		intersect.y = (startB.x - startA.x) * slopeA + startB.y;
	}
	else
	{
		intersect.x = (slopeA * startA.x - slopeB * startB.x + startB.y - startA.y) / (slopeA - slopeB);
		intersect.y = slopeB * (intersect.x - startB.x) + startB.y;
	}
	draw_ray(wolf, startA, intersect, 0xfc03ad);// red
	return (intersect);
}

static t_point		find_intersect(t_wolf *wolf, t_item ray, int prev_height)
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
			intersect_point(ray.start, ray.end, object->start, object->end, wolf);
		distance = fabs(intersect.x - ray.start.x) / cos(FOV / WIDTH);
		// distance = ray_distance(ray, intersect);
		if (distance < min_distance)
		{
			min_intersect.x = intersect.x;
			min_intersect.y = intersect.y;
			min_intersect.obj_dist = distance;
			min_intersect.texture = object->texture;
		}
		object = object->next;
	}
	return (min_intersect);
}

static void			render_wolf(t_wolf *wolf)
{
	double	 	ray_angle;
	double		angle;
	t_item		ray;
	t_point		intersect;
	t_height	plane_intersect;
	int			x;
	double		height;

	x = 0;
	ray_angle = FOV / WIDTH;
	angle = wolf->dir_angle - (FOV / 2);
	while (x < WIDTH)
	{
		ray.start.x = wolf->pos.x;
		ray.start.y = wolf->pos.y;
		ray.end.x = ray.start.x + wolf->max_ray * cos(angle);
		ray.end.y = ray.start.y + wolf->max_ray * sin(angle);
		angle += ray_angle;
		intersect = find_intersect(wolf, ray, wolf->height);
		draw_ray(wolf, ray.start, ray.end, 0xfcd303); //tellow
		// draw_intercept(wolf, ray.start, intersect.x, intersect.y); // electric
		intersect.obj_dist *= cos(FOV / 2);
		// printf("%f\n", intersect.obj_dist);
		height = wolf->wall_height / intersect.obj_dist * 255;
		plane_intersect.y_start = wolf->wall_height / 2 - height / 2;
		plane_intersect.y_end = wolf->wall_height / 2 + height / 2;
		draw_column(wolf, plane_intersect, x);
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

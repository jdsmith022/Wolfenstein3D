/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   wolf_render.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: jesmith <jesmith@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/19 11:40:53 by jesmith        #+#    #+#                */
/*   Updated: 2020/02/22 19:39:53 by mminkjan      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

static	t_height	intersect_distance(t_wolf *wolf, t_item ray, t_point intersect)
{
	double		difference;
	double		plane_x;
	double		obj_dist;
	double		height;
	t_height	camera_plane;

	(void)wolf;
	difference = ray.start.x - intersect.x;
	plane_x = ray.start.x + difference;
	obj_dist = intersect.obj_dist * intersect.obj_dist - plane_x * plane_x;
	obj_dist = sqrt(obj_dist);
	// if (intersect.texture < 5)
	height = obj_dist * 0.577F;//wolf->wall_height / (obj_dist / 1.5);
	// else
	// 	height = wolf->obj_height
	camera_plane.y_start = -height / 2 + (obj_dist / 2 + wolf->player.y);
	camera_plane.y_end = height / 5 + (obj_dist / 5 - wolf->player.y);
	camera_plane.texture = intersect.texture;
	return (camera_plane);
}

static	double		ray_distance(t_item ray, t_point intersect)
{
	double	distance;
	double	delta_x;
	double	delta_y;
	double	delta_pwr_x;
	double	delta_pwr_y;

	delta_x = intersect.x - ray.start.x;
	delta_y = intersect.y - ray.start.y;
	delta_pwr_x = delta_x * delta_x;
	delta_pwr_y = delta_y * delta_y;
	distance = sqrt(delta_pwr_x + delta_pwr_y);
	return (distance);
}

static t_point		intersect_point(t_point r_start, t_point r_end,
					t_point o_start, t_point o_end)
{
	t_form	calc;
	t_point intersect;
	double	denominator;

	intersect.x = 0;
	intersect.y = 0;
	calc.a_ray = r_end.y - r_start.y;
	calc.b_ray = r_end.x - r_start.x;
	calc.c_ray = calc.a_ray * r_start.x + calc.b_ray * r_start.y;
	calc.a_obj = o_end.y - o_start.y;
	calc.b_obj = o_start.x - o_end.x;
	calc.c_obj = calc.a_obj * o_start.x + calc.b_obj * o_start.y;
	denominator = calc.a_ray * calc.b_obj - calc.a_obj * calc.b_ray;
	if (denominator == 0)
		return (intersect);
	intersect.x = (calc.b_obj * calc.c_ray - calc.b_ray * calc.c_obj) / denominator;
	intersect.y = (calc.a_ray * calc.c_obj - calc.a_obj * calc.c_ray) / denominator;
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
			intersect_point(ray.start, ray.end, object->start, object->end);
		distance = ray_distance(ray, intersect);
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
	double  	plane_x;
	t_item		ray;
	t_point		intersect;
	t_height	plane_intersect;
	int			x;

	x = 0;
	while (x < WIDTH)
	{
		plane_x = 2 * x / (double)WIDTH - 1;
		ray.start.x = wolf->dir.x - wolf->plane.x * plane_x + wolf->pos.x;
		ray.start.y = wolf->dir.y - wolf->plane.y * plane_x + wolf->pos.y;
		ray.end.x = ray.start.x * plane_x - wolf->pos.x + wolf->max_ray * (wolf->dir.x + wolf->dir.x);
		ray.end.y = ray.start.y * plane_x - wolf->pos.y + wolf->max_ray * wolf->dir.y;
		printf("%f - %f		%f - %f \n", ray.start.x, ray.start.y, ray.end.x, ray.end.y);
		draw_ray(wolf, ray.start, ray.end);
		intersect = find_intersect(wolf, ray, wolf->height);
		// if (intersect.texture <= 4)
		// 	wolf->height = wolf->wall_height;
		// else
		// 	wolf->height = wolf->obj_height; //func for different obj height alter width of  object here too
		plane_intersect = intersect_distance(wolf, ray, intersect);
		draw_column(wolf, plane_intersect, x);
		// if (wolf->height == wolf->wall_height)
			x++;
	}
}

int				wolf_render(t_wolf *wolf)
{
	render_wolf(wolf);
	mlx_hook(wolf->win_ptr, 2, 0, key_events, wolf);
	mlx_hook(wolf->win_ptr, 17, 0, wolf_success_exit, wolf);
	mlx_put_image_to_window(wolf->mlx_ptr,
		wolf->win_ptr, wolf->image_ptr, 0, 0);
	flat_draw(wolf);
	mlx_put_image_to_window(wolf->mlx_ptr2,
		wolf->win_ptr, wolf->image_ptr2, WIDTH, 0);
	// ft_bzero(wolf->addr_str, wolf->size_line * (wolf->bits_ppixel / 8));
	return (0);
}

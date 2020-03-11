/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   wolf_engine.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: jesmith <jesmith@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/19 11:40:53 by jesmith        #+#    #+#                */
/*   Updated: 2020/03/11 11:23:09 by jesmith       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

static size_t	texture_index(t_point intersect, t_point pos, int delta)
{
	size_t index;

	index = 0;
	if (intersect.y > pos.y && delta == 0)
		return (index);
	if (intersect.y < pos.y && delta == 0)
		index = 1;
	if (intersect.x > pos.x && delta == 1)
		index = 2;
	if (intersect.x < pos.x && delta == 1)
		index = 3;
	return (index);
}

static void		project_on_plane(t_wolf *wolf, t_point intersect,
					t_project *plane, int x)
{
	plane->delta = 0;
	intersect.obj_dist *= cos(wolf->ray_angle * x - FOV / 2);
	if (intersect.obj_dist < 20)
		wolf->bound = 1;
	plane->height = \
		wolf->wall_height / intersect.obj_dist * wolf->dist_to_plane;
	plane->y_start = HEIGHT / 2 - plane->height / 2;
	plane->y_end = HEIGHT / 2 + plane->height / 2;
	if ((int)wolf->intersect.x % 300 == 0)
	{
		plane->offset = (int)wolf->intersect.y % 300;
		plane->delta = 1;
	}
	else
		plane->offset = (int)wolf->intersect.x % 300;
}

double			clamp_angle(double angle)
{
	if (angle > 360 * (PI / 180))
		angle -= 360 * (PI / 180);
	else if (angle < 0)
		angle += 360 * (PI / 180);
	return (angle);
}

static void			wolf_render(t_wolf *wolf)
{
	int			x;
	double		angle;
	size_t		texdex;
	t_item		ray;
	t_project	plane;

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
		texdex = texture_index(wolf->intersect, wolf->pos, plane.delta);
		draw_column(wolf, plane, x, texdex);
		angle += wolf->ray_angle;
		x++;
	}
}

int					wolf_engine(t_wolf *wolf)
{
	wolf_render(wolf);
	mlx_key(wolf);
	mlx_mouse(wolf);
	flat_draw(wolf);
	mlx_put_image_to_window(wolf->mlx_ptr,
		wolf->win_ptr, wolf->image_ptr, 0, 0);
	ft_memset(wolf->addr_str, 0, (wolf->bits_ppixel / 8) * HEIGHT * WIDTH);
	return (0);
}

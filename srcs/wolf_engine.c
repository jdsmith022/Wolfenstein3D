/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   wolf_engine.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: jesmith <jesmith@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/19 11:40:53 by jesmith        #+#    #+#                */
/*   Updated: 2020/03/23 13:11:08 by Malou         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

static int		rounder(double dbl)
{
	int rounded;

	rounded = (int)(dbl + 0.5);
	return (rounded);
}

static size_t	texture_index(t_point intersect, t_point pos)
{
	size_t index;
	int		texture;

	texture = intersect.texture - 1;
	if (texture == 0)
        index = 0;
    else if (intersect.texture == 1)
        index = 4;
    else if (intersect.texture == 2)
        index = 8;
	else
		index = 12;	
	if (intersect.x > pos.x && intersect.dir == 'v')
		return (index);
	else if (intersect.x < pos.x && intersect.dir == 'v')
		return (index + 1);
	else if (intersect.y > pos.y && intersect.dir == 'h')
		return (index + 2);
	return (index + 3);
}

static void		project_on_plane(t_wolf *wolf, t_point intersect,
					t_project *plane, int x)
{
	intersect.obj_dist *= cos(wolf->ray_angle * x - FOV / 2);
	plane->height = \
		wolf->wall_height / intersect.obj_dist * wolf->dist_to_plane;
	plane->y_start = HEIGHT / 2 - plane->height / 2;
	plane->y_end = HEIGHT / 2 + plane->height / 2;
	if (intersect.dir == 'v')
		plane->offset = rounder(wolf->intersect.y) % wolf->wall_width;
	else if (intersect.dir == 'h')
		plane->offset = rounder(wolf->intersect.x) % wolf->wall_width;
}

static void		wolf_render(t_wolf *wolf)
{
	int			x;
	double		angle;
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
		wolf->intersect = find_intersect(wolf, ray, angle);
		project_on_plane(wolf, wolf->intersect, &plane, x);
		wolf->graphics.texdex = texture_index(wolf->intersect, wolf->pos);
		draw_column(wolf, plane, x);
		angle += wolf->ray_angle;
		x++;
	}
}

int				wolf_engine(t_wolf *wolf)
{
	wolf_render(wolf);
	mlx_key(wolf);
	mlx_mouse(wolf);
	// flat_draw(wolf);
	mlx_put_image_to_window(wolf->graphics.mlx_ptr,
		wolf->graphics.win_ptr, wolf->graphics.image_ptr, 0, 0);
	ft_memset(wolf->graphics.addr_str, 0, \
		(wolf->graphics.bits_ppixel / 8) * HEIGHT * WIDTH);
	return (0);
}

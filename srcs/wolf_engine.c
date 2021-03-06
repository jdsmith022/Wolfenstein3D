/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   wolf_engine.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: jesmith <jesmith@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/19 11:40:53 by jesmith       #+#    #+#                 */
/*   Updated: 2020/07/20 20:04:26 by JessicaSmit   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

static void		draw_textures(t_wolf *wolf, t_project plane, int x)
{
	draw_ceiling(wolf, plane.y_start, x);
	draw_floor(wolf, plane.y_end, x);
	draw_wall(wolf, plane, x);
}

static size_t	texture_index(t_point intersect, t_point pos)
{
	size_t	index;
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
		plane->offset = ft_rounder(wolf->intersect.y) % wolf->wall_width;
	else if (intersect.dir == 'h')
		plane->offset = ft_rounder(wolf->intersect.x) % wolf->wall_width;
}

static void		wolf_render(t_wolf *wolf)
{
	int			x;
	t_item		ray;
	t_project	plane;

	x = 0;
	wolf->angle = wolf->dir_angle - (FOV / 2);
	ray.start = wolf->pos;
	while (x < WIDTH)
	{
		wolf->angle = clamp_angle(wolf->angle);
		ray.end.x = ray.start.x + wolf->max_ray * cos(wolf->angle);
		ray.end.y = ray.start.y + wolf->max_ray * sin(wolf->angle);
		wolf->intersect = find_intersect(wolf, ray, wolf->angle);
		project_on_plane(wolf, wolf->intersect, &plane, x);
		wolf->graphics.tex_dex = texture_index(wolf->intersect, wolf->pos);
		draw_textures(wolf, plane, x);
		wolf->angle += wolf->ray_angle;
		x++;
	}
}

int				wolf_engine(t_wolf *wolf)
{
	wolf_render(wolf);
	mlx_key(wolf);
	mlx_mouse(wolf);
	mlx_put_image_to_window(wolf->graphics.mlx_ptr,
		wolf->graphics.win_ptr, wolf->graphics.image_ptr, 0, 0);
	ft_memset(wolf->graphics.addr_str, 0, \
		(wolf->graphics.bits_ppixel / 8) * HEIGHT * WIDTH);
	return (0);
}

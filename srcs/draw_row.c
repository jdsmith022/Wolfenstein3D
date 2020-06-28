/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   draw_row.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: Malou <Malou@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/16 17:41:14 by Malou         #+#    #+#                 */
/*   Updated: 2020/06/28 13:12:27 by jesmith       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

static void	put_row(t_wolf *wolf, size_t wall_index, size_t tex_dex)
{
	size_t addr_dex;

	addr_dex = wolf->graphics.index;
	wolf->graphics.addr_str[addr_dex] = \
	wolf->graphics.wall[tex_dex]->addr_str[(size_t)wall_index];
	addr_dex++;
	wall_index++;
	wolf->graphics.addr_str[addr_dex] = \
	wolf->graphics.wall[tex_dex]->addr_str[(size_t)wall_index];
	addr_dex++;
	wall_index++;
	wolf->graphics.addr_str[addr_dex] = \
	wolf->graphics.wall[tex_dex]->addr_str[(size_t)wall_index];
}

static void	row_calculations(t_wolf *wolf, double dist, size_t tex_dex)
{
	t_point		floor;
	t_point		texture;
	size_t		wall_index;
	t_graphics	*graphics;
	int			bpp;

	graphics = &wolf->graphics;
	bpp = graphics->wall[tex_dex]->bits_ppixel / 8;
	floor.x = dist * cos(wolf->angle);
	floor.y = dist * sin(wolf->angle);
	floor.x += wolf->pos.x;
	floor.y += wolf->pos.y;
	texture.x = (int)floor.x % TEXTURE_SIZE;
	texture.y = (int)floor.y % TEXTURE_SIZE;
	wall_index = ((texture.y * graphics->wall[tex_dex]->size_line) + \
		(texture.x * bpp));
	put_row(wolf, wall_index, tex_dex);
}

void		draw_ceiling(t_wolf *wolf, t_project plane, int x)
{
	double	dist;
	size_t	tex_dex;
	int		color;
	int		y;

	y = plane.y_start;
	tex_dex = 0;
	color = wolf->graphics.color[4];
	while (y >= 0)
	{
		wolf->graphics.index = \
			(y * wolf->graphics.size_line) + \
			(x * wolf->graphics.bits_ppixel / 8);
		dist = (wolf->wall_height - (double)PLAYER_HEIGHT) / ((HEIGHT / 2) - y);
		dist *= wolf->dist_to_plane;
		dist /= cos(wolf->ray_angle * x - FOV / 2);
		if (wolf->event.colors == 1)
			put_pixel(wolf, color, x, y);
		else
			row_calculations(wolf, dist, tex_dex);
		y--;
	}
}

void		draw_floor(t_wolf *wolf, int y, int x)
{
	double	dist;
	size_t	tex_dex;
	int		color;

	color = wolf->graphics.color[5];
	tex_dex = 4;
	if (y < HEIGHT)
	{
		dist = (double)PLAYER_HEIGHT / (y - (HEIGHT / 2));
		dist *= wolf->dist_to_plane;
		dist /= cos(wolf->ray_angle * x - FOV / 2);
		if (wolf->event.colors == 1)
			put_pixel(wolf, color, x, y);
		else
			row_calculations(wolf, dist, tex_dex);
	}
}

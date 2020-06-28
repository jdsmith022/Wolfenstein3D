/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   draw_row.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: Malou <Malou@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/16 17:41:14 by Malou         #+#    #+#                 */
/*   Updated: 2020/06/28 12:08:24 by jesmith       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

static void	put_row(t_wolf *wolf, size_t wall_index)
{
	size_t addr_dex;

	addr_dex = wolf->graphics.index;
	wolf->graphics.addr_str[addr_dex] = \
	wolf->graphics.wall[0]->addr_str[(size_t)wall_index];
	addr_dex++;
	wall_index++;
	wolf->graphics.addr_str[addr_dex] = \
	wolf->graphics.wall[0]->addr_str[(size_t)wall_index];
	addr_dex++;
	wall_index++;
	wolf->graphics.addr_str[addr_dex] = \
	wolf->graphics.wall[0]->addr_str[(size_t)wall_index];
}

static void	row_calculations(t_wolf *wolf, double dist)
{
	t_point		floor;
	t_point		texture;
	size_t		wall_index;
	t_graphics	*graphics;
	int			bpp;

	graphics = &wolf->graphics;
	bpp = graphics->wall[0]->bits_ppixel / 8;
	floor.x = dist * cos(wolf->angle);
	floor.y = dist * sin(wolf->angle);
	floor.x += wolf->pos.x;
	floor.y += wolf->pos.y;
	texture.x = (int)floor.x % 64;
	texture.y = (int)floor.y % 64;
	wall_index = ((texture.y * graphics->wall[0]->size_line) + \
		(texture.x * bpp));
	put_row(wolf, wall_index);
}

void		draw_ceiling(t_wolf *wolf, t_project plane, int x)
{
	double	dist;
	int		y;

	y = plane.y_start;
	while (y >= 0)
	{
		wolf->graphics.index = \
			(y * wolf->graphics.size_line) + \
			(x * wolf->graphics.bits_ppixel / 8);
		dist = (wolf->wall_height - (double)PLAYER_HEIGHT) / ((HEIGHT / 2) - y);
		dist *= wolf->dist_to_plane;
		dist /= cos(wolf->ray_angle * x - FOV / 2);
		row_calculations(wolf, dist);
		y--;
	}
}

void		draw_floor(t_wolf *wolf, int y, int x)
{
	double	dist;

	if (y < HEIGHT)
	{
		dist = (double)PLAYER_HEIGHT / (y - (HEIGHT / 2));
		dist *= wolf->dist_to_plane;
		dist /= cos(wolf->ray_angle * x - FOV / 2);
		row_calculations(wolf, dist);
	}
}

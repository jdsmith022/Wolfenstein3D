/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   draw_row.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: JessicaSmith <JessicaSmith@student.coda      +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/06 11:07:45 by JessicaSmit   #+#    #+#                 */
/*   Updated: 2020/05/13 12:16:09 by jessicasmit   ########   odam.nl         */
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
	wall_index = ((texture.y * graphics->wall[0]->size_line) + (texture.x * bpp));
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
			(y * wolf->graphics.size_line) + (x * wolf->graphics.bits_ppixel / 8);
		dist = (wolf->wall_height - (double)32) / ((HEIGHT / 2) - y);
		dist *= wolf->dist_to_plane;
		dist *= cos(wolf->ray_angle / (x - FOV / 2));
		row_calculations(wolf, dist);
		y--;
	}
}

void		draw_floor(t_wolf *wolf, int y, int x)
{
	double	dist;

	dist = (double)32 / (y - (HEIGHT / 2));
	dist *= wolf->dist_to_plane;
	dist *= cos(wolf->ray_angle / (x - FOV / 2));
	row_calculations(wolf, dist);
}

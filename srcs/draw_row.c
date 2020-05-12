/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   draw_row.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: JessicaSmith <JessicaSmith@student.coda      +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/06 11:07:45 by JessicaSmit   #+#    #+#                 */
/*   Updated: 2020/05/12 18:39:35 by jessicasmit   ########   odam.nl         */
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

void	draw_ceiling(t_wolf *wolf, int y)
{
	double	dist;
	t_point	floor;
	t_point	texture;
	size_t	wall_index;
	t_graphics	*graphics;

	graphics = &wolf->graphics;
	dist = (wolf->wall_height - (double)32) / ((HEIGHT / 2) - y);
	dist *= wolf->dist_to_plane;
	// dist *= cos(wolf->ray_adjacent / (x - FOV / 2));
	floor.x = dist * cos(wolf->angle);
	floor.y = dist * sin(wolf->angle);
	floor.x += wolf->pos.x;
	floor.y += wolf->pos.y;
	texture.x = (int)floor.x % 64;
	texture.y = (int)floor.y % 64;
	wall_index = ((texture.y * graphics->wall[0]->size_line) + (texture.x * graphics->wall[0]->bits_ppixel / 8));
	put_row(wolf, wall_index);
}

void	draw_floor(t_wolf *wolf, int y)
{
	double	dist;
	t_point	floor;
	t_point	texture;
	size_t	wall_index;
	t_graphics	*graphics;

	graphics = &wolf->graphics;
	dist = (double)32 / (y - (HEIGHT / 2));
	dist *= wolf->dist_to_plane;
	// dist *= cos(wolf->ray_adjacent / (x - FOV / 2));
	floor.x = dist * cos(wolf->angle);
	floor.y = dist * sin(wolf->angle);
	floor.x += wolf->pos.x;
	floor.y += wolf->pos.y;
	texture.x = (int)floor.x % 64;
	texture.y = (int)floor.y % 64;
	wall_index = ((texture.y * graphics->wall[0]->size_line) + (texture.x * graphics->wall[0]->bits_ppixel / 8));
	put_row(wolf, wall_index);
}


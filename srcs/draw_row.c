/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   draw_row.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: JessicaSmith <JessicaSmith@student.coda      +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/06 11:07:45 by JessicaSmit   #+#    #+#                 */
/*   Updated: 2020/04/07 16:22:32 by JessicaSmit   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

static void	put_pixel(t_wolf *wolf, int color, int x, int y)
{
	size_t	index;

	if (x >= 0 && x < WIDTH && y < HEIGHT && y >= 0)
	{
		index = (y * wolf->graphics.size_line) + \
			(x * wolf->graphics.bits_ppixel / 8);
		wolf->graphics.addr_str[index] = color;
		index++;
		wolf->graphics.addr_str[index] = color >> 8;
		index++;
		wolf->graphics.addr_str[index] = color >> 16;
	}
}

static void	put_row(t_wolf *wolf, int x, int y, t_i text)
{
	size_t addr_dex;
	size_t wall_dex;
	size_t row_dex;

	addr_dex = 4 * (WIDTH * y + x);
	wall_dex = 4 * (64 * (int)text.y + (int)text.x);
	row_dex = wolf->graphics.row_dex;
	wolf->graphics.addr_str[addr_dex] = \
		wolf->graphics.wall[row_dex]->addr_str[wall_dex];
	addr_dex++;
	wall_dex++;
	wolf->graphics.addr_str[addr_dex] = \
		wolf->graphics.wall[row_dex]->addr_str[wall_dex];
	addr_dex++;
	wall_dex++;
	wolf->graphics.addr_str[addr_dex] = \
		wolf->graphics.wall[row_dex]->addr_str[wall_dex];
}

void	draw_row(t_wolf *wolf, t_item ray, int y, int x)
{
	double	dist;
	double	floor_x;
	double	floor_y;
	t_i		text;

	if (wolf->event.colors == 1)
		put_pixel(wolf, 0xd57016, x, y);
	else
	{
		dist = (double)HEIGHT / (2 * (double)y - (double)HEIGHT);
		floor_x = dist / wolf->dist_to_plane * ray.end.x + (1 - (dist / wolf->dist_to_plane)) * wolf->pos.x;
		floor_y = dist / wolf->dist_to_plane * ray.end.y + (1 - (dist / wolf->dist_to_plane)) * wolf->pos.y;
		text.x = (int)(floor_x * 64) % 64;
		text.y = (int)(floor_y * 64) % 64;
		put_row(wolf, x, y, text);
	}
}

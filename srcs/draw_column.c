/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   draw_column.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: mminkjan <mminkjan@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/12 17:56:58 by mminkjan       #+#    #+#                */
/*   Updated: 2020/02/18 12:30:12 by jesmith       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

static void	put_pixel(t_wolf *wolf, int color, int x, int y)
{
	size_t	index;
	if (x >= 0 && x < WIDTH && y < HEIGHT && y >= 0)
	{
		index = (y * wolf->size_line) + (x * wolf->bits_ppixel / 8);
		wolf->addr_str[index] = color;
		index++;
		wolf->addr_str[index] = color >> 8;
		index++;
		wolf->addr_str[index] = color >> 16;
	}
}

static void	draw_object(t_wolf *wolf, int x, int y)
{
	put_pixel(wolf, 0xffffff, x, y); //white
}

static void	draw_floor(t_wolf *wolf, int x, int y)
{
	put_pixel(wolf, 0x51636c, x, y); //gray-blue
}

static void	draw_item(t_wolf *wolf, int x, int y)
{
	put_pixel(wolf, 0x0000ff, x, y); //blue
}

static void	draw_ceiling(t_wolf *wolf, int x, int y)
{
	put_pixel(wolf, 0xd57016, x, y); //orange
}

void	draw_column(t_wolf *wolf, t_item wall, int x)
{
	int y;

	y = 0;
	while (y < HEIGHT)
	{
		if (wall.texture < 5)
		{
			if (y < wall.start.y)
				draw_ceiling(wolf, x, y);
			else if (y >= wall.start.y && y <= wall.end.y)
				draw_item(wolf, x, y);
			else
				draw_floor(wolf, x, y);
		}
		if (wall.texture > 4)
			draw_object(wolf, x, y);
		y++;
	}
}

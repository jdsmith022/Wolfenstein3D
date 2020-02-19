/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   draw_column2.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: jesmith <jesmith@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/19 14:46:31 by jesmith        #+#    #+#                */
/*   Updated: 2020/02/19 15:42:14 by jesmith       ########   odam.nl         */
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

// static void	draw_object(t_wolf *wolf, int x, int y)
// {
// 	put_pixel(wolf, 0xffffff, x, y); //white
// }

static void	draw_floor(t_wolf *wolf, int x, int y)
{
	put_pixel(wolf, 0x51636c, x, y); //gray-blue
}

static void	draw_wall(t_wolf *wolf, int x, int y)
{
	put_pixel(wolf, 0x0000ff, x, y); //blue
}

static void	draw_ceiling(t_wolf *wolf, int x, int y)
{
	put_pixel(wolf, 0xd57016, x, y); //orange
}

void	draw_column2(t_wolf *wolf, t_height plane_intersect, int x)
{
	int y;

	y = 0;
	while (y < HEIGHT)
	{
		if (y < plane_intersect.y_start)
			draw_ceiling(wolf, x, y);
		else if (y >= plane_intersect.y_start && y <= plane_intersect.y_end)
			draw_wall(wolf, x, y);
		else if (y > plane_intersect.y_end)
			draw_floor(wolf, x, y);
		y++;
	}
}
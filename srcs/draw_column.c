/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   draw_column.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: jesmith <jesmith@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/19 14:46:31 by jesmith        #+#    #+#                */
/*   Updated: 2020/03/10 11:21:10 by jesmith       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

// static void	put_pixel(t_wolf *wolf, int color, int x, int y)
// {
// 	size_t	index;
// 	if (x >= 0 && x < WIDTH && y < HEIGHT && y >= 0)
// 	{
// 		index = (y * wolf->size_line) + (x * wolf->bits_ppixel / 8);
// 		wolf->addr_str[index] = color;
// 		index++;
// 		wolf->addr_str[index] = color >> 8;
// 		index++;
// 		wolf->addr_str[index] = color >> 16;
// 	}
// }

// static void	draw_object(t_wolf *wolf, int x, int y)
// {
// 	put_pixel(wolf, 0xffffff, x, y); //white
// }

// static void	draw_floor(t_wolf *wolf, int x, int y)
// {
// 	put_pixel(wolf, 0x51636c, x, y);
// }

static void	draw_wall(t_wolf *wolf, int index, int wall_index)
{
	wolf->addr_str[index] = wolf->img.addr_str[wall_index];
}

// static void	draw_ceiling(t_wolf *wolf, int x, int y)
// {
// 	put_pixel(wolf, 0xd57016, x, y);
// }

void	draw_column(t_wolf *wolf, t_project plane, int x)
{
	double y;
	int	index;
	double	wall_index;
	double	wall_y;

	y = 0;
	while (y < HEIGHT)
	{
		index = (y * wolf->size_line) + (x * wolf->bits_ppixel / 8);
		// if (y < plane.y_start)
		// 	draw_ceiling(wolf, x, y);
		if (y >= plane.y_start && y <= plane.y_end)
		{
			wall_y = (double)(wolf->wall_height / plane.height) * (double)(y - plane.y_start) * 4;
			wall_index = ((int)wall_y * wolf->img.size_line) + (plane.offset * wolf->img.bits_ppixel / 8) * 4;
			draw_wall(wolf, index, wall_index);
		}
		// else if (y > plane.y_end)
		// 	draw_floor(wolf, x, y);
		y++;
	}
}

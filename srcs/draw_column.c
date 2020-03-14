/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   draw_column.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: jesmith <jesmith@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/19 14:46:31 by jesmith        #+#    #+#                */
/*   Updated: 2020/03/14 17:16:58 by mminkjan      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

static void	put_pixel(t_wolf *wolf, int color, int x, int y)
{
	size_t	index;
	if (x >= 0 && x < WIDTH && y < HEIGHT && y >= 0)
	{
		index = (y * wolf->graphics.size_line) + (x * wolf->graphics.bits_ppixel / 8);
		wolf->graphics.addr_str[index] = color;
		index++;
		wolf->graphics.addr_str[index] = color >> 8;
		index++;
		wolf->graphics.addr_str[index] = color >> 16;
	}
}

// static void	draw_object(t_wolf *wolf, int x, int y)
// {
// 	put_pixel(wolf, 0xffffff, x, y); //white
// }

// static void	draw_floor(t_wolf *wolf, size_t texdex,
// 				int index, double wall_index)
// {
// 	// (void)texdex;
// 	wolf->graphics.addr_str[index] = wolf->graphics.wall[texdex]->addr_str[(size_t)wall_index];
// 	wolf->graphics.addr_str[index + 1] = wolf->graphics.wall[texdex]->addr_str[(size_t)wall_index + 1];
// 	wolf->graphics.addr_str[index + 2] = wolf->graphics.wall[texdex]->addr_str[(size_t)wall_index + 2];
// }

static void	draw_ceiling(t_wolf *wolf, int x, int y)
{
	put_pixel(wolf, 0xd57016, x, y);
}

static void	draw_wall(t_wolf *wolf, size_t texdex,
				int index, double wall_index)
{
	wolf->graphics.addr_str[index] = wolf->graphics.wall[texdex]->addr_str[(size_t)wall_index];
	wolf->graphics.addr_str[index + 1] = wolf->graphics.wall[texdex]->addr_str[(size_t)wall_index + 1];
	wolf->graphics.addr_str[index + 2] = wolf->graphics.wall[texdex]->addr_str[(size_t)wall_index + 2];
}

void			draw_column(t_wolf *wolf, t_project plane, int x, size_t texdex)
{
	int		index;
	int		y;
	double	wall_y;
	double	wall_index;

	y = 0;
	while (y < HEIGHT)
	{
		index = (y * wolf->graphics.size_line) + (x * wolf->graphics.bits_ppixel / 8);
		if (y < plane.y_start)
			draw_ceiling(wolf, x, y);
		if (y >= plane.y_start && y <= plane.y_end)
		{
			wall_y = (double)(wolf->wall_height / plane.height) * (y - plane.y_start) / 2.5;
			wall_index = ((int)wall_y * wolf->graphics.wall[texdex]->size_line) + (plane.offset * wolf->graphics.wall[texdex]->bits_ppixel / 8);
			draw_wall(wolf, texdex, index, wall_index);
		}
		else if (y > plane.y_end)
		{
			put_pixel(wolf, 0xd58973, x, y);
			// wall_y = (double)(wolf->wall_height / 2) / (y - HEIGHT / 2) * wolf->dist_to_plane;
			// wall_index = ((int)wall_y * wolf->graphics.wall[texdex]->size_line) + (wall_y * wolf->graphics.wall[texdex]->bits_ppixel / 8);
			// draw_floor(wolf, texdex, index, wall_index);
		}
		y++;
	}
}

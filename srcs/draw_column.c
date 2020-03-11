/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   draw_column.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: jesmith <jesmith@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/19 14:46:31 by jesmith        #+#    #+#                */
/*   Updated: 2020/03/11 16:40:59 by jesmith       ########   odam.nl         */
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

// static void	draw_floor(t_wolf *wolf, size_t texdex,
// 				int index, double wall_index)
// {
// 	int color;
// 	int new;
// 	int red;
// 	int blue;
// 	int green;

// 	(void)texdex;

// 	color = wolf->img[1].addr_str[(size_t)wall_index];
// 	red = (color >> 16) & 0xFF;
// 	green = (color >> 8) & 0xFF;
// 	blue = (color & 0xFF);
// 	new = (red << 16 | green << 8 | blue);
// 	wolf->addr_str[index] = new;
// 	index++;
// 	wolf->addr_str[index] = new >> 8;
// 	index++;
// 	wolf->addr_str[index] = new >> 16;
// }

// static void	draw_ceiling(t_wolf *wolf, int x, int y)
// {
// 	put_pixel(wolf, 0xd57016, x, y);
// }

static void	draw_wall(t_wolf *wolf, size_t texdex,
				int index, double wall_index)
{
	int color;
	int new;
	int red;
	int blue;
	int green;

	color = wolf->img[texdex].addr_str[(size_t)wall_index];
	red = (color >> 16) & 0xFF;
	green = (color >> 8) & 0xFF;
	blue = (color & 0xFF);
	new = (red << 16 | green << 8 | blue);
	wolf->addr_str[index] = new;
	index++;
	wolf->addr_str[index] = new >> 8;
	index++;
	wolf->addr_str[index] = new >> 16;
	// wolf->addr_str[index] = new;
	// wolf->addr_str[index] = color;
	// printf("%d\n", color);
	// index++;
	// wolf->addr_str[index] = color >> 8;
	// index++;
	// wolf->addr_str[index] = color >> 16;
	// wolf->addr_str[index >> 16] = wolf->img.addr_str[(int)wall_index];
	// index++;
	// wall_index++;
	// wolf->addr_str[index >> 8] = wolf->img.addr_str[(int)wall_index];
	// index++;
	// wall_index++;
	// wolf->addr_str[index] = wolf->img.addr_str[(int)wall_index];
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
		index = (y * wolf->size_line) + (x * wolf->bits_ppixel / 8);
		// if (y < plane.y_start)
		// 	draw_ceiling(wolf, x, y);
		if (y >= plane.y_start && y <= plane.y_end)
		{
			wall_y = (double)(wolf->wall_height / plane.height) * (y - plane.y_start) * 4;
			wall_index = ((int)wall_y * wolf->img[texdex].size_line) + (plane.offset * wolf->img[texdex].bits_ppixel / 8) * 4;
			draw_wall(wolf, texdex, index, wall_index);
		}
		// else if (y > plane.y_end)
		// {
		// 	wall_y = (double)((HEIGHT / 2)) / (y - plane.y_start) * wolf->dist_to_plane;
		// 	wall_index = ((int)wall_y * wolf->img[1].size_line) + (y * wolf->img[1].bits_ppixel / 8);
		// 	draw_floor(wolf, texdex, index, wall_index);
		// }
		y++;
	}
}

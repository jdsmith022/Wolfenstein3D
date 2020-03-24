/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   draw_column.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: jesmith <jesmith@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/19 14:46:31 by jesmith        #+#    #+#                */
/*   Updated: 2020/03/24 19:16:59 by jessicasmit   ########   odam.nl         */
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

static void	texture_to_str(t_wolf *wolf, size_t index, size_t texdex,
				double wall_index)
{
	wolf->graphics.addr_str[index] = \
		wolf->graphics.wall[texdex]->addr_str[(size_t)wall_index];
	index++;
	wall_index++;
	wolf->graphics.addr_str[index] = \
		wolf->graphics.wall[texdex]->addr_str[(size_t)wall_index];
	index++;
	wall_index++;
	wolf->graphics.addr_str[index] = \
		wolf->graphics.wall[texdex]->addr_str[(size_t)wall_index];
}

static void	draw_floor(t_wolf *wolf, t_project plane, int y, int x)
{
	t_graphics	graphics;
	double		floor_y;
	double		floor_index;
	size_t		texdex;

  (void)x;
	texdex = wolf->graphics.texdex;
	graphics = wolf->graphics;
    texdex = 1;
	floor_y = ((double)(wolf->wall_height / 2) / (y - HEIGHT / 2)) * wolf->dist_to_plane / plane.offset;
	floor_index = ((int)floor_y * wolf->graphics.wall[texdex]->size_line) + (x * wolf->graphics.wall[texdex]->bits_ppixel / 8);
	texture_to_str(wolf, graphics.index, texdex, floor_index);
}

static void	wall_texture(t_wolf *wolf, t_project plane,
				int x, int y)
{
	t_graphics	graphics;
	double		wall_y;
	double		wall_index;
	size_t		texdex;
	int			color;

	texdex = wolf->graphics.texdex;
	color = wolf->graphics.color[texdex];
	graphics = wolf->graphics;
	if (wolf->event.colors == 1)
		put_pixel(wolf, color, x, y);
	else
	{
		wall_y = (double)(wolf->wall_height / plane.height) * \
			(y - plane.y_start);
		wall_index = ((int)wall_y * \
			graphics.wall[texdex]->size_line) + \
			(plane.offset * graphics.wall[texdex]->bits_ppixel / 8);
		texture_to_str(wolf, graphics.index, texdex, wall_index);
	}
}

void		draw_column(t_wolf *wolf, t_project plane, int x)
{
	t_graphics	*graphics;
	int			y;

	graphics = &wolf->graphics;
	y = 0;
	while (y < HEIGHT)
	{
		graphics->index = (y * graphics->size_line) + (x * graphics->bits_ppixel / 8);
		if (y <= plane.y_start)
			put_pixel(wolf, 0xd57016, x, y);
		if (y > plane.y_start && y < plane.y_end)
			wall_texture(wolf, plane, x, y);
		else if (y > plane.y_end)
		// {
		// 	// put_pixel(wolf, 0xd58973, x, y);
			draw_floor(wolf, plane, y, x);
		// }
		y++;
	}
}

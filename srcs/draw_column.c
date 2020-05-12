/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   draw_column.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: jesmith <jesmith@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/19 14:46:31 by jesmith       #+#    #+#                 */
/*   Updated: 2020/05/12 18:50:50 by jessicasmit   ########   odam.nl         */
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

static void	put_wall(t_wolf *wolf, size_t index, size_t tex_dex,
				double wall_index)
{
	wolf->graphics.addr_str[index] = \
		wolf->graphics.wall[tex_dex]->addr_str[(size_t)wall_index];
	index++;
	wall_index++;
	wolf->graphics.addr_str[index] = \
		wolf->graphics.wall[tex_dex]->addr_str[(size_t)wall_index];
	index++;
	wall_index++;
	wolf->graphics.addr_str[index] = \
		wolf->graphics.wall[tex_dex]->addr_str[(size_t)wall_index];
}

static void	wall_texture(t_wolf *wolf, t_project plane,
				int x, int y)
{
	t_graphics	graphics;
	double		wall_y;
	double		wall_index;
	size_t		tex_dex;
	int			color;

	tex_dex = wolf->graphics.tex_dex;
	color = wolf->graphics.color[tex_dex];
	graphics = wolf->graphics;
	if (wolf->event.colors == 1)
		put_pixel(wolf, color, x, y);
	else
	{
		wall_y = (double)(wolf->wall_height / plane.height) * \
			(y - plane.y_start);
		wall_index = ((int)wall_y * \
			graphics.wall[tex_dex]->size_line) + \
			(plane.offset * graphics.wall[tex_dex]->bits_ppixel / 8);
		put_wall(wolf, graphics.index, tex_dex, wall_index);
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
		graphics->index = \
			(y * graphics->size_line) + (x * graphics->bits_ppixel / 8);		
		if (y < plane.y_end)
			wall_texture(wolf, plane, x, y);
		else
			draw_floor(wolf, y);
		y++;
	}
	y = plane.y_start;
	while (y >= 0)
	{
		graphics->index = \
			(y * graphics->size_line) + (x * graphics->bits_ppixel / 8);
		draw_ceiling(wolf, y);
		y--;
	}
}

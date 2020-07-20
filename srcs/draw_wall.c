/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   draw_wall.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: jesmith <jesmith@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/19 14:46:31 by jesmith       #+#    #+#                 */
/*   Updated: 2020/07/20 19:58:00 by JessicaSmit   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

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
	else if (x >= 0 && x < WIDTH && y < HEIGHT && y >= 0)
	{
		wall_y = (double)(wolf->wall_height / plane.height) * \
			(y - plane.y_start);
		wall_index = ((int)wall_y * \
			graphics.wall[tex_dex]->size_line) + \
			(plane.offset * graphics.wall[tex_dex]->bits_ppixel / 8);
		put_wall(wolf, graphics.index, tex_dex, wall_index);
	}
}

void		draw_wall(t_wolf *wolf, t_project plane, int x)
{
	t_graphics	*graphics;
	int			y;

	graphics = &wolf->graphics;
	y = plane.y_start;
	while (y < plane.y_end)
	{
		graphics->index = \
			(y * graphics->size_line) + (x * graphics->bits_ppixel / 8);
		wall_texture(wolf, plane, x, y);
		y++;
	}
}

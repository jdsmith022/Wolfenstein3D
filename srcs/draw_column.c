/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   draw_column.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: jesmith <jesmith@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/19 14:46:31 by jesmith       #+#    #+#                 */
/*   Updated: 2020/04/06 10:49:13 by JessicaSmit   ########   odam.nl         */
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

static void	put_row(t_wolf *wolf, int x, int y, double text_x, double text_y)
{
	size_t addr_dex;
	size_t wall_dex;
	size_t row_dex;

	addr_dex = 4 * (WIDTH * y + x);
	wall_dex = 4 * (64 * (int)text_y + (int)text_x);
	row_dex = wolf->graphics.row_dex;
	wolf->graphics.addr_str[addr_dex] = wolf->graphics.wall[row_dex]->addr_str[wall_dex];
	addr_dex++;
	wall_dex++;
	wolf->graphics.addr_str[addr_dex] = wolf->graphics.wall[row_dex]->addr_str[wall_dex];
	addr_dex++;
	wall_dex++;
	wolf->graphics.addr_str[addr_dex] = wolf->graphics.wall[row_dex]->addr_str[wall_dex];
}

 void	draw_row(t_wolf *wolf, t_item ray, int y, int x, t_project plane)
{

	double	current_dist;
	double	cur_floor_x;
	double	cur_floor_y;
	double	text_x;
	double	text_y;

	if (wolf->event.colors == 1 && y <= plane.y_start)
		put_pixel(wolf, 0xd57016, x, y);
	else if (wolf->event.colors == 1 && y > plane.y_end)
		put_pixel(wolf, 0xd57016, x, y);
	else
	{
		current_dist = (double)HEIGHT /(2 * (double)y - (double)HEIGHT);
		cur_floor_x = current_dist / wolf->dist_to_plane * (ray.end.x * plane.offset) + (1 - (current_dist / wolf->dist_to_plane)) * wolf->pos.x;
		cur_floor_y = current_dist / wolf->dist_to_plane * (ray.end.y * plane.offset) + (1 - (current_dist / wolf->dist_to_plane)) * wolf->pos.y;
		text_x = (int)(cur_floor_x * 64) % 64;
		text_y = (int)(cur_floor_y * 64) % 64;
		put_row(wolf, x, y, text_x, text_y);
	}
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

void		draw_column(t_wolf *wolf, t_project plane, int x, t_item ray)
{
	t_graphics	*graphics;
	int			y;

	graphics = &wolf->graphics;
	y = 0;
	while (y < HEIGHT)
	{
		graphics->index = (y * graphics->size_line) + (x * graphics->bits_ppixel / 8);
		if (y <= plane.y_start)
		{
			wolf->graphics.row_dex = 0;
			draw_row(wolf, ray, y, x, plane);
		}
		if (y > plane.y_start && y < plane.y_end)
			wall_texture(wolf, plane, x, y);
		else if (y > plane.y_end)
		{
			wolf->graphics.row_dex = 5;
			draw_row(wolf, ray, y, x, plane);
		}
		y++;
	}
}

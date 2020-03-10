/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   draw_line.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jesmith <jesmith@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/10 12:57:12 by jesmith        #+#    #+#                */
/*   Updated: 2020/03/10 12:57:29 by jesmith       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

static void		put_pixel(t_wolf *wolf, t_point point, int color)
{
	int		index;

	if (point.x >= 0 && point.x < WIDTH && point.y >= 0
	&& point.y < HEIGHT)
	{
		index = ((int)point.y * wolf->size_line) + ((int)point.x *
			wolf->bits_ppixel / 8);
		wolf->addr_str2[index] = color;
		index++;
		wolf->addr_str2[index] = color >> 8;
		index++;
		wolf->addr_str2[index] = color >> 16;
	}
}

static void		draw_y_dominant(t_wolf *wolf, t_line *line,
					t_point start, t_point end, int color)
{
	t_point point;

	point = start;
	while (point.y < end.y)
	{
		if (line->error_y <= 0)
			line->error_y += 2 * line->delta_x_abs;
		else
		{
			if ((line->delta_x < 0 && line->delta_y < 0) ||
			(line->delta_x > 0 && line->delta_y > 0))
				point.x++;
			else
				point.x--;
			line->error_y += 2 * (line->delta_x_abs - line->delta_y_abs);
		}
		put_pixel(wolf, point, color);
		point.y++;
	}
}

static void		draw_x_dominant(t_wolf *wolf, t_line *line,
					t_point start, t_point end, int color)
{
	t_point point;

	point = start;
	while (point.x < end.x)
	{
		if (line->error_x < 0)
			line->error_x += 2 * line->delta_y_abs;
		else
		{
			if ((line->delta_x < 0 && line->delta_y < 0) ||
			(line->delta_x > 0 && line->delta_y > 0))
				point.y++;
			else
				point.y--;
			line->error_x += 2 * (line->delta_y_abs - line->delta_x_abs);
		}
		put_pixel(wolf, point, color);
		point.x++;
	}
}

static void		set_direction(t_wolf *wolf, t_line *line,
					t_point start, t_point end, int color)
{
	t_point hold;

	if ((line->delta_x < 0 && line->delta_y_abs <= line->delta_x_abs) ||
		(line->delta_y < 0 && line->delta_y_abs > line->delta_x_abs))
	{
		hold = start;
		start = end;
		end = hold;
	}
	if (line->delta_y_abs <= line->delta_x_abs)
		draw_x_dominant(wolf, line, start, end, color);
	else
		draw_y_dominant(wolf, line, start, end, color);
}

void			draw_line(t_wolf *wolf, t_point start, t_point end, int color)
{
	t_line line;

	line.delta_x = end.x - start.x;
	line.delta_y = end.y - start.y;
	line.delta_x_abs = abs((int)line.delta_x);
	line.delta_y_abs = abs((int)line.delta_y);
	line.error_x = 2 * line.delta_y_abs - line.delta_x_abs;
	line.error_y = 2 * line.delta_x_abs - line.delta_y_abs;
	set_direction(wolf, &line, start, end, color);
}

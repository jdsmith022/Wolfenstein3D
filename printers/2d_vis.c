/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   2d_vis.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: mminkjan <mminkjan@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/22 14:10:44 by mminkjan       #+#    #+#                */
/*   Updated: 2020/03/16 17:34:10 by Malou         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void		draw_ray(t_wolf *wolf, t_point r_start, t_point r_end, int color)
{
	t_point start;
	t_point end;

	start.x = r_start.x / 4;
	start.y = r_start.y / 4;
	end.x = (int)r_end.x / 4;
	end.y = (int)r_end.y / 4;
	draw_line(wolf, start, end, color);
}

void		draw_intercept(t_wolf *wolf, t_point r_start, int x, int y)
{
	t_point start;
	t_point end;

	start.x = r_start.x / 4;
	start.y = r_start.y / 4;
	end.x = (int)x / 4;
	end.y = (int)y / 4;
	draw_line(wolf, start, end, 0x00ffff);
}

void		draw_map(t_wolf *wolf, t_item *item)
{
	t_point start;
	t_item	*temp;
	t_point end;

	temp = item;
	while (temp != NULL)
	{
		start.x = (int)temp->start.x / 4;
		start.y = (int)temp->start.y / 4;
		end.x = (int)temp->end.x / 4;
		end.y = (int)temp->end.y / 4;
		draw_line(wolf, start, end, 0xffffff);
		temp = temp->next;
	}
}

int			flat_draw(t_wolf *wolf)
{
	draw_map(wolf, wolf->item);
	mlx_put_image_to_window(wolf->vis.mlx_ptr2,
		wolf->graphics.win_ptr, wolf->vis.image_ptr2, WIDTH, 0);
	ft_bzero(wolf->vis.addr_str2, HEIGHT * WIDTH * (wolf->graphics.bits_ppixel / 8));
	return (0);
}

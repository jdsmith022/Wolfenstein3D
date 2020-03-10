/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   2d_vis.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: mminkjan <mminkjan@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/22 14:10:44 by mminkjan       #+#    #+#                */
/*   Updated: 2020/03/10 12:57:52 by jesmith       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void		draw_ray(t_wolf *wolf, t_point r_start, t_point r_end, int color)
{
	t_point start;
	t_point end;

	start.x = r_start.x / 3;
	start.y = r_start.y / 3;
	end.x = (int)r_end.x / 3;
	end.y = (int)r_end.y / 3;
	draw_line(wolf, start, end, color);
}

void		draw_intercept(t_wolf *wolf, t_point r_start, int x, int y)
{
	t_point start;
	t_point end;

	start.x = r_start.x / 3;
	start.y = r_start.y / 3;
	end.x = (int)x / 3;
	end.y = (int)y / 3;
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
		start.x = (int)temp->start.x / 3;
		start.y = (int)temp->start.y / 3;
		end.x = (int)temp->end.x / 3;
		end.y = (int)temp->end.y / 3;
		draw_line(wolf, start, end, 0xffffff);
		temp = temp->next;
	}
}

int			flat_draw(t_wolf *wolf)
{
	draw_map(wolf, wolf->item);
	mlx_put_image_to_window(wolf->mlx_ptr2,
		wolf->win_ptr, wolf->image_ptr2, WIDTH, 0);
	ft_bzero(wolf->addr_str2, HEIGHT * WIDTH * (wolf->bits_ppixel / 8));
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   printers.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: jesmith <jesmith@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/10 12:08:56 by jesmith        #+#    #+#                */
/*   Updated: 2020/03/24 19:16:13 by jessicasmit   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"
#include "../ft_printf/ft_printf.h"

void	print_map_coordinates(t_item *item)
{
	t_item	*temp;

	ft_printf("%d\n", 1);
	temp = item;
	while (temp != NULL)
	{
		ft_printf("texture = %d | start.x = %f	start.y = %f	|\
		end.x = %f	end.y = %f\n", temp->texture, temp->start.x,\
		temp->start.y, temp->end.x, temp->end.y);
		temp = temp->next;
	}
	ft_printf("\n");
}

void	print_map(int **map_values, t_wolf *wolf)
{
	int y;
	int x;

	(void)wolf;
	y = 0;
	while (y < wolf->max_y)
	{
		x = 0;
		while (x < wolf->max_x)
		{
			ft_printf("|%d|", map_values[y][x]);
			x++;
		}
		ft_printf("\n");
		y++;
	}
	ft_printf("\n");
}

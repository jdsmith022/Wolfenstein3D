/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   printers.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: jesmith <jesmith@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/10 12:08:56 by jesmith        #+#    #+#                */
/*   Updated: 2020/03/16 15:22:42 by Malou         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"
#include <stdio.h>

void	print_map_coordinates(t_item *item)
{
	t_item	*temp;

	printf("%d\n", 1);
	temp = item;
	while (temp != NULL)
	{
		printf("texture = %d | start.x = %f	start.y = %f	|\
		end.x = %f	end.y = %f\n", temp->texture, temp->start.x,\
		temp->start.y, temp->end.x, temp->end.y);
		temp = temp->next;
	}
	printf("\n");
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
			printf("|%d|", map_values[y][x]);
			x++;
		}
		printf("\n");
		y++;
	}
	printf("\n");
}

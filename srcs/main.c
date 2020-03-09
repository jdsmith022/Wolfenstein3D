/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mminkjan <mminkjan@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/03 20:21:28 by mminkjan       #+#    #+#                */
/*   Updated: 2020/03/09 19:32:49 by jesmith       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void	print_map_coordinates(t_item *item)
{
	t_item	*temp;

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

int		main(int argc, char **argv)
{
	t_wolf	wolf;

	if (argc != 2)
		wolf_failure_exit(&wolf, NULL, USAGE_ERR);
	wolf = init_wolf();
	wolf.map = save_map_values(&wolf, argv[1]);
	print_map(wolf.map, &wolf);
	save_map_coordinates(&wolf);
	print_map_coordinates(wolf.item);
	init_mlx(&wolf);
	init_mlx2(&wolf); //remove later
	mlx_loop_hook(wolf.mlx_ptr, wolf_engine, &wolf);
	mlx_loop(wolf.mlx_ptr);
	return (0);
}

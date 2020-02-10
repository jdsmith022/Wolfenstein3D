/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mminkjan <mminkjan@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/03 20:21:28 by mminkjan       #+#    #+#                */
/*   Updated: 2020/02/10 19:05:40 by mminkjan      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void	print_map_coordinates(t_object *object)
{
	while (object != NULL)
	{
		printf("texture = %d | start.x = %d	start.y = %d	|\
		end.x = %d	end.y = %d\n", object->texture, object->start.x,\
		object->start.y, object->end.x, object->end.y);
		object = object->next;
	}
	printf("\n");
}

void	print_map(int **map_values, t_wolf *wolf)
{
	int y;
	int x;

	(void)wolf;
	y = 0;
	while (y < 7)
	{
		x = 0;
		while (x < 12)
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
	int		**map_values;

	if (argc != 2)
		wolf_failure_exit(&wolf, NULL, USAGE_ERR);
	wolf = init_wolf();
	map_values = save_map_values(&wolf, argv[1]);
	print_map(map_values, &wolf);
	save_map_coordinates(&wolf, map_values);
	print_map_coordinates(wolf.object);
	init_mlx(&wolf);
	mlx_loop_hook(wolf.mlx_ptr, wolf_render, &wolf);
	mlx_loop(wolf.mlx_ptr);
	return (0);
}

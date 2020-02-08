/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mminkjan <mminkjan@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/03 20:21:28 by mminkjan       #+#    #+#                */
/*   Updated: 2020/02/08 14:19:30 by mminkjan      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void	print_map(int **map_values, t_wolf *wolf)
{
	int y = 0;
	(void)wolf;
	while (y < 7)
	{
		int x = 0;
		while (x < 12)
		{
			printf("|%d|", map_values[y][x]);
			x++;
		}
		printf("\n");
		y++;
	}
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
	mlx_setup(&wolf);
	save_map_coordinates(wolf, map_values);
	// wolf->title = ft_strdup(argv[1]);
	// mlx_loop_hook(wolf->mlx_ptr, render_wolf, wolf);
	// mlx_loop(wolf->mlx_ptr);
	return (0);
}

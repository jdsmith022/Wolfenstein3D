/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mminkjan <mminkjan@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/03 20:21:28 by mminkjan       #+#    #+#                */
/*   Updated: 2020/03/11 11:36:51 by jesmith       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

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

/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mminkjan <mminkjan@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/03 20:21:28 by mminkjan      #+#    #+#                 */
/*   Updated: 2020/06/30 16:54:57 by jesmith       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

int		main(int argc, char **argv)
{
	t_wolf	wolf;
	char	*filename;
	char	*exe;

	filename = argv[1];
	exe = argv[0];
	if (ft_strcmp(argv[1], "--help") == 0)
		print_help_menu();
	if (argc != 2 || ft_strcmp(exe, filename) == 0 || \
		ft_strcmp(&exe[2], filename) == 0)
	{
		ft_putendl(USAGE_ERR);
		exit(EXIT_FAILURE);
	}
	wolf = init_wolf();
	wolf.map = save_map_values(&wolf, argv[1]);
	save_map_coordinates(&wolf);
	init_mlx(&wolf);
	mlx_loop_hook(wolf.graphics.mlx_ptr, wolf_engine, &wolf);
	mlx_loop(wolf.graphics.mlx_ptr);
	return (0);
}

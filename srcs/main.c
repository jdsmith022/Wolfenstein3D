/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mminkjan <mminkjan@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/03 20:21:28 by mminkjan      #+#    #+#                 */
/*   Updated: 2020/07/20 19:03:36 by JessicaSmit   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void	check_valid_input(int argc, char *filename, char *exe)
{
	if (argc != 2)
	{
		ft_putendl(USAGE_ERR);
		exit(EXIT_FAILURE);
	}
	if (ft_strcmp(exe, filename) == 0 || \
		ft_strcmp(&exe[2], filename) == 0)
	{
		ft_putendl(USAGE_ERR);
		exit(EXIT_FAILURE);
	}
}

int		main(int argc, char **argv)
{
	t_wolf	wolf;
	char	*filename;
	char	*exe;

	filename = argv[1];
	exe = argv[0];
	check_valid_input(argc, filename, exe);
	if (ft_strcmp(argv[1], "--help") == 0)
		print_help_menu();
	if (ft_strcmp(argv[1], "--settings") == 0)
		print_settings_menu();
	wolf = init_wolf();
	wolf.map = save_map_values(&wolf, argv[1]);
	save_map_coordinates(&wolf);
	init_mlx(&wolf);
	mlx_loop_hook(wolf.graphics.mlx_ptr, wolf_engine, &wolf);
	mlx_loop(wolf.graphics.mlx_ptr);
	return (0);
}

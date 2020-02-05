/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mminkjan <mminkjan@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/03 20:21:28 by mminkjan       #+#    #+#                */
/*   Updated: 2020/02/05 13:38:37 by jesmith       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

int		main(int argc, char **argv)
{
	t_wolf	*wolf;

	if (argc != 2)
		wolf_failure_exit(USAGE_ERR);
	init_wolf(wolf);
	validate_map(wolf, argv[1]);
	mlx_setup(wolf);
	save_map(wolf);
	// wolf->title = ft_strdup(argv[1]);
	mlx_loop_hook(wolf->mlx_ptr, render_wolf, wolf);
	mlx_loop(wolf->mlx_ptr);
}

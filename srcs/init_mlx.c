/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_mlx.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: mminkjan <mminkjan@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/03 20:34:26 by mminkjan       #+#    #+#                */
/*   Updated: 2020/02/13 15:24:52 by mminkjan      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void	init_mlx(t_wolf *wolf)
{
	int		endian;

	endian = 0;
	wolf->mlx.mlx_ptr = mlx_init();
	wolf->mlx.win_ptr = mlx_new_window(wolf->mlx.mlx_ptr, \
		WIDTH, HEIGHT, "Wolf3d");
	if (wolf->mlx.win_ptr == NULL)
		wolf_failure_exit(wolf, NULL, MALLOC_ERR);
	wolf->mlx.img_ptr = mlx_new_image(wolf->mlx.mlx_ptr, WIDTH, HEIGHT);
	if (wolf->mlx.img_ptr == NULL)
		wolf_failure_exit(wolf, NULL, MALLOC_ERR);
	wolf->mlx.addr_str = mlx_get_data_addr(wolf->mlx.img_ptr, &wolf->mlx.bpp,
		&wolf->mlx.size_line, &endian);
	if (wolf->mlx.addr_str == NULL)
		wolf_failure_exit(wolf, NULL, MALLOC_ERR);
}

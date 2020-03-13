/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_mlx.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: mminkjan <mminkjan@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/03 20:34:26 by mminkjan       #+#    #+#                */
/*   Updated: 2020/03/11 16:31:58 by mminkjan      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void		init_mlx(t_wolf *wolf)
{
	int		endian;

	endian = 0;
	wolf->graphics.mlx_ptr = mlx_init();
	wolf->graphics.win_ptr = mlx_new_window(wolf->graphics.mlx_ptr, \
		WIDTH + WIDTH / 2, HEIGHT, "Wolf3d");
	if (wolf->graphics.win_ptr == NULL)
		wolf_failure_exit(wolf, NULL, MALLOC_ERR);
	wolf->graphics.image_ptr = mlx_new_image(wolf->graphics.mlx_ptr, WIDTH, HEIGHT);
	if (wolf->graphics.image_ptr == NULL)
		wolf_failure_exit(wolf, NULL, MALLOC_ERR);
	wolf->graphics.addr_str = mlx_get_data_addr(wolf->graphics.image_ptr, &wolf->graphics.bits_ppixel,
		&wolf->graphics.size_line, &endian);
	if (wolf->graphics.addr_str == NULL)
		wolf_failure_exit(wolf, NULL, MALLOC_ERR);
	load_textures(wolf);
}

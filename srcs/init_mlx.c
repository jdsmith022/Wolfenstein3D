/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_mlx.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: mminkjan <mminkjan@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/03 20:34:26 by mminkjan       #+#    #+#                */
/*   Updated: 2020/03/09 19:50:31 by jesmith       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

static void	load_textures(t_wolf *wolf)
{
	int		endian;
	int		width;
	int		height;

	endian = 0;
	width = wolf->module;
	height = wolf->wall_height;
	wolf->img.image_ptr = mlx_xpm_file_to_image(wolf->mlx_ptr,\
		"pictures/head.xpm", &width, &height);
	if (wolf->img.image_ptr == NULL)
		wolf_failure_exit(wolf, NULL, MALLOC_ERR);
	wolf->img.addr_str = mlx_get_data_addr(wolf->img.image_ptr, \
		&wolf->img.bits_ppixel, &wolf->img.size_line, &endian);
	if (wolf->img.addr_str == NULL)
		wolf_failure_exit(wolf, NULL, MALLOC_ERR);
}

void		init_mlx(t_wolf *wolf)
{
	int		endian;

	endian = 0;
	wolf->mlx_ptr = mlx_init();
	wolf->win_ptr = mlx_new_window(wolf->mlx_ptr, \
		WIDTH + WIDTH / 2, HEIGHT, "Wolf3d");
	if (wolf->win_ptr == NULL)
		wolf_failure_exit(wolf, NULL, MALLOC_ERR);
	wolf->image_ptr = mlx_new_image(wolf->mlx_ptr, WIDTH, HEIGHT);
	if (wolf->image_ptr == NULL)
		wolf_failure_exit(wolf, NULL, MALLOC_ERR);
	wolf->addr_str = mlx_get_data_addr(wolf->image_ptr, &wolf->bits_ppixel,
		&wolf->size_line, &endian);
	if (wolf->addr_str == NULL)
		wolf_failure_exit(wolf, NULL, MALLOC_ERR);
	load_textures(wolf);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   load_textures.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: jesmith <jesmith@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/10 17:07:11 by jesmith        #+#    #+#                */
/*   Updated: 2020/03/11 10:40:22 by jesmith       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

static void	load_addr_str(t_wolf *wolf)
{
	int		endian;

	endian = 0;
	wolf->img[0].addr_str = mlx_get_data_addr(wolf->img[0].image_ptr, \
		&wolf->img[0].bits_ppixel, &wolf->img[0].size_line, &endian);
	wolf->img[1].addr_str = mlx_get_data_addr(wolf->img[1].image_ptr, \
		&wolf->img[1].bits_ppixel, &wolf->img[1].size_line, &endian);
	wolf->img[2].addr_str = mlx_get_data_addr(wolf->img[2].image_ptr, \
		&wolf->img[2].bits_ppixel, &wolf->img[2].size_line, &endian);
	wolf->img[3].addr_str = mlx_get_data_addr(wolf->img[3].image_ptr, \
		&wolf->img[3].bits_ppixel, &wolf->img[3].size_line, &endian);
	wolf->img[4].addr_str = mlx_get_data_addr(wolf->img[4].image_ptr, \
		&wolf->img[4].bits_ppixel, &wolf->img[4].size_line, &endian);
	wolf->img[5].addr_str = mlx_get_data_addr(wolf->img[5].image_ptr, \
		&wolf->img[5].bits_ppixel, &wolf->img[5].size_line, &endian);
	wolf->img[6].addr_str = mlx_get_data_addr(wolf->img[6].image_ptr, \
		&wolf->img[6].bits_ppixel, &wolf->img[6].size_line, &endian);
	wolf->img[7].addr_str = mlx_get_data_addr(wolf->img[7].image_ptr, \
		&wolf->img[7].bits_ppixel, &wolf->img[7].size_line, &endian);
	wolf->img[8].addr_str = mlx_get_data_addr(wolf->img[8].image_ptr, \
		&wolf->img[8].bits_ppixel, &wolf->img[8].size_line, &endian);
	wolf->img[9].addr_str = mlx_get_data_addr(wolf->img[9].image_ptr, \
		&wolf->img[9].bits_ppixel, &wolf->img[9].size_line, &endian);
}

static void	load_image_ptr(t_wolf *wolf, int width, int height)
{
	wolf->img[0].image_ptr = mlx_xpm_file_to_image(wolf->mlx_ptr,\
		"textures/mesh.xpm", &width, &height);
	wolf->img[1].image_ptr = mlx_xpm_file_to_image(wolf->mlx_ptr,\
		"textures/escher2.XPM", &width, &height);
	wolf->img[2].image_ptr = mlx_xpm_file_to_image(wolf->mlx_ptr,\
		"textures/escher3.xpm", &width, &height);
	wolf->img[3].image_ptr = mlx_xpm_file_to_image(wolf->mlx_ptr,\
		"textures/head.xpm", &width, &height);
	wolf->img[4].image_ptr = mlx_xpm_file_to_image(wolf->mlx_ptr,\
		"textures/head.xpm", &width, &height);
	wolf->img[5].image_ptr = mlx_xpm_file_to_image(wolf->mlx_ptr,\
		"textures/head.xpm", &width, &height);
	wolf->img[6].image_ptr = mlx_xpm_file_to_image(wolf->mlx_ptr,\
		"textures/head.xpm", &width, &height);
	wolf->img[7].image_ptr = mlx_xpm_file_to_image(wolf->mlx_ptr,\
		"textures/head.xpm", &width, &height);
	wolf->img[8].image_ptr = mlx_xpm_file_to_image(wolf->mlx_ptr,\
		"textures/head.xpm", &width, &height);
	wolf->img[9].image_ptr = mlx_xpm_file_to_image(wolf->mlx_ptr,\
		"textures/head.xpm", &width, &height);
}

void	load_textures(t_wolf *wolf)
{
	int		width;
	int		height;
	int		index;

	width = wolf->module;
	height = wolf->wall_height;
	load_image_ptr(wolf, width, height);
	index = 0;
	while (wolf->img[index].image_ptr && wolf->img[index].image_ptr != NULL)
	{
		index++;
		if (wolf->img[index].image_ptr && wolf->img[index].image_ptr == NULL)
			wolf_failure_exit(wolf, NULL, MALLOC_ERR);
	}
	load_addr_str(wolf);
	index = 0;
	while (wolf->img[index].addr_str && wolf->img[index].addr_str != NULL)
	{
		index++;
		if (wolf->img[index].addr_str && wolf->img[index].addr_str == NULL)
			wolf_failure_exit(wolf, NULL, MALLOC_ERR);
	}
}

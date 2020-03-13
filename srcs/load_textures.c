/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   load_textures.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: jesmith <jesmith@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/10 17:07:11 by jesmith        #+#    #+#                */
/*   Updated: 2020/03/13 16:25:48 by mminkjan      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

static void	load_addr_str(t_wolf *wolf)
{
	int		endian;

	// endian = 0;
	wolf->graphics.wall[0]->addr_str = mlx_get_data_addr(wolf->graphics.wall[0], \
		&wolf->graphics.wall[0]->bits_ppixel, &wolf->graphics.wall[0]->size_line, &endian);
	wolf->graphics.wall[1]->addr_str = mlx_get_data_addr(wolf->graphics.wall[1], \
		&wolf->graphics.wall[1]->bits_ppixel, &wolf->graphics.wall[1]->size_line, &endian);
	wolf->graphics.wall[2]->addr_str = mlx_get_data_addr(wolf->graphics.wall[2], \
		&wolf->graphics.wall[2]->bits_ppixel, &wolf->graphics.wall[2]->size_line, &endian);
	wolf->graphics.wall[3]->addr_str = mlx_get_data_addr(wolf->graphics.wall[3], \
		&wolf->graphics.wall[3]->bits_ppixel, &wolf->graphics.wall[3]->size_line, &endian);
	wolf->graphics.wall[4]->addr_str = mlx_get_data_addr(wolf->graphics.wall[4], \
		&wolf->graphics.wall[4]->bits_ppixel, &wolf->graphics.wall[4]->size_line, &endian);
	wolf->graphics.wall[5]->addr_str = mlx_get_data_addr(wolf->graphics.wall[5], \
		&wolf->graphics.wall[5]->bits_ppixel, &wolf->graphics.wall[5]->size_line, &endian);
	wolf->graphics.wall[6]->addr_str = mlx_get_data_addr(wolf->graphics.wall[6], \
		&wolf->graphics.wall[6]->bits_ppixel, &wolf->graphics.wall[6]->size_line, &endian);
	wolf->graphics.wall[7]->addr_str = mlx_get_data_addr(wolf->graphics.wall[7], \
		&wolf->graphics.wall[7]->bits_ppixel, &wolf->graphics.wall[7]->size_line, &endian);
	wolf->graphics.wall[8]->addr_str = mlx_get_data_addr(wolf->graphics.wall[8], \
		&wolf->graphics.wall[8]->bits_ppixel, &wolf->graphics.wall[8]->size_line, &endian);
	wolf->graphics.wall[9]->addr_str = mlx_get_data_addr(wolf->graphics.wall[9], \
		&wolf->graphics.wall[9]->bits_ppixel, &wolf->graphics.wall[9]->size_line, &endian);
}

static void	load_image_ptr(t_wolf *wolf, int width, int height)
{
	wolf->graphics.wall[0] = mlx_xpm_file_to_image(wolf->graphics.mlx_ptr,\
		"textures/mesh.xpm", &width, &height);
	wolf->graphics.wall[1] = mlx_xpm_file_to_image(wolf->graphics.mlx_ptr,\
		"textures/escher2.XPM", &width, &height);
	wolf->graphics.wall[2] = mlx_xpm_file_to_image(wolf->graphics.mlx_ptr,\
		"textures/escher3.xpm", &width, &height);
	wolf->graphics.wall[3] = mlx_xpm_file_to_image(wolf->graphics.mlx_ptr,\
		"textures/head.xpm", &width, &height);
	wolf->graphics.wall[4] = mlx_xpm_file_to_image(wolf->graphics.mlx_ptr,\
		"textures/head.xpm", &width, &height);
	wolf->graphics.wall[5] = mlx_xpm_file_to_image(wolf->graphics.mlx_ptr,\
		"textures/head.xpm", &width, &height);
	wolf->graphics.wall[6] = mlx_xpm_file_to_image(wolf->graphics.mlx_ptr,\
		"textures/head.xpm", &width, &height);
	wolf->graphics.wall[7] = mlx_xpm_file_to_image(wolf->graphics.mlx_ptr,\
		"textures/head.xpm", &width, &height);
	wolf->graphics.wall[8] = mlx_xpm_file_to_image(wolf->graphics.mlx_ptr,\
		"textures/head.xpm", &width, &height);
	wolf->graphics.wall[9] = mlx_xpm_file_to_image(wolf->graphics.mlx_ptr,\
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
	while (wolf->graphics.wall[index] && wolf->graphics.wall[index] != NULL)
	{
		if (wolf->graphics.wall[index] && wolf->graphics.wall[index] == NULL)
			wolf_failure_exit(wolf, NULL, MALLOC_ERR);
		index++;
	}
	load_addr_str(wolf);
	index = 0;
	// while (wolf->graphics.wall[index]->addr_str && wolf->graphics.wall[index]->addr_str != NULL)
	// {
	// 	if (wolf->graphics.wall[index]->addr_str && wolf->graphics.wall[index]->addr_str == NULL)
	// 		wolf_failure_exit(wolf, NULL, MALLOC_ERR);
	// 	index++;
	// 	// printf("%x\n", wolf->graphics.wall[index]->addr_str[0]);
	// }
	printf("end\n");
}

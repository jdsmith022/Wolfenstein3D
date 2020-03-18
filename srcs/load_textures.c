/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   load_textures.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: jesmith <jesmith@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/10 17:07:11 by jesmith        #+#    #+#                */
/*   Updated: 2020/03/18 15:17:05 by Malou         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

static void	load_addr_str3(t_wolf *wolf, int endian)
{
	wolf->graphics.wall[10]->addr_str = mlx_get_data_addr(\
		wolf->graphics.wall[10], &wolf->graphics.wall[10]->bits_ppixel,\
		&wolf->graphics.wall[10]->size_line, &endian);
	wolf->graphics.wall[11]->addr_str = mlx_get_data_addr(\
		wolf->graphics.wall[11], &wolf->graphics.wall[11]->bits_ppixel,\
		&wolf->graphics.wall[11]->size_line, &endian);
	wolf->graphics.wall[12]->addr_str = mlx_get_data_addr(\
		wolf->graphics.wall[12], &wolf->graphics.wall[12]->bits_ppixel,\
		&wolf->graphics.wall[12]->size_line, &endian);
	wolf->graphics.wall[13]->addr_str = mlx_get_data_addr(\
		wolf->graphics.wall[13], &wolf->graphics.wall[13]->bits_ppixel,\
		&wolf->graphics.wall[13]->size_line, &endian);
	wolf->graphics.wall[14]->addr_str = mlx_get_data_addr(\
		wolf->graphics.wall[14], &wolf->graphics.wall[14]->bits_ppixel,\
		&wolf->graphics.wall[14]->size_line, &endian);
	wolf->graphics.wall[15]->addr_str = mlx_get_data_addr(\
		wolf->graphics.wall[15], &wolf->graphics.wall[15]->bits_ppixel,\
		&wolf->graphics.wall[15]->size_line, &endian);
}

static void	load_addr_str2(t_wolf *wolf, int endian)
{
	wolf->graphics.wall[5]->addr_str = mlx_get_data_addr(\
		wolf->graphics.wall[5], &wolf->graphics.wall[5]->bits_ppixel,\
		&wolf->graphics.wall[5]->size_line, &endian);
	wolf->graphics.wall[6]->addr_str = mlx_get_data_addr(\
		wolf->graphics.wall[6], &wolf->graphics.wall[6]->bits_ppixel,\
		&wolf->graphics.wall[6]->size_line, &endian);
	wolf->graphics.wall[7]->addr_str = mlx_get_data_addr(\
		wolf->graphics.wall[7], &wolf->graphics.wall[7]->bits_ppixel,\
		&wolf->graphics.wall[7]->size_line, &endian);
	wolf->graphics.wall[8]->addr_str = mlx_get_data_addr(\
		wolf->graphics.wall[8], &wolf->graphics.wall[8]->bits_ppixel,\
		&wolf->graphics.wall[8]->size_line, &endian);
	wolf->graphics.wall[9]->addr_str = mlx_get_data_addr(\
		wolf->graphics.wall[9], &wolf->graphics.wall[9]->bits_ppixel,\
		&wolf->graphics.wall[9]->size_line, &endian);
	load_addr_str3(wolf, endian);
}

void		load_addr_str(t_wolf *wolf)
{
	int		endian;

	wolf->graphics.wall[0]->addr_str = mlx_get_data_addr(\
		wolf->graphics.wall[0], &wolf->graphics.wall[0]->bits_ppixel,\
		&wolf->graphics.wall[0]->size_line, &endian);
	wolf->graphics.wall[1]->addr_str = mlx_get_data_addr(\
		wolf->graphics.wall[1], &wolf->graphics.wall[1]->bits_ppixel,\
		&wolf->graphics.wall[1]->size_line, &endian);
	wolf->graphics.wall[2]->addr_str = mlx_get_data_addr(\
		wolf->graphics.wall[2], &wolf->graphics.wall[2]->bits_ppixel,\
		&wolf->graphics.wall[2]->size_line, &endian);
	wolf->graphics.wall[3]->addr_str = mlx_get_data_addr(\
		wolf->graphics.wall[3], &wolf->graphics.wall[3]->bits_ppixel,\
		&wolf->graphics.wall[3]->size_line, &endian);
	wolf->graphics.wall[4]->addr_str = mlx_get_data_addr(\
		wolf->graphics.wall[4], &wolf->graphics.wall[4]->bits_ppixel,\
		&wolf->graphics.wall[4]->size_line, &endian);
	load_addr_str2(wolf, endian);
}

static void	load_image_ptr2(t_wolf *wolf, int width, int height)
{
	wolf->graphics.wall[8] = mlx_xpm_file_to_image(wolf->graphics.mlx_ptr,\
		"textures/head.xpm", &width, &height);
	wolf->graphics.wall[9] = mlx_xpm_file_to_image(wolf->graphics.mlx_ptr,\
		"textures/head.xpm", &width, &height);
	wolf->graphics.wall[10] = mlx_xpm_file_to_image(wolf->graphics.mlx_ptr,\
		"textures/head.xpm", &width, &height);
	wolf->graphics.wall[11] = mlx_xpm_file_to_image(wolf->graphics.mlx_ptr,\
		"textures/head.xpm", &width, &height);
	wolf->graphics.wall[12] = mlx_xpm_file_to_image(wolf->graphics.mlx_ptr,\
		"textures/head.xpm", &width, &height);
	wolf->graphics.wall[13] = mlx_xpm_file_to_image(wolf->graphics.mlx_ptr,\
		"textures/head.xpm", &width, &height);
	wolf->graphics.wall[14] = mlx_xpm_file_to_image(wolf->graphics.mlx_ptr,\
		"textures/head.xpm", &width, &height);
	wolf->graphics.wall[15] = mlx_xpm_file_to_image(wolf->graphics.mlx_ptr,\
		"textures/head.xpm", &width, &height);
}

void		load_image_ptr(t_wolf *wolf, int width, int height)
{
	wolf->graphics.wall[0] = mlx_xpm_file_to_image(wolf->graphics.mlx_ptr,\
		"textures/mossy.xpm", &width, &height);
	wolf->graphics.wall[1] = mlx_xpm_file_to_image(wolf->graphics.mlx_ptr,\
		"textures/dark_blue.xpm", &width, &height);
	wolf->graphics.wall[2] = mlx_xpm_file_to_image(wolf->graphics.mlx_ptr,\
		"textures/light_blue.xpm", &width, &height);
	wolf->graphics.wall[3] = mlx_xpm_file_to_image(wolf->graphics.mlx_ptr,\
		"textures/wood.xpm", &width, &height);
	wolf->graphics.wall[4] = mlx_xpm_file_to_image(wolf->graphics.mlx_ptr,\
		"textures/redbrick.xpm", &width, &height);
	wolf->graphics.wall[4] = NULL;
	wolf->graphics.wall[5] = mlx_xpm_file_to_image(wolf->graphics.mlx_ptr,\
		"textures/greystone.xpm", &width, &height);
	wolf->graphics.wall[6] = mlx_xpm_file_to_image(wolf->graphics.mlx_ptr,\
		"textures/bricks.xpm", &width, &height);
	wolf->graphics.wall[7] = mlx_xpm_file_to_image(wolf->graphics.mlx_ptr,\
		"textures/head.xpm", &width, &height);
	load_image_ptr2(wolf, width, height);
}

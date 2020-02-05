/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   mlx_setup.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jesmith <jesmith@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/05 13:01:30 by jesmith        #+#    #+#                */
/*   Updated: 2020/02/05 13:03:35 by jesmith       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "graphics.h"

void	mlx_setup(t_mlx *mlx)
{
	int		endian;

	endian = 0;
	mlx->mlx_ptr = mlx_init();
	mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, 1200, 600, mlx->title);
	if (mlx->win_ptr == NULL)
		mlx_exit(MALLOC_ERR);
	mlx->img_ptr = mlx_new_image(mlx->img_ptr, 1200, 600);
	if (mlx->img_ptr == NULL)
		mlx_exit(MALLOC_ERR);
	mlx->addr_str = mlx_get_data_addr(mlx->img_ptr, &mlx->bpp,
		&mlx->size_line, &endian);
	if (mlx->addr_str == NULL)
		mlx_exit(MALLOC_ERR);
}
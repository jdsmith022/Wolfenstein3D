/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mminkjan <mminkjan@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/03 20:34:26 by mminkjan       #+#    #+#                */
/*   Updated: 2020/02/03 20:50:26 by mminkjan      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void	wolf_exit(char *error)
{
	ft_putendl(error);
	exit(EXIT_FAILURE);
}

void	init_wolf(t_wolf *wolf)
{
	wolf = (t_wolf*)ft_memalloc(sizeof(t_wolf));
	if (wolf == NULL)
		wolf_exit(MALLOC_ERR);
}

void	init_mlx(t_wolf *wolf)
{
	int		endian;

	endian = 0;
	wolf->mlx_ptr = mlx_init();
	wolf->win_ptr = mlx_new_window(wolf->mlx_ptr, 1200, 600, "Wolf3d");
	if (wolf->win_ptr == NULL)
		wolf_exit(MALLOC_ERR);
	wolf->img_ptr = mlx_new_image(wolf->img_ptr, 1200, 600);
	if (wolf->img_ptr == NULL)
		wolf_exit(MALLOC_ERR);
	wolf->addr_str = mlx_get_data_addr(wolf->img_ptr, &wolf->bpp,
		&wolf->size_line, &endian);
	if (wolf->addr_str == NULL)
		wolf_exit(MALLOC_ERR);
}

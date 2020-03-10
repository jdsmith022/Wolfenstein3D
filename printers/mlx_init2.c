/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   mlx_init2.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jesmith <jesmith@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/09 19:32:24 by jesmith        #+#    #+#                */
/*   Updated: 2020/03/09 19:32:37 by jesmith       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void		init_mlx2(t_wolf *wolf)
{
	int		endian;

	endian = 0;
	wolf->mlx_ptr2 = mlx_init();
	wolf->image_ptr2 = mlx_new_image(wolf->mlx_ptr2, WIDTH, HEIGHT);
	if (wolf->image_ptr2 == NULL)
		wolf_failure_exit(wolf, NULL, MALLOC_ERR);
	wolf->addr_str2 = mlx_get_data_addr(wolf->image_ptr2, &wolf->bits_ppixel,
		&wolf->size_line, &endian);
	if (wolf->addr_str2 == NULL)
		wolf_failure_exit(wolf, NULL, MALLOC_ERR);
}

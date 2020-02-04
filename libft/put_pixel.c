/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   put_pixel.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jesmith <jesmith@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/04 12:27:14 by jesmith        #+#    #+#                */
/*   Updated: 2020/02/04 12:27:45 by jesmith       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	put_pixel(t_mlx *mlx, int color, int x, int y)
{
	size_t	index;

	if (x >= 0 && x < WIDTH && y < HEIGHT && y >= 0)
	{
		index = (y * fractol->size_line) + (x * fractol->bits_ppixel / 8);
		fractol->addr_str[index] = color;
		index++;
		fractol->addr_str[index] = color >> 8;
		index++;
		fractol->addr_str[index] = color >> 16;
	}
}

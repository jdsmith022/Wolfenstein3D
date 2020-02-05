/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_wolf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jesmith <jesmith@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/05 13:14:09 by jesmith        #+#    #+#                */
/*   Updated: 2020/02/05 13:33:57 by jesmith       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void	init_wolf(t_wolf *wolf)
{
	wolf = (t_wolf *)ft_memalloc(sizeof(t_wolf));
	if (wolf == NULL)
		wolf_failure_exit(wolf, MALLOC_ERR);
	wolf->win_width = 1200;
	wolf->win_height = 600;
}

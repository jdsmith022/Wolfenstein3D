/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_wolf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jesmith <jesmith@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/05 13:14:09 by jesmith        #+#    #+#                */
/*   Updated: 2020/02/05 18:25:30 by jesmith       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void	init_wolf(t_wolf *wolf)
{
	wolf = (t_wolf*)malloc(sizeof(t_wolf));
	if (wolf == NULL)
		wolf_failure_exit(wolf, MALLOC_ERR);
	wolf->win_width = 1200;
	wolf->win_height = 600;
	wolf->max_x = 0;
	wolf->max_y = 0;
}

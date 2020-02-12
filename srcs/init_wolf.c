/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_wolf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jesmith <jesmith@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/05 13:14:09 by jesmith        #+#    #+#                */
/*   Updated: 2020/02/12 17:45:54 by mminkjan      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

t_wolf	init_wolf(void)
{
	t_wolf wolf;

	wolf.max_x = 0;
	wolf.max_y = 0;
	wolf.item = NULL;
	wolf.pos.x = (WIDTH / 3) * 2;
	wolf.pos.y = (HEIGHT / 3) * 2;
	wolf.dir.x = 0;
	wolf.dir.y = -1;
	wolf.plane.x = 0;
	wolf.plane.y = 0.66;
	wolf.module = 300;
	wolf.height_wall = 300
	return (wolf);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_wolf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jesmith <jesmith@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/05 13:14:09 by jesmith        #+#    #+#                */
/*   Updated: 2020/02/11 12:12:00 by mminkjan      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

t_wolf	init_wolf(void)
{
	t_wolf wolf;

	wolf.win_width = 1200;
	wolf.win_height = 600;
	wolf.max_x = 0;
	wolf.max_y = 0;
	wolf.object = NULL;
	wolf.pos.x = wolf.win_width / 2;
	wolf.pos.y = wolf.win_height / 2;
	wolf.dir.x = 0;
	wolf.dir.y = 0;
	return (wolf);
}

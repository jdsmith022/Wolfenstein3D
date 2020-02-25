/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_wolf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jesmith <jesmith@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/05 13:14:09 by jesmith        #+#    #+#                */
/*   Updated: 2020/02/25 16:44:21 by jesmith       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

t_wolf	init_wolf(void)
{
	t_wolf wolf;

	ft_bzero(&wolf, sizeof(t_wolf));
	wolf.max_x = 0;
	wolf.max_y = 0;
	wolf.item = NULL;
	wolf.pos.x = 500;
	wolf.pos.y = 150;
	wolf.dir_angle = 0.9;
	wolf.dir.x = 0;
	wolf.dir.y = -1;
	wolf.plane.x = 0;
	wolf.plane.y = 66;
	wolf.module = 300;
	wolf.height = 0;
	wolf.wall_height = 300;
	wolf.obj_height = 70; //seperate func assignment
	return (wolf);
}

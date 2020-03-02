/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_wolf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jesmith <jesmith@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/05 13:14:09 by jesmith        #+#    #+#                */
/*   Updated: 2020/03/02 20:09:24 by mminkjan      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

t_wolf	init_wolf(void)
{
	t_wolf wolf;

	ft_bzero(&wolf, sizeof(t_wolf));
	wolf.max_x = 0;
	wolf.max_y = 0;
	wolf.bound = 0;
	wolf.item = NULL;
	wolf.pos.x = 500;
	wolf.pos.y = 150;
	wolf.dir_angle = 180 * (PI / 180);
	wolf.dist_to_plane = (WIDTH / 2) / tan(FOV / 2);
	wolf.module = 300;
	wolf.height = 0;
	wolf.wall_height = 250;
	wolf.ray_angle = FOV / WIDTH;
	wolf.obj_height = 70; //seperate func assignment
	return (wolf);
}

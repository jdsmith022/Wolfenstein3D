/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_wolf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jesmith <jesmith@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/05 13:14:09 by jesmith       #+#    #+#                 */
/*   Updated: 2020/06/28 13:16:49 by jesmith       ########   odam.nl         */
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
	wolf.pos.x = 10;
	wolf.pos.y = 10;
	wolf.dir_angle = 20;
	wolf.dist_to_plane = (WIDTH / 2) / tan(FOV / 2);
	wolf.wall_width = 64;
	wolf.wall_height = 64;
	wolf.ray_angle = FOV / WIDTH;
	wolf.obj_height = 70;
	return (wolf);
}

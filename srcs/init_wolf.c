/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_wolf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jesmith <jesmith@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/05 13:14:09 by jesmith       #+#    #+#                 */
/*   Updated: 2020/04/05 14:15:53 by JessicaSmit   ########   odam.nl         */
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
	wolf.dir_angle = 145 * (PI / 180);
	wolf.dist_to_plane = (WIDTH / 2) / tan(FOV / 2);
	wolf.wall_width = 64;
	wolf.wall_height = 64;
	wolf.ray_angle = FOV / WIDTH;
	wolf.obj_height = 70; //seperate func assignment
	return (wolf);
}

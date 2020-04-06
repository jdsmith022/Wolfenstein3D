/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   key_player_movement.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: jesmith <jesmith@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/10 11:15:21 by jesmith       #+#    #+#                 */
/*   Updated: 2020/04/06 17:16:29 by JessicaSmit   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

static void		player_side_movement(t_wolf *wolf, int key,
					t_point *pos, double *move_angle)
{
	double radian;
	double reverse_radian;

	radian = 90 * PI / 180;
	reverse_radian = 180 * PI / 180;
	if (key == A)
	{
		pos->x += SPEED * cos(wolf->dir_angle - radian);
		pos->y += SPEED * sin(wolf->dir_angle - radian);
		*(move_angle) = wolf->dir_angle + radian * reverse_radian;
	}
	if (key == D)
	{
		pos->x += SPEED * cos(wolf->dir_angle + radian);
		pos->y += SPEED * sin(wolf->dir_angle + radian);
		*(move_angle) = wolf->dir_angle - radian * reverse_radian;
	}
}

void			key_player_movement(t_wolf *wolf, int key,
					t_point *pos, double *move_angle)
{
	double radian;

	radian = 90 * PI / 180;
	if (key == W)
	{
		pos->x += SPEED * cos(wolf->dir_angle);
		pos->y += SPEED * sin(wolf->dir_angle);
		*(move_angle) = wolf->dir_angle;
	}
	if (key == S)
	{
		pos->x -= SPEED * cos(wolf->dir_angle);
		pos->y -= SPEED * sin(wolf->dir_angle);
		*(move_angle) = wolf->dir_angle + 180 * PI / 180;
	}
	if (key == A || key == D)
		player_side_movement(wolf, key, pos, move_angle);
}

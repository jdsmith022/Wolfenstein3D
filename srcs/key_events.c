/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   key_events.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mminkjan <mminkjan@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/10 19:09:56 by mminkjan       #+#    #+#                */
/*   Updated: 2020/03/03 16:00:44 by jesmith       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

static void	key_player_position(t_wolf *wolf, int key)
{
	t_point pos;
	double	radian;

	pos = wolf->pos;
	radian = 90 * PI / 180;
	if (key == W)
	{
		pos.x += SPEED * cos(wolf->dir_angle);
		pos.y += SPEED * sin(wolf->dir_angle);
	}
	if (key == S)
	{
		pos.x -= SPEED * cos(wolf->dir_angle);
		pos.y -= SPEED * sin(wolf->dir_angle);
	}
	if (key == A && wolf->pos.x >= 10)
	{
		pos.x += SPEED * cos(wolf->dir_angle - radian);
		pos.y += SPEED * sin(wolf->dir_angle - radian);
	}
	if (key == D)
	{
		pos.x += SPEED * cos(wolf->dir_angle + radian);
		pos.y += SPEED * sin(wolf->dir_angle + radian);
	}
	printf("pos: %d     %d, %d\n", wolf->map[(int)round(pos.y / wolf->module)][(int)round(pos.x / wolf->module)], (int)round(pos.x / wolf->module), (int)round(pos.y / wolf->module));
	if (wolf->map[(int)round(pos.y / wolf->module)][(int)round(pos.x / wolf->module)] == 0)
		wolf->pos = pos;
}

static void	key_window_handling(t_wolf *wolf, int key)
{
	if (key == ESC)
		wolf_success_exit(wolf);
}

static int			key_events(int key, t_wolf *wolf)
{
	key_window_handling(wolf, key);
	key_player_position(wolf, key);
	return (0);
}

void		mlx_key(t_wolf *wolf)
{
	mlx_hook(wolf->win_ptr, 2, 0, key_events, wolf);
	mlx_hook(wolf->win_ptr, 17, 0, wolf_success_exit, wolf);
}

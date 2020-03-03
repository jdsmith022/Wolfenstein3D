/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   key_events.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mminkjan <mminkjan@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/10 19:09:56 by mminkjan       #+#    #+#                */
/*   Updated: 2020/03/03 11:07:14 by mminkjan      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

static void	key_player_position(t_wolf *wolf, int key)
{
	wolf->event.hold_angle = wolf->dir_angle;
	if (key == W)
	{
		wolf->pos.x += SPEED * cos(wolf->dir_angle);
		wolf->pos.y += SPEED * sin(wolf->dir_angle);
	}
	if (key == S)
	{
		wolf->pos.x -= SPEED * cos(wolf->dir_angle);
		wolf->pos.y -= SPEED * sin(wolf->dir_angle);
	}
	if (key == A && wolf->pos.x >= 10)
	{
		wolf->pos.x += SPEED * cos(wolf->dir_angle - (90 * PI / 180));
		wolf->pos.y += SPEED * sin(wolf->dir_angle - (90 * PI / 180));
	}
	else if (key == D)
	{
		wolf->pos.x += SPEED * cos(wolf->dir_angle + (90 * PI / 180));
		wolf->pos.y += SPEED * sin(wolf->dir_angle + (90 * PI / 180));
	}
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

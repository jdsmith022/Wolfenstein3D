/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   key_events.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mminkjan <mminkjan@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/10 19:09:56 by mminkjan       #+#    #+#                */
/*   Updated: 2020/02/25 11:35:52 by jesmith       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

static void	key_player_position(t_wolf *wolf, int key)
{
	wolf->event.hold_angle = wolf->dir_angle;
	// dependant on direction as well......another check in if statement
	printf("angle: %f\n", wolf->dir_angle);
	if (key == W)
	{
		if (wolf->pos.y >= 10)
			wolf->pos.y -= 10;
	}
	else if (key == S)
		wolf->pos.y += 10;
	if (key == A && wolf->pos.x >= 10)
		wolf->pos.x -= 10;
	else if (key == D)
		wolf->pos.x += 10;
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

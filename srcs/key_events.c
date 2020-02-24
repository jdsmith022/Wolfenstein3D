/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   key_events.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mminkjan <mminkjan@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/10 19:09:56 by mminkjan       #+#    #+#                */
/*   Updated: 2020/02/24 18:13:30 by jesmith       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

static void	key_player_position(t_wolf *wolf, int key)
{
	if (key == W && wolf->pos.y < HEIGHT && wolf->pos.y > 10)
		wolf->player.y -= 10;
	else if (key == S && wolf->pos.y < HEIGHT && wolf->pos.y > 0)
		wolf->player.y += 10;
	if (key == A && wolf->pos.x < WIDTH && wolf->pos.x > 10)
		wolf->player.x -= 10;
	else if (key == D && wolf->pos.x < WIDTH && wolf->pos.x > 0)
		wolf->player.x += 10;
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

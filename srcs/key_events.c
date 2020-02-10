/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   key_events.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mminkjan <mminkjan@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/10 19:09:56 by mminkjan       #+#    #+#                */
/*   Updated: 2020/02/10 19:34:22 by mminkjan      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void	key_window_handling(t_wolf *wolf, int key)
{
	if (key == ESC)
		wolf_success_exit(wolf);
}

int		key_events(int key, t_wolf *wolf)
{
	key_window_handling(wolf, key);
	// key_navigation(wolf, key);
	return (0);
}

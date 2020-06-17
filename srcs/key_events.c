/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   key_events.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mminkjan <mminkjan@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/10 19:09:56 by mminkjan      #+#    #+#                 */
/*   Updated: 2020/06/17 19:20:25 by mminkjan      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

static int		intersect_with_object(t_wolf *wolf, t_point start, t_point end)
{
	t_item	*object;
	t_point intersect;

	object = wolf->item;
	while (object != NULL)
	{
		intersect = find_intersection_point(start, end,\
			object->start, object->end);
		if (isnan(intersect.x) == 0 || isnan(intersect.y) == 0)
			return (-1);
		object = object->next;
	}
	return (0);
}

static void		move_player_rl(t_wolf *wolf, double direction)
{
	t_point pos;

	pos = wolf->pos;
	pos.x += SPEED * cos(wolf->dir_angle + direction);
	pos.y += SPEED * sin(wolf->dir_angle + direction);
	if (intersect_with_object(wolf, wolf->pos, pos) == 0)
		wolf->pos = pos;
}

static void		move_player_fw(t_wolf *wolf, int direction)
{
	t_point pos;

	pos = wolf->pos;
	pos.x += direction * cos(wolf->dir_angle);
	pos.y += direction * sin(wolf->dir_angle);
	if (intersect_with_object(wolf, wolf->pos, pos) == 0)
		wolf->pos = pos;
}

static int		key_events(int key, t_wolf *wolf)
{
	if (key == W)
		move_player_fw(wolf, SPEED);
	else if (key == S)
		move_player_fw(wolf, -SPEED);
	else if (key == A)
		move_player_rl(wolf, (double)(-90 * PI / 180));
	else if (key == D)
		move_player_rl(wolf, (double)(90 * PI / 180));
	if (key == ALT)
	{
		if (wolf->event.colors == 0)
			wolf->event.colors = 1;
		else
			wolf->event.colors = 0;
	}
	if (key == ESC)
		wolf_success_exit(wolf);
	return (0);
}

void			mlx_key(t_wolf *wolf)
{
	mlx_hook(wolf->graphics.win_ptr, 2, 0, key_events, wolf);
	mlx_hook(wolf->graphics.win_ptr, 17, 0, wolf_success_exit, wolf);
}

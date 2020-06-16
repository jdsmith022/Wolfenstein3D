/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   key_events.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mminkjan <mminkjan@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/10 19:09:56 by mminkjan      #+#    #+#                 */
/*   Updated: 2020/06/16 17:50:24 by Malou         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

static int		intersect_direction(t_wolf *wolf,
					double move_angle, t_point pos)
{
	double		angle;
	t_item		ray;
	int			x;

	x = 0;
	angle = move_angle - (FOV / 2);
	ray.start.x = pos.x;
	ray.start.y = pos.y;
	while (x < WIDTH)
	{
		angle = clamp_angle(angle);
		ray.end.x = ray.start.x + wolf->max_ray * cos(angle);
		ray.end.y = ray.start.y + wolf->max_ray * sin(angle);
		wolf->intersect = find_intersect(wolf, ray, angle);
		angle += wolf->ray_angle;
		x++;
	}
	if (wolf->intersect.obj_dist <= 20 || pos.x < 0 || pos.y < 0 \
		|| pos.x > wolf->max_x * wolf->wall_width || \
		pos.y > wolf->max_y * wolf->wall_width)
		return (1);
	return (0);
}

static void		key_player_position(t_wolf *wolf, int key)
{
	t_point pos;
	double	move_angle;

	pos = wolf->pos;
	key_player_movement(wolf, key, &pos, &move_angle);
	if (intersect_direction(wolf, move_angle, pos) == 0)
		wolf->pos = pos;
}

static void		key_handling(t_wolf *wolf, int key)
{
	if (key == ALT)
	{
		if (wolf->event.colors == 0)
			wolf->event.colors = 1;
		else
			wolf->event.colors = 0;
	}
	if (key == ESC)
		wolf_success_exit(wolf);
}

static int		key_events(int key, t_wolf *wolf)
{
	if (key == W || key == S || key == A || key == D)
		key_player_position(wolf, key);
	if (key == ALT || key == ESC)
		key_handling(wolf, key);
	return (0);
}

void			mlx_key(t_wolf *wolf)
{
	mlx_hook(wolf->graphics.win_ptr, 2, 0, key_events, wolf);
	mlx_hook(wolf->graphics.win_ptr, 17, 0, wolf_success_exit, wolf);
}

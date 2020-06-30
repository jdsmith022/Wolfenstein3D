/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   save_map_coordinates.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mminkjan <mminkjan@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/08 14:14:17 by mminkjan      #+#    #+#                 */
/*   Updated: 2020/06/30 16:48:46 by mminkjan      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

static t_item	*init_item(t_wolf *wolf, t_i i,
					int **map_values, char dir)
{
	t_item *item;

	item = (t_item*)ft_memalloc(sizeof(t_item));
	if (item == NULL)
		wolf_failure_exit(wolf, map_values, MALLOC_ERR);
	item->dir = dir;
	item->start.x = i.x * wolf->wall_width;
	item->start.y = i.y * wolf->wall_width;
	item->end.x = item->start.x;
	item->end.y = item->start.y;
	item->texture = map_values[i.y][i.x];
	if (dir == 'h' && item->texture != map_values[i.y][i.x + 1]
			&& ((i.y - 1 >= 0 && map_values[i.y - 1][i.x] == item->texture)
			|| (i.y + 1 < wolf->max_y && \
			map_values[i.y + 1][i.x] == item->texture)))
		item->texture = map_values[i.y][i.x + 1];
	else if (dir == 'v' && item->texture != map_values[i.y + 1][i.x]
			&& ((i.x - 1 >= 0 && map_values[i.y][i.x - 1] == item->texture)
			|| (i.x + 1 < wolf->max_x && \
			map_values[i.y][i.x + 1] == item->texture)))
		item->texture = map_values[i.y + 1][i.x];
	return (item);
}

static t_i		check_vertical_coordinates(t_wolf *wolf,
					int **map_values, t_i i)
{
	t_item	*item;
	int		value;

	item = init_item(wolf, i, map_values, 'v');
	value = map_values[i.y][i.x];
	if (i.y + 1 < wolf->max_x && map_values[i.y + 1][i.x] == value)
	{
		while (i.y + 1 < wolf->max_y && map_values[i.y + 1][i.x] == value)
		{
			item->end.y += wolf->wall_width;
			i.y++;
		}
		if (i.y + 1 < wolf->max_y && map_values[i.y + 1][i.x] != 0)
			item->end.y += wolf->wall_width;
	}
	else
		item->end.y += wolf->wall_width;
	lst_addback(&wolf->item, item);
	return (i);
}

static t_i		horizontal_coordinates(t_wolf *wolf,
					int **map_values, t_i i)
{
	t_item	*item;
	int		value;

	item = init_item(wolf, i, map_values, 'h');
	value = map_values[i.y][i.x];
	if (i.x + 1 < wolf->max_x && map_values[i.y][i.x + 1] == value)
	{
		while (i.x + 1 < wolf->max_x && map_values[i.y][i.x + 1] == value)
		{
			item->end.x += wolf->wall_width;
			i.x++;
		}
		if (i.x + 1 < wolf->max_x && map_values[i.y][i.x + 1] != 0)
			item->end.x += wolf->wall_width;
	}
	else
		item->end.x += wolf->wall_width;
	lst_addback(&wolf->item, item);
	return (i);
}

static void		check_horizontal_coordinates(t_wolf *wolf)
{
	t_i iterate;

	iterate.y = 0;
	iterate.x = 0;
	while (iterate.y < wolf->max_y)
	{
		if (wolf->map[iterate.y][iterate.x] != 0 &&
			(((iterate.x + 1 < wolf->max_x &&
			wolf->map[iterate.y][iterate.x + 1] != 0) ||
			iterate.x + 1 == wolf->max_x) ||
			(((iterate.y + 1 < wolf->max_y &&
			wolf->map[iterate.y + 1][iterate.x] == 0) ||
			iterate.y + 1 == wolf->max_y) &&
			((iterate.y - 1 > 0 &&
			wolf->map[iterate.y - 1][iterate.x] == 0) ||
			iterate.y - 1 == 0))))
			iterate = horizontal_coordinates(wolf, wolf->map, iterate);
		iterate.x++;
		if (iterate.x >= wolf->max_x - 1)
		{
			iterate.y++;
			iterate.x = 0;
		}
	}
}

void			save_map_coordinates(t_wolf *wolf)
{
	t_i		iterate;

	iterate.x = 0;
	iterate.y = 0;
	check_horizontal_coordinates(wolf);
	while (iterate.x < wolf->max_x)
	{
		if (wolf->map[iterate.y][iterate.x] != 0 && ((iterate.y + 1 < \
			wolf->max_y && wolf->map[iterate.y + 1][iterate.x] != 0)
			|| iterate.y + 1 == wolf->max_y))
			iterate = check_vertical_coordinates(wolf, wolf->map, iterate);
		iterate.y++;
		if (iterate.y >= wolf->max_y - 1)
		{
			iterate.y = 0;
			iterate.x++;
		}
	}
}

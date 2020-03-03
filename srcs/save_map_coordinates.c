/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   save_map_coordinates.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mminkjan <mminkjan@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/08 14:14:17 by mminkjan       #+#    #+#                */
/*   Updated: 2020/03/03 16:02:25 by jesmith       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

static void	save_vertical_item(t_wolf *wolf, t_point start,
				t_i *i, int **map_values)
{
	t_item *item;

	item = (t_item*)ft_memalloc(sizeof(t_item));
	if (item == NULL)
		wolf_failure_exit(wolf, map_values, MALLOC_ERR);
	item->start = start;
	if (i->y + 1 == wolf->max_y)
		item->end.y = (i->y - 1) * wolf->module;
	else
		item->end.y = i->y * wolf->module;
	item->end.x = start.x;
	item->texture = map_values[i->y][i->x];
	item->next = NULL;
	lst_addback(&wolf->item, item);
}

static void	vertical_coordinates(t_wolf *wolf, int **values, t_i *i)
{
	t_point start;
	int		hold_y;

	i->y = 0;
	hold_y = 0;
	ft_bzero(&start, sizeof(t_point));
	if ((i->x + 1 == wolf->max_x) || (i->x != 1 && i->x != 0))
		start.x = (i->x - 1) * wolf->module;
	else
		start.x = i->x * wolf->module;
	while (i->y < wolf->max_y)
	{
		if (values[i->y][i->x] > 0 && values[i->y][i->x] < 5)
		{
			while (i->y + 1 < wolf->max_y && \
			values[i->y + 1][i->x] == values[i->y][i->x])
				i->y++;
			if ((i->y + 1 == wolf->max_y && hold_y + 1 != i->y) || \
			(i->y > 0 && i->y + 1 < wolf->max_y && values[i->y - 1][i->x] != 0))
				save_vertical_item(wolf, start, i, values);
		}
		hold_y = i->y;
		start.y = i->y * wolf->module;
		i->y++;
	}
}

static void	save_horizontal_item(t_wolf *wolf, t_point start,
				t_i *i, int **map_values)
{
	t_item *item;

	item = (t_item*)ft_memalloc(sizeof(t_item));
	if (item == NULL)
		wolf_failure_exit(wolf, map_values, MALLOC_ERR);
	item->start = start;
	if (i->x + 1 == wolf->max_x)
		item->end.x = (i->x - 1) * wolf->module;
	else if (map_values[i->y][i->x] > 4)
		item->end.x = (i->x + 1) * 70;
	else
		item->end.x = i->x * wolf->module;
	item->end.y = start.y;
	item->texture = map_values[i->y][i->x];
	item->next = NULL;
	lst_addback(&wolf->item, item);
}

static void	horizontal_coordinates(t_wolf *wolf, int **values, t_i *i)
{
	t_point start;

	i->x = 0;
	ft_bzero(&start, sizeof(t_point));
	if (i->y != 0 && i->y + 1 != wolf->max_y)
		start.y = i->y * wolf->module;
	if (i->y + 1 == wolf->max_y)
		start.y = (i->y - 1) * wolf->module;
	while (i->x < wolf->max_x - 1)
	{
		if (values[(int)i->y][(int)i->x] != 0)
		{
			while (values[i->y][i->x + 1] == values[i->y][i->x])
				i->x++;
			if ((values[i->y][i->x - 1] < 5 && values[i->y][i->x - 1] > 0 \
			&& values[i->y][i->x + 1] >= 0) || \
			(values[i->y][i->x + 1] > 0 && values[i->y][i->x + 1] < 5))
				save_horizontal_item(wolf, start, i, values);
		}
		start.x = i->x * wolf->module;
		if (i->y != 0)
			i->x++;
	}
}

void		save_map_coordinates(t_wolf *wolf)
{
	t_i		iterate;

	iterate.y = 0;
	while (iterate.y < wolf->max_y)
	{
		horizontal_coordinates(wolf, wolf->map, &iterate);
		iterate.y++;
	}
	iterate.x = 0;
	while (iterate.x < wolf->max_x)
	{
		vertical_coordinates(wolf, wolf->map, &iterate);
		iterate.x++;
	}
}

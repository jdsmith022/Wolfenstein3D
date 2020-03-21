/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   save_map_coordinates.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mminkjan <mminkjan@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/08 14:14:17 by mminkjan       #+#    #+#                */
/*   Updated: 2020/03/21 10:50:12 by Malou         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

// static void	save_vertical_item(t_wolf *wolf, t_point start,
// 				t_i *i, int **map_values)
// {
// 	t_item *item;

// 	item = (t_item*)ft_memalloc(sizeof(t_item));
// 	if (item == NULL)
// 		wolf_failure_exit(wolf, map_values, MALLOC_ERR);
// 	item->start = start;
// 	if (i->y + 1 == wolf->max_y)
// 		item->end.y = (i->y - 1) * wolf->wall_width + 64;
// 	else
// 		item->end.y = i->y * wolf->wall_width + 64;
// 	item->end.x = start.x;
// 	item->texture = map_values[i->y][i->x];
// 	item->next = NULL;
// 	lst_addback(&wolf->item, item);
// }

// static void	vertical_coordinates(t_wolf *wolf, int **values, t_i *i)
// {
// 	t_point start;

// 	i->y = 0;
// 	ft_bzero(&start, sizeof(t_point));
// 	if ((i->x + 1 == wolf->max_x) || (i->x > 1))
// 		start.x = (i->x - 1) * wolf->wall_width + 64;
// 	else
// 		start.x = i->x * wolf->wall_width + 64;
// 	while (i->y < wolf->max_y)
// 	{
// 		if (values[i->y][i->x] > 0 && values[i->y][i->x] < 5)
// 		{
// 			while (i->y + 1 < wolf->max_y && \
// 			values[i->y + 1][i->x] == values[i->y][i->x])
// 				i->y++;
// 			if ((i->x == 0) || (i->y + 1 < wolf->max_y && i->y - 1 >= 0 && \
// 				values[i->y + 1][i->x] < 5 && values[i->y - 1][i->x] > 0) || \
// 				(i->x + 1 == wolf->max_x))
// 				save_vertical_item(wolf, start, i, values);
// 		}
// 		start.y = i->y * wolf->wall_width + 64;
// 		i->y++;
// 	}
// }

// static void	save_horizontal_item(t_wolf *wolf, t_point start,
// 				t_i *i, int **map_values)
// {
// 	t_item *item;

// 	item = (t_item*)ft_memalloc(sizeof(t_item));
// 	if (item == NULL)
// 		wolf_failure_exit(wolf, map_values, MALLOC_ERR);
// 	item->start = start;
// 	if (i->x + 1 == wolf->max_x)
// 		item->end.x = (i->x - 1) * wolf->wall_width + 64;
// 	else if (map_values[i->y][i->x] > 4)
// 		item->end.x = (i->x + 1) * 70;
// 	else
// 		item->end.x = i->x * wolf->wall_width + 64;
// 	item->end.y = start.y;
// 	item->texture = map_values[i->y][i->x];
// 	item->next = NULL;
// 	lst_addback(&wolf->item, item);
// }

// static void	horizontal_coordinates(t_wolf *wolf, int **values, t_i *i)
// {
// 	t_point start;
// 	int		hold_x;

// 	i->x = 0;
// 	hold_x = 0;
// 	ft_bzero(&start, sizeof(t_point));
// 	if (i->y + 1 == wolf->max_y)
// 		start.y = (i->y - 1) * wolf->wall_width + 64;
// 	else
// 		start.y = i->y * wolf->wall_width + 64;
// 	while (i->x < wolf->max_x - 1)
// 	{
// 		if (values[(int)i->y][(int)i->x] != 0)
// 		{
// 			while (values[i->y][i->x + 1] == values[i->y][i->x])
// 				i->x++;
// 			if ((i->y + 1 < wolf->max_y && values[i->y + 1][i->x] == 0 && values[i->y][i->x + 1] != 0) || \
// 				(i->x == 1 && i->y + 1 < wolf->max_y && values[i->y - 1][i->x] == 0 && values[i->y + 1][i->x] == 0) || \
// 				(i->y + 1 == wolf->max_y) || (i->y == 0) || (hold_x != i->x))
// 				save_horizontal_item(wolf, start, i, values);
// 		}
// 		start.x = i->x * wolf->wall_width + 64;
// 		if (i->y != 0)
// 			i->x++;
// 		hold_x = i->x;
// 	}
// }

// static t_i vertical_coordinates(t_wolf *wolf, int **map_values, t_i i)
// {
// 	int value;

// 	wolf->item = (t_item*)ft_memalloc(sizeof(t_item));
// 	if (wolf->item == NULL)
// 		wolf_failure_exit(wolf, map_values, MALLOC_ERR);
// 	value = map_values[i.y][i.x];
// 	wolf->item->start.x = i.x;
// 	wolf->item->start.y = i.y;
// 	wolf->item->end.x = i.y;
// 	wolf->item->end.y = i.y;
// 	wolf->item->texture = value;
// 	while (i.y + 1 < wolf->max_y && map_values[i.y + 1][i.x] == value)
// 	{
// 		wolf->item->end.y += wolf->wall_width;
// 		i.y++;
// 	}
// 	return(i);

// }

static t_item *init_item(t_wolf *wolf, t_i i, int **map_values, char dir)
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
			|| (i.y + 1 < wolf->max_y && map_values[i.y + 1][i.x] == item->texture)))
		item->texture = map_values[i.y][i.x + 1];
	else if (dir == 'v' && item->texture != map_values[i.y + 1][i.x]
			&& ((i.x - 1 >= 0 && map_values[i.y][i.x - 1] == item->texture) 
			|| (i.x + 1 < wolf->max_x && map_values[i.y][i.x + 1] == item->texture)))
		item->texture = map_values[i.y + 1][i.x];
	return (item);
}

static t_i	check_vertical_coordinates(t_wolf *wolf, int **map_values, t_i i)
{
	int value;
	t_item *item;

	item = init_item(wolf, i , map_values, 'v');
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
	return(i);
}

static t_i	horizontal_coordinates(t_wolf *wolf, int **map_values, t_i i)
{
	int value;
	t_item *item;

	item = init_item(wolf, i , map_values, 'h');
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
	return(i);
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
			iterate.x + 1  == wolf->max_x) ||
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

void	save_map_coordinates(t_wolf *wolf)
{
	t_i		iterate;

	iterate.x = 0;
	iterate.y = 0;
	check_horizontal_coordinates(wolf);
	while (iterate.x < wolf->max_x)
	{
		if (wolf->map[iterate.y][iterate.x] != 0 && 
			((iterate.y + 1 < wolf->max_y && wolf->map[iterate.y + 1][iterate.x] != 0)
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

/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   save_map_coordinates.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mminkjan <mminkjan@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/08 14:14:17 by mminkjan       #+#    #+#                */
/*   Updated: 2020/02/08 17:14:24 by mminkjan      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

static void	lst_addback(t_object *object, t_object *points)
{
	t_object *temp;

	temp = object;
	if (temp == NULL)
	{
		object = points;
		return ;
	}
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = points;
}

static void	vertical_coordinates(t_wolf *wolf, int **map_values, int x, t_object *object)
{
	t_object	*points;
	int			texture;
	int			y;

	y = 0;
	while (y < wolf->max_x)
	{
		texture = map_values[y][x];
		if (texture != 0)
		{
			if (map_values[y + 1][x] == texture || map_values[y + 1][x] != 0)
				points = (t_object *)ft_memalloc(sizeof(t_object));
			if (points == NULL)
				wolf_failure_exit(wolf, map_values, MALLOC_ERR);
			points->start.x = x * wolf->module;
			points->start.y = y * wolf->module;
			points->texture = texture;
			while ((y + 1) <= wolf->max_y && map_values[y + 1][x] == texture)
				y++;
			if (((y + 1) <= wolf->max_y) && map_values[y + 1][x] != texture && map_values[y + 1][x] != 0)
				y++;
			points->end.x = x * wolf->module;
			points->end.y = y * wolf->module;
			points->next = NULL;
			lst_addback(wolf->object, points);
		}
		y++;
	}
}

t_object	*horizontal_coordinates(t_wolf *wolf, int **map_values, int y, t_object *objects)
{
	t_object *points;
	int		texture;
	int		x;

	x = 0;
	while (x < wolf->max_x)
	{
		texture = map_values[y][x];
		if (texture != 0)
		{
			if (map_values[y + 1][x] == 0 || map_values[y][x + 1] == texture)
				points = (t_object *)ft_memalloc(sizeof(t_object));
			if (points == NULL)
				wolf_failure_exit(wolf, map_values, MALLOC_ERR);
			points->start.x = x * wolf->module;
			points->start.y = y * wolf->module;
			points->texture = texture;
			while ((x + 1) <= wolf->max_x && (map_values[y][x + 1]) == texture)
				x++;
			if (map_values[y + 1][x] != texture)
			{
				points->end.x = x * wolf->module;
				points->end.y = y * wolf->module;
				points->next = NULL;
				lst_addback(wolf->object, points);
			}
		}
		x++;
	}
}

void		save_map_coordinates(t_wolf *wolf, int **map_values)
{
	t_object	*objects;
	int			x;
	int			y;

	x = 0;
	y = 0;
	objects = (t_object *)ft_memalloc(sizeof(t_object));
	if (objects == NULL)
		wolf_failure_exit(wolf, map_values, MALLOC_ERR);
	objects->next = NULL;
	while (y < wolf->max_y)
	{
		horizontal_coordinates(wolf, map_values, y, objects);
		y++;
	}
	while (x < wolf->max_x)
	{
		vertical_coordinates(wolf, map_values, x, objects);
		x++;
	}
}

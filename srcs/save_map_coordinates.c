/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   save_map_coordinates.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mminkjan <mminkjan@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/08 14:14:17 by mminkjan       #+#    #+#                */
/*   Updated: 2020/02/11 15:01:12 by JessicaSmit   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

static void	lst_addback(t_object **object_list, t_object *object)
{
	t_object *temp;

	temp = *object_list;
	if (temp == NULL)
	{
		*object_list = object;
		return ;
	}
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = object;
}

static void	save_object(t_wolf *wolf, t_point start,
				int x, int y, int **map_values, int texture)
{
	t_object *object;

	object = (t_object*)ft_memalloc(sizeof(t_object));
	if (object == NULL)
		wolf_failure_exit(wolf, map_values, MALLOC_ERR);
	object->start = start;
	object->end.x = x * wolf->module;
	object->end.y = y * wolf->module;
	object->texture = texture;
	object->next = NULL;
	lst_addback(&wolf->object, object);
}

static void	vertical_coordinates(t_wolf *wolf, int **values, int x)
{
	t_point		start;
	int			texture;
	int			height;
	int			y;

	y = 0;
	while (y < wolf->max_y)
	{
		height = 0;
		texture = values[y][x];
		if (texture != 0)
		{
			start.x = x * wolf->module;
			start.y = y * wolf->module;
			while (y + 1 < wolf->max_y && values[y + 1][x] == texture)
			{
				height++;
				y++;
			}
			if (height > 0)
				save_object(wolf, start, x, y, values, texture);
		}
		y++;
	}
}

// static void	horizontal_coordinates(t_wolf *wolf, int **values, int y)
// {
// 	t_point start;
// 	int		texture;
// 	int		x;
// 	int		width;

// 	x = 0;
// 	while (x < wolf->max_x)
// 	{
// 		texture = values[y][x];
// 		width = 0;
// 		if (texture != 0)
// 		{
// 			start.x = x * wolf->module;
// 			start.y = y * wolf->module;
// 			while (x + 1 < wolf->max_x && values[y][x + 1] == texture)
// 			{
// 				width++;
// 				x++;
// 			}
// 			if (width == 0 && x > 0 && (y = 1 < wolf->max_y && values[y + 1][x] != texture))
// 				x++;
// 			if (x != 0 && x < wolf->max_x)
// 				save_object(wolf, start, x, y, values, texture);
// 		}
// 		x++;
// 	}
// }

static void	horizontal_coordinates(t_wolf *wolf, int **values, int y)
{
	t_point start;
	int		texture;
	int		x;
	int		start_x;

	x = 0;
	start.x = 0;
	start_x = 0;
	start.y = y * wolf->module;
	while (x < wolf->max_x)
	{
		texture = values[y][x];
		if (texture != 0)
		{
			printf("texture: %d\n", texture);
			while (values[y][x + 1] == texture)
				x++;
			if (x > 0 && x < wolf->max_x && x == start_x && texture < 5) //&& (y + 1 < wolf->max_y && values[y + 1][x] != texture))
				x++;
			if ((start_x != x && values[y][x - 1] != 0) || (start_x == x - 1 && texture > 4))
			{
				printf("x: %d, %d start: %d\n", x, y, start_x);
				save_object(wolf, start, x, y, values, texture);
			}
		}
		// if (x == 0)
		// 	x++;
		printf("endx: %d and y: %d\n", x, y);
		start.x = x * wolf->module;
		if (x > 0)
			start_x = x;
		x++;
		if (x == 0)
			start_x = x;

	}
}

void		save_map_coordinates(t_wolf *wolf, int **map_values)
{
	t_object	*objects;
	int			x;
	int			y;

	x = 0;
	y = 0;
	printf("mod: %d\n", wolf->module);
	printf("max_x: %d\n", wolf->max_x);
	objects = (t_object*)ft_memalloc(sizeof(t_object));
	if (objects == NULL)
		wolf_failure_exit(wolf, map_values, MALLOC_ERR);
	objects->next = NULL;
	while (y < wolf->max_y)
	{
		horizontal_coordinates(wolf, map_values, y);
		y++;
	}
	while (x < wolf->max_x)
	{
		vertical_coordinates(wolf, map_values, x);
		x++;
	}
}


// static void	lst_addback(t_object **object_list, t_object *object)
// {
// 	t_object *temp;

// 	temp = *object_list;
// 	if (temp == NULL)
// 	{
// 		*object_list = object;
// 		return ;
// 	}
// 	while (temp->next != NULL)
// 		temp = temp->next;
// 	temp->next = object;
// }

// static void	save_object(t_wolf *wolf, t_point start, int x, int y, int **map_values)
// {
// 	t_object *object;

// 	object = (t_object*)ft_memalloc(sizeof(t_object));
// 	if (object == NULL)
// 		wolf_failure_exit(wolf, map_values, MALLOC_ERR);
// 	object->start = start;
// 	object->end.x = x * wolf->module;
// 	object->end.y = y * wolf->module;
// 	object->texture = map_values[y][x];
// 	object->next = NULL;
// 	lst_addback(&wolf->object, object);
// }

// static void	vertical_coordinates(t_wolf *wolf, int **values, int x)
// {
// 	t_point		start;
// 	int			texture;
// 	int			lenght;
// 	int			y;

// 	y = 0;
// 	while (y < wolf->max_y)
// 	{
// 		texture = values[y][x];
// 		lenght = 0;
// 		if (texture != 0)
// 		{
// 			start.x = x * wolf->module;
// 			start.y = x * wolf->module;
// 			while (y + 1 < wolf->max_y && values[y + 1][x] == texture)
// 			{
// 				y++;
// 				lenght++;
// 			}
// 			if (lenght > 0)
// 				save_object(wolf, start, x, y, values);
// 		}
// 		y++;
// 	}
// }

// static void	horizontal_coordinates(t_wolf *wolf, int **values, int y)
// {
// 	t_point start;
// 	int		texture;
// 	int		width;
// 	int		x;

// 	x = 0;
// 	while (x < wolf->max_x)
// 	{
// 		texture = values[y][x];
// 		width = 0;
// 		if (texture != 0)
// 		{
// 			start.x = x * wolf->module;
// 			start.y = y * wolf->module;
// 			while ((x + 1) < wolf->max_x && values[y][x + 1] == texture)
// 			{
// 				x++;
// 				width++;
// 			}
// 			if (width > 1 ||\
// 				(values[y + 1][x] != texture && values[y - 1][x] != texture))
// 				save_object(wolf, start, x, y, values);
// 		}
// 		x++;
// 	}
// }

// void		save_map_coordinates(t_wolf *wolf, int **map_values)
// {
// 	t_object	*objects;
// 	int			x;
// 	int			y;

// 	x = 0;
// 	y = 0;
// 	objects = (t_object*)ft_memalloc(sizeof(t_object));
// 	if (objects == NULL)
// 		wolf_failure_exit(wolf, map_values, MALLOC_ERR);
// 	objects->next = NULL;
// 	while (y < wolf->max_y)
// 	{
// 		horizontal_coordinates(wolf, map_values, y);
// 		y++;
// 	}
// 	while (x < wolf->max_x)
// 	{
// 		vertical_coordinates(wolf, map_values, x);
// 		x++;
// 	}
// }

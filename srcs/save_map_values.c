/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   save_map_values.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: jesmith <jesmith@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/05 13:35:03 by jesmith        #+#    #+#                */
/*   Updated: 2020/03/09 19:31:13 by jesmith       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

static void	set_max_ray(t_wolf *wolf)
{
	int map_width;
	int map_length;

	map_width = wolf->max_x * wolf->module;
	map_length = wolf->max_y * wolf->module;
	wolf->max_ray = sqrt(map_width * map_width + map_length * map_length);
}

static int	validate_map_size(t_wolf *wolf)
{
	if (wolf->max_x < 5 || wolf->max_y < 5)
		return (-1);
	if (wolf->max_x > MAX_SIZE || wolf->max_y > MAX_SIZE)
		return (-1);
	return (0);
}

static int	validate_map_edges(t_wolf *wolf, int **values)
{
	int		x;
	int		y;

	y = 0;
	while (y < wolf->max_y)
	{
		if (y == 0 || y == wolf->max_y)
		{
			x = 0;
			while (x < wolf->max_x && values[y][x] > 0)
				x++;
			if (x != wolf->max_x)
				return (-1);
		}
		while (y < wolf->max_y \
			&& values[y][0] != 0 && values[y][wolf->max_x - 1] != 0)
			y++;
		if (y != wolf->max_y)
			return (-1);
	}
	return (0);
}

static int	*save_values(t_wolf *wolf, char *map_line)
{
	char	**map_array;
	int		*values;
	int		number;
	int		x;

	x = 0;
	map_array = ft_strsplit(map_line, ' ');
	if (map_array == NULL)
		return (NULL);
	values = malloc(sizeof(int) * MAX_SIZE);
	if (values == NULL)
		return (NULL);
	while (map_array[x] != '\0' && ft_isnumber_base(map_array[x], 10) == 1)
	{
		number = ft_atoi_base(map_array[x], 10);
		if (number > MAX_TEXTURES)
			return (NULL);
		values[x] = number;
		x++;
	}
	if (wolf->max_x == 0)
		wolf->max_x = x;
	if (x == wolf->max_x)
		return (values);
	return (NULL);
}

int			**save_map_values(t_wolf *wolf, char *file_name)
{
	int		ret_value;
	char	*map_line;
	int		**values;
	int		fd;

	fd = open(file_name, O_RDONLY);
	values = (int**)malloc(sizeof(int*) * (MAX_SIZE * MAX_SIZE));
	if (fd < 0 || values == NULL)
		wolf_failure_exit(wolf, values, "error: saving file");
	ret_value = get_next_line(fd, &map_line);
	while (ret_value > 0)
	{
		values[wolf->max_y] = save_values(wolf, map_line);
		free(map_line);
		if (values[wolf->max_y] == NULL)
			wolf_failure_exit(wolf, values, "error: input valid map");
		wolf->max_y++;
		ret_value = get_next_line(fd, &map_line);
	}
	if (ret_value < 0)
		wolf_failure_exit(wolf, values, "error: reading file");
	if (validate_map_edges(wolf, values) < 0 || validate_map_size(wolf) < 0)
		wolf_failure_exit(wolf, values, "error: input valid map");
	set_max_ray(wolf);
	return (values);
}

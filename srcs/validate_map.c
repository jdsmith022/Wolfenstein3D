/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   validate_map.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: jesmith <jesmith@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/05 13:35:03 by jesmith        #+#    #+#                */
/*   Updated: 2020/02/05 18:29:34 by jesmith       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

// static void	free_int(int **map_values)
// {
// 	size_t x;
// 	size_t y;

// 	x = 0;
// 	y = 0;
// 	while (map_values[y])
// 	{
// 		while (map_values[y][x])
// 		{
// 			map_values[y][x] = 0;
// 			free(map_values[x]);
// 			x++;
// 		}
// 		free(map_values[y]);
// 		y++;
// 	}
// }

static void	free_str(char **map_array)
{
	size_t x;
	size_t y;

	x = 0;
	y = 0;
	while (map_array[y] != NULL)
	{
		while (map_array[y][x] != '\0')
		{
			map_array[y][x] = '\0';
			free(map_array[x]);
			x++;
		}
		free(map_array[y]);
		y++;
	}
}

static int		*validate_values(t_wolf *wolf, char **map_array, int **map_values)
{
	size_t	index;
	int		width;
	int		*values;
	int		ret_value;

	index = 0;
	width = 0;
	values = (int *)malloc(sizeof(int) * 100);
	if (values == NULL)
	{
		free_str(map_array);
		free(map_values);
		wolf_failure_exit(wolf, "error: reading file");
	}
	while (map_array[index] != '\0')
	{
		ret_value = ft_isnumber_base(map_array[index], 10);
		if (ret_value == -1)
			wolf_failure_exit(wolf, "error: reading file");
		values[index] = ft_atoi_base(map_array[index], 10);
		index++;
		width++;
	}
	if (wolf->max_x == 0)
		wolf->max_x = width;
	// if (wolf->max_x == 10)
	// {
	// 	free_str(map_array);
	// 	free(values);
	// 	free_int(map_values);
	// 	wolf_failure_exit(wolf, "error: reading file");
	// }
	return (values);
}

int		**validate_map(t_wolf *wolf, char *file_name)
{
	int		ret_value;
	char	*map_line;
	char	**map_array;
	int		**map_values;
	size_t	index;
	int		fd;

	index = 0;
	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		wolf_failure_exit(wolf, "error: opening file");
	ret_value = get_next_line(fd, &map_line);
	map_values = (int**)malloc(sizeof(int*) * (100 * 100));
	while (ret_value > 0)
	{
		if (ret_value == -1)
			wolf_failure_exit(wolf, "error: reading file");
		map_array = ft_strsplit(map_line, ' ');
		if (map_array == NULL)
			wolf_failure_exit(wolf, "error: reading file");
		if (map_values == NULL)
		{
			free_str(map_array);
			wolf_failure_exit(wolf, "error: reading file");
		}
		map_values[index] = validate_values(wolf, map_array, map_values);
		index++;
		ret_value = get_next_line(fd, &map_line);
		free(map_line);
		wolf->max_y += 1;
	}
	return (map_values);
}

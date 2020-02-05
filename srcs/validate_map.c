/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   validate_map.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: jesmith <jesmith@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/05 13:35:03 by jesmith        #+#    #+#                */
/*   Updated: 2020/02/05 20:00:20 by mminkjan      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

static void	free_values(int **map_values)
{
	size_t	y;

	y = 0;
	while (map_values[y])
	{
		free(map_values[y]);
		y++;
	}
}

static int	*validate_values(t_wolf *wolf, char **map_array)
{
	size_t	index;
	int		width;
	int		*values;
	int		ret_value;

	index = 0;
	width = 0;
	values = (int *)malloc(sizeof(int) * 100);
	if (values == NULL)
		return (NULL);
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
	if (width != wolf->max_x)
		return (NULL);
	return (values);
}

int			*save_values(t_wolf *wolf, int **map_values,
			char *map_line, size_t index)
{
	char **map_array;

	map_array = ft_strsplit(map_line, ' ');
	if (map_array == NULL)
		wolf_failure_exit(wolf, "error: reading file");
	map_values[index] = validate_values(wolf, map_array);
	if (map_values[index] == NULL)
	{
		free_values(map_values);
		wolf_failure_exit(wolf, "error: reading file");
	}
	return (map_values[index]);
}

int			**validate_map(t_wolf *wolf, char *file_name)
{
	int		ret_value;
	char	*map_line;
	int		**map_values;
	size_t	index;
	int		fd;

	index = 0;
	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		wolf_failure_exit(wolf, "error: opening file");
	ret_value = get_next_line(fd, &map_line);
	map_values = (int**)malloc(sizeof(int*) * (100 * 100));
	if (map_values == NULL)
		wolf_failure_exit(wolf, "error: reading file");
	while (ret_value > 0)
	{
		map_values[index] = save_values(wolf, map_values, map_line, index);
		ret_value = get_next_line(fd, &map_line);
		if (ret_value == -1)
			wolf_failure_exit(wolf, "error: reading file");
		free(map_line);
		wolf->max_y++;
		index++;
	}
	return (map_values);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   validate_map.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: jesmith <jesmith@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/05 13:35:03 by jesmith        #+#    #+#                */
/*   Updated: 2020/02/06 18:42:09 by mminkjan      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

static void	free_values(void **values)
{
	size_t	y;

	y = 0;
	while (values[y] != NULL)
	{
		free(values[y]);
		y++;
	}
	free(values);
}

static int	validate_values(t_wolf *wolf, char **map_array,
			int **values)
{
	int		x;
	int		width;
	int		ret_value;

	x = 0;
	width = 0;
	(*values) = (int *)malloc(sizeof(int) * 100);
	if (values == NULL)
		return (-1);
	while (map_array[x] != '\0')
	{
		ret_value = ft_isnumber_base(map_array[x], 10);
		if (ret_value == -1)
			return (-1);
		*values[x] = ft_atoi_base(map_array[x], 10);
		printf("%d\n", *values[x]);
		x++;
		width++;
	}
	if (wolf->max_x == 0)
		wolf->max_x = width;
	if (width != wolf->max_x)
		return (-1);
	return (0);
}

void		save_values(t_wolf *wolf, char *map_line, int **values)
{
	char	**map_array;
	int		valid;

	map_array = ft_strsplit(map_line, ' ');
	if (map_array == NULL)
		wolf_failure_exit(wolf, "error: reading file");
	valid = validate_values(wolf, map_array, values);
	if (valid == -1)
	{
		free_values((void**)values);
		wolf_failure_exit(wolf, "error: reading file");
	}
	free_values((void**)map_array);
}

int			**validate_map(t_wolf *wolf, char *file_name)
{
	int		ret_value;
	char	*map_line;
	int		**map_values;
	int		fd;

	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		wolf_failure_exit(wolf, "error: opening file");
	ret_value = get_next_line(fd, &map_line);
	map_values = (int**)malloc(sizeof(int*) * (100 * 100));
	if (map_values == NULL)
		wolf_failure_exit(wolf, "error: reading file");
	while (ret_value > 0)
	{
		save_values(wolf, map_line, &map_values[wolf->max_y]);
		ret_value = get_next_line(fd, &map_line);
		if (ret_value == -1)
		{
			free(map_values);
			wolf_failure_exit(wolf, "error: reading file");
		}
		free(map_line);
		wolf->max_y++;
	}
	return (map_values);
}

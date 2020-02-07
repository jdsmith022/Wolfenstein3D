/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   validate_map.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: jesmith <jesmith@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/05 13:35:03 by jesmith        #+#    #+#                */
/*   Updated: 2020/02/07 15:42:15 by mminkjan      ########   odam.nl         */
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
	values = malloc(sizeof(int) * 100);
	while (map_array[x] != '\0' && ft_isnumber_base(map_array[x], 10) == 1)
	{
		number = ft_atoi_base(map_array[x], 10);
		values[x] = number;
		x++;
	}
	if (wolf->max_x == 0)
		wolf->max_x = x;
	if (x == wolf->max_x)
		return (values);
	return (NULL);
}

int			**save_map(t_wolf *wolf, char *file_name)
{
	int		ret_value;
	char	*map_line;
	int		**values;
	int		fd;

	fd = open(file_name, O_RDONLY);
	values = (int**)malloc(sizeof(int*) * (100 * 100));
	if (fd < 0 || values == NULL)
		wolf_failure_exit(wolf, "error: saving file");
	ret_value = get_next_line(fd, &map_line);
	while (ret_value > 0)
	{
		values[wolf->max_y] = save_values(wolf, map_line);
		if (values[wolf->max_y] == NULL)
		{
			free_values((void**)values);
			wolf_failure_exit(wolf, "error: reading file");
		}
		free(map_line);
		wolf->max_y++;
		ret_value = get_next_line(fd, &map_line);
	}
	if (ret_value < 0)
		wolf_failure_exit(wolf, "error: reading file");
	return (values);
}

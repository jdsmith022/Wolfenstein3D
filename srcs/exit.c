/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   exit.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: jesmith <jesmith@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/11 12:57:21 by jesmith        #+#    #+#                */
/*   Updated: 2020/03/11 13:07:10 by jesmith       ########   odam.nl         */
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

int			wolf_failure_exit(t_wolf *wolf, int **map_values,
				char *exit_message)
{
	close(wolf->fd);
	ft_putendl(exit_message);
	if (map_values)
		free_values((void**)map_values);
	if (wolf->item)
		lst_del(&wolf->item, ft_del);
	ft_bzero(wolf, sizeof(t_wolf));
	exit(EXIT_FAILURE);
	return (-1);
}

int			wolf_success_exit(t_wolf *wolf)
{
	close(wolf->fd);
	free_values((void**)wolf->map);
	lst_del(&wolf->item, ft_del);
	ft_bzero(wolf, sizeof(t_wolf));
	exit(EXIT_SUCCESS);
	return (0);
}


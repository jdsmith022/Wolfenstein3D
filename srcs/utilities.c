/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utilities.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jesmith <jesmith@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/05 13:14:43 by jesmith        #+#    #+#                */
/*   Updated: 2020/02/08 14:02:32 by mminkjan      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

// void	lst_del(t_points *point, void (ft_del)(void*, size_t))
// {
// 	t_points *list;

// 	(void)ft_del;
// 	list = *point;
// 	while ((*point)->next_x != 0)
// 	{
// 		(*point) = (*point)->next_x;
// 		if (*point != NULL)
// 			free(*point);
// 		list = (*point);
// 	}
// 	(*point) = (*point)->next_x;
// 	if (*point != NULL)
// 		free(*point);
// 	(*point) = NULL;
// }

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

void	wolf_success_exit(t_wolf *wolf)
{
	close(wolf->fd);
	// lst_del(wolf->points);
	ft_bzero(wolf, sizeof(t_wolf));
	free(wolf);
	exit(EXIT_SUCCESS);
}

void	wolf_failure_exit(t_wolf *wolf, int **map_values, char *exit_message)
{
	close(wolf->fd);
	ft_putendl(exit_message);
	if (map_values)
		free_values((void**)map_values);
	// lst_del(wolf->points);
	ft_bzero(wolf, sizeof(t_wolf));
	exit(EXIT_FAILURE);
}

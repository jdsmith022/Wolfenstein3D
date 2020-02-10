/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utilities.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jesmith <jesmith@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/05 13:14:43 by jesmith        #+#    #+#                */
/*   Updated: 2020/02/10 19:37:02 by mminkjan      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void	lst_del(t_object **object, void (ft_del)(void*, size_t))
{
	t_object *list;

	(void)ft_del;
	list = *object;
	while ((*object)->next != 0)
	{
		(*object) = (*object)->next;
		if (*object != NULL)
			free(*object);
		list = (*object);
	}
	(*object) = (*object)->next;
	if (*object != NULL)
		free(*object);
	(*object) = NULL;
}

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
	lst_del(&wolf->object, ft_del);
	ft_bzero(wolf, sizeof(t_wolf));
	exit(EXIT_SUCCESS);
}

void	wolf_failure_exit(t_wolf *wolf, int **map_values, char *exit_message)
{
	close(wolf->fd);
	ft_putendl(exit_message);
	if (map_values)
		free_values((void**)map_values);
	lst_del(&wolf->object, ft_del);
	ft_bzero(wolf, sizeof(t_wolf));
	exit(EXIT_FAILURE);
}

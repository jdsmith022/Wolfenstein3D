/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utilities.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jesmith <jesmith@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/05 13:14:43 by jesmith        #+#    #+#                */
/*   Updated: 2020/02/22 13:54:22 by jesmith       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void	lst_del(t_item **item, void (ft_del)(void*, size_t))
{
	t_item *list;

	(void)ft_del;
	list = *item;
	while ((*item)->next != 0)
	{
		(*item) = (*item)->next;
		if (*item != NULL)
			free(*item);
		list = (*item);
	}
	(*item) = (*item)->next;
	if (*item != NULL)
		free(*item);
	(*item) = NULL;
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

int		wolf_success_exit(t_wolf *wolf)
{
	close(wolf->fd);
	lst_del(&wolf->item, ft_del);
	ft_bzero(wolf, sizeof(t_wolf));
	exit(EXIT_SUCCESS);
	return (0);
}

int		wolf_failure_exit(t_wolf *wolf, int **map_values, char *exit_message)
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

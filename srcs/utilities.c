/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utilities.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jesmith <jesmith@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/05 13:14:43 by jesmith        #+#    #+#                */
/*   Updated: 2020/02/05 16:09:33 by jesmith       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

// void	lst_del(t_points **point, void (ft_del)(void*, size_t))
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

void	wolf_success_exit(t_wolf *wolf)
{
	close(wolf->fd);
	if (wolf->line)
	{
		// lst_del(&wolf->line, &ft_del);
		ft_bzero(wolf->line, sizeof(t_line));
		free(wolf->line);
	}
	if (wolf != NULL)
	{
		ft_bzero(wolf, sizeof(t_wolf));
		free(wolf);
	}
	exit(EXIT_SUCCESS);
}

void	wolf_failure_exit(t_wolf *wolf, char *exit_message)
{
	ft_putendl_fd(exit_message, wolf->fd);
	close(wolf->fd);
	if (wolf->line)
	{
		// lst_del(&wolf->line, &ft_del);
		ft_bzero(wolf->line, sizeof(t_line));
		free(wolf->line);
	}
	if (wolf != NULL)
	{
		ft_bzero(wolf, sizeof(t_wolf));
		free(wolf);
	}
	exit(EXIT_FAILURE);
}
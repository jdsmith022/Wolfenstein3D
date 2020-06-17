/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utilities.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mminkjan <mminkjan@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/17 14:37:03 by mminkjan      #+#    #+#                 */
/*   Updated: 2020/06/17 14:37:05 by mminkjan      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void		lst_del(t_item **item, void (ft_del)(void*, size_t))
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

void		lst_addback(t_item **item_list, t_item *item)
{
	t_item *temp;

	temp = *item_list;
	if (temp == NULL)
	{
		*item_list = item;
		return ;
	}
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = item;
}

double		clamp_angle(double angle)
{
	if (angle >= 360 * (PI / 180))
		angle -= 360 * (PI / 180);
	else if (angle <= 0)
		angle += 360 * (PI / 180);
	return (angle);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utilities.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mminkjan <mminkjan@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/17 14:37:03 by mminkjan      #+#    #+#                 */
/*   Updated: 2020/06/30 14:45:58 by jesmith       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void		print_help_menu(void)
{
	ft_putendl("A map must meet the following requirements to be valid:");
	ft_putendl("00: A map must be least 5 x 5.");
	ft_putendl("01: The boarder of the map must contain\
		a number between 1 and 4.");
	ft_putendl("02: There must be a space between every number.");
	ft_putendl("03: The length of every row must be the same.");
	ft_putendl("04: The length of every column must be the same.");
	ft_putendl("Example of a valid 6 x 5 map with only exterior walls:");
	ft_putendl("1 1 1 1 1 1");
	ft_putendl("1 0 0 0 0 1");
	ft_putendl("1 0 0 0 0 1");
	ft_putendl("1 0 0 0 0 1");
	ft_putendl("1 1 1 1 1 1");
	exit(0);
}

void		put_pixel(t_wolf *wolf, int color, int x, int y)
{
	size_t	index;

	if (x >= 0 && x < WIDTH && y < HEIGHT && y >= 0)
	{
		index = (y * wolf->graphics.size_line) + \
			(x * wolf->graphics.bits_ppixel / 8);
		wolf->graphics.addr_str[index] = color;
		index++;
		wolf->graphics.addr_str[index] = color >> 8;
		index++;
		wolf->graphics.addr_str[index] = color >> 16;
	}
}

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

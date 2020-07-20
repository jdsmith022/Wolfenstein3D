/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_menu.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: JessicaSmith <JessicaSmith@student.coda      +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/20 19:01:30 by JessicaSmit   #+#    #+#                 */
/*   Updated: 2020/07/20 19:15:24 by JessicaSmit   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void		print_settings_menu(void)
{
	ft_putendl("The following keys are used to move around the map:");
	ft_putendl("Walk forward: w");
	ft_putendl("Walk backwards: s");
	ft_putendl("Walk left: a");
	ft_putendl("Walk right: d\n");
	ft_putendl("To pan left or right, click and hold mouse then drag");
	ft_putendl("mouse left or right.\n");
	ft_putendl("Special features:");
	ft_putendl("To show colors instead of wall textures: alt\n");
	ft_putendl("Create a different textured maps:");
	ft_putendl("Use different textures series to create different world.");
	ft_putendl("Choose one number between 1 and 4 to create a map.");
	ft_putendl("Each number is a complete series of matching textures.");
	ft_putendl("For example: 1 is one set, 2 is another set, etc.\n");
	exit(0);
}

void		print_help_menu(void)
{
	ft_putendl("A map must meet the following requirements to be valid:");
	ft_putendl("00: A map must be least 5 x 5.");
	ft_putendl("01: The map's boarder must contain a number between 1 and 4.");
	ft_putendl("02: There must be a space between every number.");
	ft_putendl("03: The length of every row must be the same.");
	ft_putendl("04: The length of every column must be the same.");
	ft_putendl("Example of a valid 6 x 5 map with only exterior walls:");
	ft_putendl("1 1 1 1 1 1");
	ft_putendl("1 0 0 0 0 1");
	ft_putendl("1 0 0 0 0 1");
	ft_putendl("1 0 0 0 0 1");
	ft_putendl("1 1 1 1 1 1\n");
	exit(0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   load_color.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: Malou <Malou@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/16 17:40:51 by Malou         #+#    #+#                 */
/*   Updated: 2020/06/16 17:40:55 by Malou         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void	load_color(t_wolf *wolf)
{
	int *color;

	color = wolf->graphics.color;
	color[0] = 0xD35400;
	color[1] = 0x800000;
	color[2] = 0xFF5733;
	color[3] = 0xC70039;
	color[4] = 0x581845;
	color[5] = 0xE74C3C;
	color[6] = 0x2980B9;
	color[7] = 0xF1C40F;
	color[8] = 0x16A085;
	color[9] = 0xA6ACAF;
	color[10] = 0x34495E;
	color[11] = 0x707B7C;
	color[12] = 0xCD5C5C;
	color[13] = 0xF08080;
	color[14] = 0xE9967A;
	color[15] = 0xFFA07A;
}

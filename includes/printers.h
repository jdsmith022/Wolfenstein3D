/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   printers.h                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: jesmith <jesmith@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/10 12:34:56 by jesmith        #+#    #+#                */
/*   Updated: 2020/03/11 11:32:22 by jesmith       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTERS_H
# define PRINTERS_H

# include "./wolf3d.h"

typedef struct s_wolf	t_wolf;
typedef struct s_point	t_point;
typedef struct s_item	t_item;

typedef	struct		s_line //delete later
{
	double			delta_x;
	double			delta_y;
	double			delta_x_abs;
	double			delta_y_abs;
	double			error_x;
	double			error_y;
	double			delta_alt;
}					t_line;

typedef struct		s_vis
{
	void			*win_ptr2;
	void			*mlx_ptr2;
	void			*image_ptr2;
	char			*addr_str2;
}					t_vis;

void				print_map(int **map_values, t_wolf *wolf);
void				print_map_coordinates(t_item *item);
int					flat_draw(t_wolf *wolf);
void				draw_line(t_wolf *wolf, t_point start, \
						t_point end, int color);
void				draw_intercept(t_wolf *wolf, t_point r_start, int x, int y);
void				draw_ray(t_wolf *wolf, t_point r_start, \
						t_point r_end, int color);
void				init_mlx2(t_wolf *wolf);

#endif

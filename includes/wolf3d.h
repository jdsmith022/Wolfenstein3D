/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   wolf3d.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: mminkjan <mminkjan@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/03 20:12:46 by mminkjan       #+#    #+#                */
/*   Updated: 2020/02/19 15:40:32 by jesmith       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

# include "../libft/libft.h"
# include "../minilibx_macos/mlx.h"
# include <math.h>
# include <fcntl.h>

# include <stdio.h> //remove later

# define USAGE_ERR "usage: input valid wolf3d map"
# define MALLOC_ERR "error: malloc"

# define WIDTH	1200
# define HEIGHT 600

# define MAX_SIZE 100
# define MAX_TEXTURES 7

# define ESC 53

typedef struct		s_form
{
	int				a_ray;
	int				b_ray;
	int				c_ray;
	int				a_obj;
	int				b_obj;
	int				c_obj;
	double			delta_x;
	double			delta_y;
}					t_form;

typedef struct 		s_height
{
	double			y_start;
	double			y_end;
	int				texture;
}					t_height;

typedef	struct		s_point {
	double			x;
	double			y;
	int				texture;
	double			obj_dist;
}					t_point;

typedef	struct		s_item {
	t_point			start;
	t_point			end;
	int				texture;
	struct s_item	*next;
}					t_item;

typedef struct		s_i {
	int				x;
	int				y;
}					t_i;

typedef struct		s_wolf {
	void			*win_ptr;
	void			*mlx_ptr;
	void			*image_ptr;
	int				bits_ppixel;
	int				size_line;
	char			*addr_str;
	int				**map;
	int				max_x;
	int				max_y;
	int				fd;
	int				module;
	int				height;
	int				wall_height;
	int				obj_height;
	double			max_ray;
	t_point			pos;
	t_point			dir;
	t_point			plane;
	t_item			*item;
	t_form			form;
}					t_wolf;

t_wolf				init_wolf(void);
void				init_mlx(t_wolf *wolf);

int					wolf_success_exit(t_wolf *wolf);
int					wolf_failure_exit(t_wolf *wolf,\
					int **map_values, char *exit_message);
void				lst_del(t_item **item, void (ft_del)(void*, size_t));

int					**save_map_values(t_wolf *wolf, char *file_name);
void				save_map_coordinates(t_wolf *wolf, int **map_values);

int					wolf_render2(t_wolf *wolf);
t_point				line_intersection(t_point r_start, t_point r_end,\
					t_point o_start, t_point o_end);

void				draw_column2(t_wolf *wolf, t_height wall, int x);

int					key_events(int key, t_wolf *wolf);

void				print_map(int **map_values, t_wolf *wolf); //delete later
void				print_map_coordinates(t_item *item); //delete later

#endif

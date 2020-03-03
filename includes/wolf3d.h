/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   wolf3d.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: mminkjan <mminkjan@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/03 20:12:46 by mminkjan       #+#    #+#                */
/*   Updated: 2020/03/03 12:37:12 by mminkjan      ########   odam.nl         */
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

# define PI 3.14159265359
# define FOV 60 * (PI / 180)

# define SPEED 10

# define ESC 53
# define W 13
# define S 1
# define A 0
# define D 2

# define MOUSE_PRESS 1

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

typedef struct		s_project
{
	double			y_start;
	double			y_end;
	int				texture;
}					t_project;

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

typedef	struct		s_event {
	int				key_press;
	int				mouse_press;
	int				hold_angle;
	int				hold_x;
	int				hold_y; // needed?
}					t_event;

typedef struct		s_i {
	int				x;
	int				y;
}					t_i;

typedef struct		s_player
{
	double			x;
	double			y;
}					t_player;

typedef	struct			s_line //delete later
{
	double				delta_x;
	double				delta_y;
	double				delta_x_abs;
	double				delta_y_abs;
	double				error_x;
	double				error_y;
	double				delta_alt;
}						t_line;

typedef struct		s_wolf {
	void			*win_ptr2; //remove from here
	void			*mlx_ptr2;
	void			*image_ptr2;
	char			*addr_str2; // to here
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
	int				bound;
	double			max_ray;
	double			dir_angle;
	double			dist_to_plane;
	double			ray_angle;
	t_point			intersect;
	t_point			pos;
	t_event			event;
	t_item			*item;
	t_form			form;
}					t_wolf;

t_wolf				init_wolf(void);
void				init_mlx(t_wolf *wolf);

int					wolf_success_exit(t_wolf *wolf);
int					wolf_failure_exit(t_wolf *wolf,\
					int **map_values, char *exit_message);
void				lst_del(t_item **item, void (ft_del)(void*, size_t));
void				lst_addback(t_item **item_list, t_item *item);

int					**save_map_values(t_wolf *wolf, char *file_name);
void				save_map_coordinates(t_wolf *wolf);

int					wolf_engine(t_wolf *wolf);
t_point				find_intersect(t_wolf *wolf, t_item ray,\
					int prev_height, double angle);

void				draw_column(t_wolf *wolf, t_project wall, int x);

void				mlx_mouse(t_wolf *wolf);
void				mlx_key(t_wolf *wolf);

void				print_map(int **map_values, t_wolf *wolf); //delete later
void				print_map_coordinates(t_item *item); //delete later
int					flat_draw(t_wolf *wolf); // remove later
void				draw_line(t_wolf *wolf, t_point start, t_point end, int color); //remove
void				draw_intercept(t_wolf *wolf, t_point r_start, int x, int y);
void				draw_ray(t_wolf *wolf, t_point r_start, t_point r_end, int color);
void				init_mlx2(t_wolf *wolf); //remove


#endif

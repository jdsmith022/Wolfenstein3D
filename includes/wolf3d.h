/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   wolf3d.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: mminkjan <mminkjan@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/03 20:12:46 by mminkjan       #+#    #+#                */
/*   Updated: 2020/03/16 15:29:27 by mminkjan         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

# include "../libft/libft.h"
# include "./printers.h"
# include "../minilibx_macos/mlx.h"
# include <math.h>
# include <fcntl.h>

# include <stdio.h> //remove later

# define USAGE_ERR "usage: input valid wolf3d map"
# define MALLOC_ERR "error: malloc"

# define WIDTH	1200
# define HEIGHT 600

# define MAX_SIZE 100
# define MAX_TEXTURES 4
# define MAX_WIDTH WIDTH * wolf->wall_width
# define MAX_HEIGHT HEIGHT * wolf->wall_width

# define PI 3.14159265359
# define FOV 60 * (PI / 180)

# define SPEED 20

# define ESC 53
# define ALT 261
# define W 13
# define S 1
# define A 0
# define D 2

# define MOUSE_PRESS 1

typedef	struct		s_texture
{
	void			*image_ptr;
	char			*addr_str;
	int				bits_ppixel;
	int				size_line;
}					t_texture;

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
	int				height;
	double			offset;
	int				x;
	int				delta;
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
	int				colors;
	int				hold_x;
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

typedef struct		s_graphics {
	void			*win_ptr;
	void			*mlx_ptr;
	void			*image_ptr;
	int				bits_ppixel;
	int				size_line;
	char			*addr_str;
	int				color[16];
	t_texture		*wall[16];
	size_t			texdex;
	size_t			index;
	t_texture		sprite;
	t_texture		floor;
	t_texture		ceiling;
}					t_graphics;

typedef struct		s_wolf {
	int				**map;
	int				max_x;
	int				max_y;
	int				fd;
	int				wall_width;
	double			wall_height;
	int				obj_height;
	double			max_ray;
	double			dir_angle;
	double			dist_to_plane;
	double			ray_angle;
	t_graphics		graphics;
	t_vis			vis;
	t_point			intersect;
	t_point			pos;
	t_event			event;
	t_item			*item;
	t_form			form;
}					t_wolf;

t_wolf				init_wolf(void);
void				init_mlx(t_wolf *wolf);

void 				load_color(t_wolf *wolf);
void				load_addr_str(t_wolf *wolf);
void				load_image_ptr(t_wolf *wolf, int width, int height);

int					**save_map_values(t_wolf *wolf, char *file_name);
void				save_map_coordinates(t_wolf *wolf);

int					wolf_engine(t_wolf *wolf);
t_point				find_intersect(t_wolf *wolf, t_item ray, double angle);

void				draw_column(t_wolf *wolf, t_project wall, \
						int x);

void				mlx_mouse(t_wolf *wolf);
void				mlx_key(t_wolf *wolf);
void				key_player_movement(t_wolf *wolf, int key, \
						t_point *pos, double *move_angle);

int					wolf_success_exit(t_wolf *wolf);
int					wolf_failure_exit(t_wolf *wolf,\
						int **map_values, char *exit_message);

void				lst_del(t_item **item, void (ft_del)(void*, size_t));
void				lst_addback(t_item **item_list, t_item *item);
double				clamp_angle(double angle);

#endif

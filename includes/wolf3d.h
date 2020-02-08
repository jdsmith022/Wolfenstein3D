/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   wolf3d.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: mminkjan <mminkjan@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/03 20:12:46 by mminkjan       #+#    #+#                */
/*   Updated: 2020/02/08 15:05:04 by mminkjan      ########   odam.nl         */
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

# define MAX_SIZE 100
# define MAX_TEXTURES 7

typedef struct	s_intersection
{
	int			a_ray;
	int			b_ray;
	int			c_ray;
	int			a_wall;
	int			b_wall;
	int			c_wall;
}				t_intersection;

typedef	struct	s_point {
	int			x;
	int			y;
}				t_point;

typedef	struct	s_object {
	t_point		start;
	t_point		end;
	int			texture;
	struct s_object		*next;
}				t_object;

typedef struct	s_wolf {
	void		*mlx_ptr;
	void		*win_ptr;
	void		*img_ptr;
	char		*addr_str;
	int			bpp;
	int			size_line;
	int			**map;
	double		win_height;
	double		win_width;
	int			max_x;
	int			max_y;
	int			fd;
	int			module;
	t_point		point;
	t_object	*object;
}				t_wolf;

void			mlx_setup(t_wolf *wolf);
t_wolf			init_wolf(void);

void			wolf_success_exit(t_wolf *wolf);
void			wolf_failure_exit(t_wolf *wolf, int **map_values, char *exit_message);
// void			lst_del(t_points **points, void (ft_del)(void*, size_t));

int				**save_map(t_wolf *wolf, char *file_name);

void	print_map(int **map_values, t_wolf *wolf); //delete later

#endif

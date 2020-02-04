/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   wolf3d.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: mminkjan <mminkjan@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/03 20:12:46 by mminkjan       #+#    #+#                */
/*   Updated: 2020/02/04 11:17:23 by mminkjan      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

# include "../libft/libft.h"
# include "../minilibx_macos/mlx.h"
# include <math.h>
# include <fcntl.h>

# define USAGE_ERR "usage: inpult valid wolf3d map"
# define MALLOC_ERR "error: malloc"

typedef	struct	s_point {
	int			x;
	int			y;
}				t_point;

typedef	struct	s_line {
	t_point		start;
	t_point		end;
	int			texture;
}				t_line;

typedef struct	s_wolf3d {
	void		*mlx_ptr;
	void		*win_ptr;
	void		*img_ptr;
	char		*addr_str;
	int			bpp;
	int			size_line;
	int			**map;
	t_point		point;
	t_line		line;
}				t_wolf;

void			init_mlx(t_wolf *wolf);
void			init_wolf(t_wolf *wolf);
void			wolf_exit(char *error);

#endif

# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: mminkjan <mminkjan@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2020/02/03 20:54:24 by mminkjan       #+#    #+#                 #
#    Updated: 2020/03/04 19:12:59 by mminkjan      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = wolf3d

FLAGS = -Wall -Wextra -Werror -o

MLX = minilibx_macos/

MLXFLAGS = -lmlx -framework OpenGL -framework AppKit

LIBFT = libft/

SRCS = ./srcs/


SRCS_FILES = main init_wolf utilities init_mlx \
			save_map_values save_map_coordinates wolf_engine find_intersect \
			mouse_events draw_column key_events \
			2d_vis mlx_init2

PRINT = ./printers/ #remove
PT_FILES =  #remove 

CFILES = $(SRCS_FILES:%=$(SRCS)%.c)

OFILES = $(CFILES:%.c=%.o)

HEADERS = includes/wolf3d.h

ADD_FILES = Makefile author ./maps

all: $(NAME)

%.o: %.c
	@gcc -g -c $(FLAGS) $@ $<

$(NAME) : $(OFILES)
	@make re -C $(LIBFT)
	@gcc -g -I $(MLX) -L $(MLX) $(MLXFLAGS) -I $(LIBFT) -L $(LIBFT) -lft \
	$(CFILES) $(FLAGS) $(NAME)
	@rm -f $(OFILES)

clean :
	@make clean -C $(LIBFT)
	@rm -f $(OFILES)
	@rm -f *#
	@rm -f *~
	@rm -f *.DS_Store
	@rm -Rf .vscode

fclean : clean
	@make fclean -C $(LIBFT)
	@rm -f $(NAME)

re : fclean all

add : fclean
	@git add $(MLX) $(LIBFT) $(CFILES) $(HEADERS) $(ADD_FILES)
	@git status

push :
ifdef MSG
	@git commit -m "$(MSG)"
	@git push
endif

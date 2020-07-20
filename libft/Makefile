# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: jesmith <jesmith@studentodam.nl>             +#+                      #
#                                                    +#+                       #
#    Created: 2019/01/13 12:32:27 by jesmith       #+#    #+#                  #
#    Updated: 2020/07/20 20:04:09 by JessicaSmit   ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME := libft.a
CFLAGS := -Wall -Werror -Wextra
HEAD := libft.h
SRCS := atoi_base bzero del free_strarray isnumber_base itoa_base \
		memalloc memset putchar putendl putstr strcmp strsplit has_prefix \
		isdigit_base iswhitespace lstnew strchr strdel strdup strjoin strlen \
		strsub memcpy memdel stralloc toupper rounder

CFILES := $(SRCS:%=./ft_%.c) get_next_line.c

SRCO := $(CFILES:%.c=%.o)

NORM := norminette $(HEAD) $(CFILES) | grep -e "Warning" -e "Error" -B 1

all: $(NAME)

norm:
	@$(NORM)

add:
	@git add $(CFILES) $(HEAD) Makefile README.md
	@git status

push:
ifdef MSG
	@git commit -m "$(MSG)"
	@git push
	@make norm
else
	@echo "WARNING NO MESSAGE"
endif

print:
	@echo "$(SRCO)"

$(NAME):
	@gcc $(CFLAGS) -c $(CFILES)   
	@ar rc	$(NAME) $(SRCO) $(HEAD)
	@ranlib	$(NAME)

clean:
	@/bin/rm -f $(SRCO)
	@/bin/rm -f *#
	@/bin/rm -f *~
	@/bin/rm -f *.DS_Store
	@/bin/rm -Rf .vscode

fclean:
	@/bin/rm -f $(SRCO) libft.a

re: fclean all

/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   libft.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: jesmith <jesmith@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/13 12:48:31 by jesmith       #+#    #+#                 */
/*   Updated: 2020/07/20 20:04:04 by JessicaSmit   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdlib.h>
# include <stddef.h>
# include <unistd.h>
# include <string.h>
# include "get_next_line.h"

void				ft_bzero(void *s, size_t n);
void				*ft_memset(void *str, int c, size_t n);
void				*ft_memcpy(void *dst, const void *str, size_t n);
void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);

char				*ft_strdup(const char *s1);
size_t				ft_strlen(const char *str);
int					ft_strcmp(const char *s1, const char *s2);
char				*ft_strchr(const char *s, int c);
char				*ft_strrev(char *s);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				**ft_strsplit(char const *s, char c);
char				**ft_strplit(char const *s, char c);
void				ft_strdel(const char *s);
char				*ft_stralloc(const char *s);
void				ft_free_strarray(char **str);

void				ft_del(void *data, size_t size);

int					ft_atoi_base(const char *str, int base);
char				*ft_itoa_base(int n, int base);
int					ft_intlen(int n);
int					ft_rounder(double dbl);

int					ft_isdigit_base(char c, int base);
int					ft_iswhitespace(int c);
int					ft_isprint(int c);
int					ft_toupper(int c);
int					ft_isnumber_base(char *nb, int base);
int					ft_has_prefix(const char *str, int base);

void				ft_putchar(char c);
void				ft_putendl(char const *s);
void				ft_putstr(char const *s);

int					get_next_line(const int fd, char **line);

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

t_list				*ft_lstnew(void const *content, size_t content_size);

#endif

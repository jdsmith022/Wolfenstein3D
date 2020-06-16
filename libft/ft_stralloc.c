/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_stralloc.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: jesmith <marvin@codam.nl>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/05 14:36:06 by jesmith       #+#    #+#                 */
/*   Updated: 2020/06/16 18:31:59 by Malou         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_stralloc(const char *s)
{
	return ((char *)malloc(sizeof(char) * ft_strlen(s) + 1));
}

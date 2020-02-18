/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   line_intersection.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: mminkjan <mminkjan@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/03 16:31:11 by mminkjan       #+#    #+#                */
/*   Updated: 2020/02/18 10:41:28 by jesmith       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

t_point	line_intersection(t_point r_start, t_point r_end,
			t_point o_start, t_point o_end)
{
	int				denominator;
	t_point			intersection;
	t_form			st;

	intersection.x = 0;
	intersection.y = 0;
	// printf("start: %f, %f end:  %f, %f\n", o_start.x, o_start.y, o_end.x, o_end.y);
	st.a_ray = r_end.y - r_start.y;
	st.b_ray = r_start.x - r_end.x;
	st.c_ray = st.a_ray * r_start.x + st.b_ray * r_start.y;
	st.a_obj = o_end.y - o_start.y;
	st.b_obj = o_start.x - o_end.x;
	st.c_obj = st.a_obj * o_start.x + st.b_obj * o_start.y;
	denominator = st.a_ray * st.b_obj - st.a_obj * st.b_ray;
	if (denominator == 0)
		return (intersection);
	intersection.x = (st.b_obj * st.c_ray - st.b_ray * st.c_obj) / denominator;
	intersection.y = (st.a_ray * st.c_obj - st.a_obj * st.c_ray) / denominator;
	return (intersection);
}

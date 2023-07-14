/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 11:36:32 by revieira          #+#    #+#             */
/*   Updated: 2023/07/14 18:27:51 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VEC3_H
# define VEC3_H

typedef struct s_point
{
	double	x;
	double	y;
	double	z;
}	t_point;

typedef t_point	t_color;
typedef t_point	t_vec3;

//vec3 operators
t_vec3	add(t_vec3 a, t_vec3 b);
t_vec3	minus(t_vec3 a, t_vec3 b);
t_vec3	multiply(t_vec3 a, t_vec3 b);
t_vec3	division(t_vec3 a, t_vec3 b);
t_vec3	s_multiply(t_vec3 a, double n);
t_vec3	s_division(t_vec3 a, double n);
double	length_square(t_vec3 a);
double	magnitude(t_vec3 a);
t_vec3	normalize(t_vec3 a);
double	dot(t_vec3 m1, t_vec3 m2);

//color
int		get_color(t_color color);
t_color	gradient_color(double axis, t_color a, t_color b);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 11:51:18 by revieira          #+#    #+#             */
/*   Updated: 2023/07/11 16:37:04 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECTS_H
# define OBJECTS_H

# include "vec3.h"

typedef struct s_sphere
{
	t_point	center;
	double	radius;
	t_color	color;
}	t_sphere;

typedef struct s_cylinder
{
	t_point	center;
	t_vec3	vector;
	double	radius;
	double	height;
	t_color	color;
}	t_cylinder;

typedef struct s_plane
{
	t_point	center;
	t_vec3	vector;
	t_color	color;
}	t_plane;

t_sphere	*sp(t_point center, double radius, t_color color);

#endif
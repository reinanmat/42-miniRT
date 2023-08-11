/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 11:51:18 by revieira          #+#    #+#             */
/*   Updated: 2023/08/11 15:35:10 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECTS_H
# define OBJECTS_H

# include "vec3.h"
# include "matrices.h"

typedef struct s_sphere
{
	t_point		center;
	double		radius;
	t_color		color;
	t_matrix	transform;
}	t_sphere;

typedef struct s_cylinder
{
	t_point		center;
	t_vec3		vector;
	double		diameter;
	double		height;
	t_color		color;
	t_matrix	transform;
}	t_cylinder;

typedef struct s_plane
{
	t_point		center;
	t_vec3		vector;
	t_color		color;
	t_matrix	transform;
}	t_plane;

t_sphere	*sphere(char **config);
t_cylinder	*cylinder(char **config);
t_plane		*plane(char **config);

#endif

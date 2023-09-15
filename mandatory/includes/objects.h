/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 11:51:18 by revieira          #+#    #+#             */
/*   Updated: 2023/09/15 19:11:06 by fnacarel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECTS_H
# define OBJECTS_H

# include "vec3.h"
# include "matrices.h"

typedef struct s_material
{
	double	ambient;
	double	diffuse;
	double	specular;
	double	shininess;
	t_color	color;
}	t_material;

typedef struct s_sphere
{
	t_point		center;
	double		radius;
	t_matrix	transform;
	t_matrix	inv_transform;
	t_material	material;
}	t_sphere;

typedef struct s_cylinder
{
	t_point		center;
	t_vec3		vector;
	double		diameter;
	double		height;
	double		min;
	double		max;
	t_matrix	transform;
	t_matrix	inv_transform;
	t_material	material;
}	t_cylinder;

typedef struct s_plane
{
	t_point		center;
	t_vec3		vector;
	t_matrix	transform;
	t_matrix	inv_transform;
	t_material	material;
}	t_plane;

t_material	default_material(void);
t_sphere	*sphere(char **config);
t_cylinder	*cylinder(char **config);
t_plane		*plane(char **config);

#endif

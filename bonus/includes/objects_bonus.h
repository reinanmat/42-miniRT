/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 11:51:18 by revieira          #+#    #+#             */
/*   Updated: 2023/09/13 13:18:52 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECTS_BONUS_H
# define OBJECTS_BONUS_H

# include "vec3_bonus.h"
# include "matrices_bonus.h"

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
	t_material	material;
}	t_cylinder;

typedef struct s_plane
{
	t_point		center;
	t_vec3		vector;
	t_matrix	transform;
	t_material	material;
}	t_plane;

typedef struct s_cone
{
	t_point		center;
	t_vec3		vector;
	double		diameter;
	double		height;
	double		min;
	double		max;
	t_matrix	transform;
	t_material	material;
}	t_cone;

t_material	default_material(void);
t_sphere	*sphere(char **config);
t_cylinder	*cylinder(char **config);
t_plane		*plane(char **config);
t_cone		*cone(char **config);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 11:51:18 by revieira          #+#    #+#             */
/*   Updated: 2023/09/25 15:57:22 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECTS_BONUS_H
# define OBJECTS_BONUS_H

# define COLOR 0
# define PATTERN 1
# define TEXTURE 2

# define STRIPE_PATTERN 0
# define GRADIENT_PATTERN 1
# define RING_PATTERN 2
# define CHECKER_PATTERN 3

# include "vec3_bonus.h"
# include "matrices_bonus.h"

typedef struct s_pattern
{
	int			type;
	t_color		a;
	t_color		b;
	t_matrix	transform;
	t_matrix	inv_transform;
}	t_pattern;

typedef struct s_texture
{
	int		height;
	int		width;
	t_color	**map_texture;
}	t_texture;

typedef struct s_material
{
	double		ambient;
	double		diffuse;
	double		specular;
	double		shininess;
	int			type_material;
	t_color		color;
	t_pattern	pattern;
	t_texture	texture;
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

typedef struct s_cone
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
}	t_cone;

t_sphere	*sphere(char **config);
t_cylinder	*cylinder(char **config);
t_plane		*plane(char **config);
t_cone		*cone(char **config);

//material
t_material	set_material(char *config);
t_texture	set_texture(char *config);
t_color		stripe_pattern(t_pattern pattern, t_point point);
t_color		ring_pattern(t_pattern pattern, t_point point);
t_color		checkers_pattern(t_pattern pattern, t_point point);
t_color		gradient_pattern(t_pattern pattern, t_point point);
t_color		sphere_map(t_texture texture, t_point point);
t_color		plane_map(t_texture texture, t_point point);
t_color		cylinder_and_cone_map(t_texture texture, t_point point);

#endif

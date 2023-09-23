/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_objects_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnacarel <fnacarel@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 16:53:05 by fnacarel          #+#    #+#             */
/*   Updated: 2023/09/23 16:54:55 by fnacarel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../includes/minirt_bonus.h"

t_matrix	transform_cy_pl_co(t_vec3 a, t_point center, t_matrix scale)
{
	t_matrix	translation_by_rot;
	t_matrix	transformed_cy;
	t_matrix	orientation_to_matr;
	t_matrix	translation_matr;

	translation_matr = translation_matrix(center);
	orientation_to_matr = get_orientation(a);
	translation_by_rot = multiply_matrix(translation_matr, orientation_to_matr);
	transformed_cy = multiply_matrix(translation_by_rot, scale);
	return (transformed_cy);
}

t_cone	*cone(char **config)
{
	t_matrix	scale;
	double		radius;
	t_cone		*co;

	co = malloc(sizeof(t_cone));
	assign_t_point(&co->center, config[1]);
	assign_t_point(&co->vector, config[2]);
	co->diameter = ft_atof(config[3]);
	co->min = -ft_atof(config[4]);
	co->max = ft_atof(config[5]);
	radius = co->diameter / 2;
	scale = scaling_matrix(vec3(radius, radius, radius));
	co->material = set_material(config[6]);
	co->transform = transform_cy_pl_co(co->vector, co->center, scale);
	co->inv_transform = inverse(co->transform);
	return (co);
}

t_sphere	*sphere(char **config)
{
	t_sphere	*sp;
	t_vec3		scale;
	t_point		translation;

	sp = malloc(sizeof(t_sphere));
	sp->center = point(0, 0, 0);
	sp->radius = ft_atof(config[2]) / 2;
	assign_t_point(&translation, config[1]);
	scale = vec3(sp->radius, sp->radius, sp->radius);
	sp->material = set_material(config[3]);
	sp->transform = transform_object(translation, scale);
	sp->inv_transform = inverse(sp->transform);
	return (sp);
}

t_cylinder	*cylinder(char **config)
{
	t_cylinder	*cy;
	double		radius;
	t_matrix	cy_scale;

	cy = malloc(sizeof(t_cylinder));
	cy->height = ft_atof(config[4]);
	cy->diameter = ft_atof(config[3]);
	cy->min = -(cy->height / 2);
	cy->max = cy->height / 2;
	assign_t_point(&cy->center, config[1]);
	assign_t_point(&cy->vector, config[2]);
	radius = cy->diameter / 2;
	cy_scale = scaling_matrix(vec3(radius, radius, radius));
	cy->material = set_material(config[5]);
	cy->transform = transform_cy_pl_co(cy->vector, cy->center, cy_scale);
	cy->inv_transform = inverse(cy->transform);
	return (cy);
}

t_plane	*plane(char **config)
{
	t_plane		*pl;
	t_matrix	identity_matr;

	identity_matr = identity_matrix();
	pl = malloc(sizeof(t_plane));
	pl->material = set_material(config[3]);
	assign_t_point(&pl->center, config[1]);
	assign_t_point(&pl->vector, config[2]);
	pl->transform = transform_cy_pl_co(pl->vector, pl->center, identity_matr);
	pl->inv_transform = inverse(pl->transform);
	return (pl);
}

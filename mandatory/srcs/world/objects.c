/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 16:14:46 by revieira          #+#    #+#             */
/*   Updated: 2023/09/23 17:10:04 by fnacarel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../includes/minirt.h"

t_sphere	*sphere(char **config)
{
	t_sphere	*sp;
	t_vec3		scale;
	t_point		translation;

	sp = malloc(sizeof(t_sphere));
	sp->center = point(0, 0, 0);
	sp->radius = ft_atof(config[2]) / 2;
	sp->material = default_material();
	assign_t_color(&sp->material.color, config[3]);
	assign_t_point(&translation, config[1]);
	scale = vec3(sp->radius, sp->radius, sp->radius);
	sp->transform = transform_object(translation, scale);
	sp->inv_transform = inverse(sp->transform);
	return (sp);
}

t_matrix	transform_cy_pl(t_vec3 a, t_point center, t_matrix scale)
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

t_cylinder	*cylinder(char **config)
{
	t_cylinder	*cy;
	t_vec3		cy_scale_vec;
	t_matrix	cy_scale_matrix;

	cy = malloc(sizeof(t_cylinder));
	cy->height = ft_atof(config[4]);
	cy->diameter = ft_atof(config[3]);
	cy->min = -(cy->height / 2);
	cy->max = cy->height / 2;
	cy->transform = identity_matrix();
	cy->material = default_material();
	assign_t_point(&cy->center, config[1]);
	assign_t_point(&cy->vector, config[2]);
	assign_t_color(&cy->material.color, config[5]);
	cy_scale_vec = vec3(cy->diameter / 2, cy->diameter / 2, cy->diameter / 2);
	cy_scale_matrix = scaling_matrix(cy_scale_vec);
	cy->transform = transform_cy_pl(cy->vector, cy->center, cy_scale_matrix);
	cy->inv_transform = inverse(cy->transform);
	return (cy);
}

t_plane	*plane(char **config)
{
	t_plane	*pl;

	pl = malloc(sizeof(t_plane));
	pl->transform = identity_matrix();
	pl->material = default_material();
	assign_t_point(&pl->center, config[1]);
	assign_t_point(&pl->vector, config[2]);
	assign_t_color(&pl->material.color, config[3]);
	pl->transform = transform_cy_pl(pl->vector, pl->center, identity_matrix());
	pl->inv_transform = inverse(pl->transform);
	return (pl);
}

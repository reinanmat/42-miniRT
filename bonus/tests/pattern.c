/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pattern.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 14:39:50 by revieira          #+#    #+#             */
/*   Updated: 2023/09/13 20:08:51 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/minirt_bonus.h"

void	test_pattern(void)
{
	t_point		p;
	t_color		black;
	t_color		white;
	t_color		result;
	t_pattern	pattern;

	white = color(1, 1, 1);
	black = color(0, 0, 0);
	pattern.type = 1;
	pattern = set_pattern(white, black, identity_matrix());

	printf("\n======================STRIPE_PATTERN_Y=======================\n");
	
	p = point(0, 0, 0);
	result = stripe_at(pattern, p);
	print("point: ", &p, NULL, NULL);
	print("Expected: ", &white, " Result: ", &result);
	p = point(0, 1, 0);
	result = stripe_at(pattern, p);
	print("point: ", &p, NULL, NULL);
	print("Expected: ", &white, " Result: ", &result);
	p = point(0, 2, 0);
	result = stripe_at(pattern, p);
	print("point: ", &p, NULL, NULL);
	print("Expected: ", &white, " Result: ", &result);

	printf("\n======================STRIPE_PATTERN_Z=======================\n");
	
	p = point(0, 0, 0);
	result = stripe_at(pattern, p);
	print("point: ", &p, NULL, NULL);
	print("Expected: ", &white, " Result: ", &result);
	p = point(0, 0, 1);
	result = stripe_at(pattern, p);
	print("point: ", &p, NULL, NULL);
	print("Expected: ", &white, " Result: ", &result);
	p = point(0, 0, 2);
	result = stripe_at(pattern, p);
	print("point: ", &p, NULL, NULL);
	print("Expected: ", &white, " Result: ", &result);

	printf("\n======================STRIPE_PATTERN_X=======================\n");
	
	p = point(0, 0, 0);
	result = stripe_at(pattern, p);
	print("point: ", &p, NULL, NULL);
	print("Expected: ", &white, " Result: ", &result);
	p = point(0.9, 0, 0);
	result = stripe_at(pattern, p);
	print("point: ", &p, NULL, NULL);
	print("Expected: ", &white, " Result: ", &result);
	p = point(1, 0, 0);
	result = stripe_at(pattern, p);
	print("point: ", &p, NULL, NULL);
	print("Expected: ", &black, " Result: ", &result);
	p = point(-0.1, 0, 0);
	result = stripe_at(pattern, p);
	print("point: ", &p, NULL, NULL);
	print("Expected: ", &black, " Result: ", &result);
	p = point(-1, 0, 0);
	result = stripe_at(pattern, p);
	print("point: ", &p, NULL, NULL);
	print("Expected: ", &black, " Result: ", &result);
	p = point(-1.1, 0, 0);
	result = stripe_at(pattern, p);
	print("point: ", &p, NULL, NULL);
	print("Expected: ", &white, " Result: ", &result);
	
	printf("\n==================LIGHTING_WITH_A_PATTERN====================\n");

	t_comps		comps;
	t_light		light;
	t_amb_light	amb_light;
	t_hittable	*obj;
	t_sphere	*sp;

	comps.eyev = vec3(0, 0, -1);
	comps.normalv = vec3(0, 0, -1);
	light = point_light(point(0, 0, -10), 1);
	amb_light.color = color(1, 1, 1);
	amb_light.light_ratio = 0;
	sp = unit_sphere();
	sp->transform = identity_matrix();
	sp->inv_transform = identity_matrix();
	obj = NULL;
	hittable_add("sp", sp, &obj);
	obj->sp->material.ambient = 1;
	obj->sp->material.diffuse = 0;
	obj->sp->material.specular = 0;
	obj->sp->material.has_pattern = 1;
	obj->sp->material.pattern = set_pattern(white, black, identity_matrix());
	comps.object = obj;

	comps.over_point = point(0.9, 0, 0);
	result = lighting(light, comps, amb_light, 0);
	print("Expected: ", &white, " Result: ", &result);

	comps.over_point = point(1.1, 0, 0);
	result = lighting(light, comps, amb_light, 0);
	print("Expected: ", &black, " Result: ", &result);

	printf("\n===================TRANSFORMING_PATTERNS=====================\n");
	
	obj->sp->transform = scaling_matrix(point(2, 2, 2));
	obj->sp->inv_transform = inverse(scaling_matrix(point(2, 2, 2)));
	pattern = set_pattern(white, black, identity_matrix());
	pattern.type = 1;
	result = stripe_at_obj(pattern, get_inv_transform(obj), point(1.5, 0, 0));
	print("Expected: ", &white, " Result: ", &result);

	obj->sp->transform = identity_matrix();
	obj->sp->inv_transform = identity_matrix();
	pattern = set_pattern(white, black, scaling_matrix(point(2, 2, 2)));
	pattern.type = 1;
	result = stripe_at_obj(pattern, get_inv_transform(obj), point(1.5, 0, 0));
	print("Expected: ", &white, " Result: ", &result);

	obj->sp->transform = scaling_matrix(point(2, 2, 2));
	obj->sp->inv_transform = inverse(scaling_matrix(point(2, 2, 2)));
	pattern = set_pattern(white, black, translation_matrix(point(0.5, 0, 0)));
	pattern.type = 1;
	result = stripe_at_obj(pattern, get_inv_transform(obj), point(2.5, 0, 0));
	print("Expected: ", &white, " Result: ", &result);
	
}

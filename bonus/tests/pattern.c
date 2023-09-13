/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pattern.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 14:39:50 by revieira          #+#    #+#             */
/*   Updated: 2023/09/13 14:40:22 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/minirt_bonus.h"
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pattern.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 18:44:48 by revieira          #+#    #+#             */
/*   Updated: 2023/09/12 19:42:05 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/minirt_bonus.h"

void	test_patern(void)
{
	t_point		p;
	t_color		black;
	t_color		white;
	t_color		result;
	t_pattern	pattern;

	black = color(0, 0, 0);
	white = color(1, 1, 1);
	pattern = stripe_pattern(white, black);

	printf("\n======================STRIPE_PATTERN_Y=======================\n");
	
	p = point(0, 0, 0);
	result = stripe_at(pattern, p);
	print("point: ", &p, NULL, NULL);
	print("Expected: ", &white, "Result: ", &result);
	p = point(0, 1, 0);
	result = stripe_at(pattern, p);
	print("point: ", &p, NULL, NULL);
	print("Expected: ", &white, "Result: ", &result);
	p = point(0, 2, 0);
	result = stripe_at(pattern, p);
	print("point: ", &p, NULL, NULL);
	print("Expected: ", &white, "Result: ", &result);

	printf("\n======================STRIPE_PATTERN_Z=======================\n");
	
	p = point(0, 0, 0);
	result = stripe_at(pattern, p);
	print("point: ", &p, NULL, NULL);
	print("Expected: ", &white, "Result: ", &result);
	p = point(0, 0, 1);
	result = stripe_at(pattern, p);
	print("point: ", &p, NULL, NULL);
	print("Expected: ", &white, "Result: ", &result);
	p = point(0, 0, 2);
	result = stripe_at(pattern, p);
	print("point: ", &p, NULL, NULL);
	print("Expected: ", &white, "Result: ", &result);

	printf("\n======================STRIPE_PATTERN_X=======================\n");
	
	p = point(0, 0, 0);
	result = stripe_at(pattern, p);
	print("point: ", &p, NULL, NULL);
	print("Expected: ", &white, "Result: ", &result);
	p = point(0.9, 0, 0);
	result = stripe_at(pattern, p);
	print("point: ", &p, NULL, NULL);
	print("Expected: ", &white, "Result: ", &result);
	p = point(1, 0, 0);
	result = stripe_at(pattern, p);
	print("point: ", &p, NULL, NULL);
	print("Expected: ", &black, "Result: ", &result);
	p = point(-0.1, 0, 0);
	result = stripe_at(pattern, p);
	print("point: ", &p, NULL, NULL);
	print("Expected: ", &black, "Result: ", &result);
	p = point(-1, 0, 0);
	result = stripe_at(pattern, p);
	print("point: ", &p, NULL, NULL);
	print("Expected: ", &black, "Result: ", &result);
	p = point(-1.1, 0, 0);
	result = stripe_at(pattern, p);
	print("point: ", &p, NULL, NULL);
	print("Expected: ", &white, "Result: ", &result);
	
	printf("\n==================LIGHTING_WITH_A_PATTERN====================\n");

	t_comps		comps;
	t_light		light;
	t_amb_light	amb_light;
	t_hittable	*obj;

	comps.eyev = vec3(0, 0, -1);
	comps.normalv = vec3(0, 0, -1);
	light = point_light(point(0, 0, -10), 1);
	amb_light.color = color(1, 1, 1);
	amb_light.light_ratio = 1;
	obj->type = 1;
	obj->sp = unit_sphere();
	obj->sp->material.ambient = 1;
	obj->sp->material.diffuse = 0;
	obj->sp->material.specular = 0;
	comps.object = obj;

	comps.over_point = point(0.9, 0, 0);
	result = lighting(light, comps, amb_light, 0);
	print("Expected: ", &white, "Result: ", &result);

	comps.over_point = point(1.1, 0, 0);
	result = lighting(light, comps, amb_light, 0);
	print("Expected: ", &black, "Result: ", &result);
}

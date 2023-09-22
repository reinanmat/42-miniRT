/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   material_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 16:55:37 by revieira          #+#    #+#             */
/*   Updated: 2023/09/21 19:54:29 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../includes/minirt_bonus.h"

static int	set_type_of_material(char *config)
{
	if (is_valid_rgb_set(config))
		return (COLOR);
	else if (is_valid_pattern(config))
		return (PATTERN);
	else
		return (TEXTURE);
}

static t_pattern	set_pattern(char *config)
{
	t_pattern	p;

	if (ft_strcmp("GRADIENT", config) == 0)
		p.type = GRADIENT_PATTERN;
	else if (ft_strcmp("STRIPE", config) == 0)
		p.type = STRIPE_PATTERN;
	else if (ft_strcmp("RING", config) == 0)
		p.type = RING_PATTERN;
	else
		p.type = CHECKER_PATTERN;
	p.a = color(1, 1, 1);
	p.b = color(0, 0, 0);
	p.transform = scaling_matrix(point(0.5, 0.5, 0.5));
	p.inv_transform = inverse(p.transform);
	return (p);
}

t_material	set_material(char *config)
{
	t_material	m;

	m.ambient = 0.1;
	m.diffuse = 0.9;
	m.specular = 0.9;
	m.shininess = 200.0;
	m.type_material = set_type_of_material(config);
	if (m.type_material == COLOR)
		assign_t_color(&m.color, config);
	else if (m.type_material == PATTERN)
		m.pattern = set_pattern(config);
	else
		m.texture = set_texture(config);
	return (m);
}

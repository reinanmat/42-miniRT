/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   material.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 16:55:37 by revieira          #+#    #+#             */
/*   Updated: 2023/09/20 16:18:23 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../includes/minirt_bonus.h"

int	set_type_of_material(char **config)
{
	int	config_len;

	config_len = ft_count_matrix((void **)config);
	if (config_len != 1)
		return (PATTERN);
	else if (set_contain_only_numbers(config[0]) == 1)
		return (COLOR);
	else
		return (TEXTURE);
}

t_pattern	set_pattern(char **config)
{
	t_pattern	p;

	if (ft_strcmp("GRADIENT", config[0]) == 0)
		p.type = GRADIENT_PATTERN;
	else if (ft_strcmp("STRIPE", config[0]) == 0)
		p.type = STRIPE_PATTERN;
	else if (ft_strcmp("RING", config[0]) == 0)
		p.type = RING_PATTERN;
	else
		p.type = CHECKER_PATTERN;
	assign_t_color(&p.a, config[1]);
	assign_t_color(&p.b, config[2]);
	p.transform = scaling_matrix(point(0.5, 0.5, 0.5));
	p.inv_transform = inverse(p.transform);
	return (p);
}

t_material	set_material(char **config)
{
	t_material	m;

	m.ambient = 0.1;
	m.diffuse = 0.9;
	m.specular = 0.9;
	m.shininess = 200.0;
	m.type_material = set_type_of_material(config);
	if (m.type_material == COLOR)
		assign_t_color(&m.color, config[0]);
	else if (m.type_material == PATTERN)
		m.pattern = set_pattern(config);
	else
		m.texture = set_texture(config[0]);
	return (m);
}

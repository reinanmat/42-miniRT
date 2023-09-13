/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   material.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 16:55:37 by revieira          #+#    #+#             */
/*   Updated: 2023/09/13 15:42:21 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../includes/minirt_bonus.h"

t_material	default_material(void)
{
	t_material	m;

	m.ambient = 0.1;
	m.diffuse = 0.9;
	m.specular = 0.9;
	m.shininess = 200.0;
	m.has_pattern = 0;
	m.pattern = stripe_pattern(color(1, 1, 1), color(0, 0, 0));
	return (m);
}

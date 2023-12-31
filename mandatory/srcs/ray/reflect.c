/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reflect.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 17:03:51 by revieira          #+#    #+#             */
/*   Updated: 2023/08/21 18:54:33 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../includes/minirt.h"

t_vec3	reflect(t_vec3 in, t_vec3 normal)
{
	double	dot_product;

	dot_product = dot(in, normal);
	return (sub(in, s_multiply(normal, 2 * dot_product)));
}

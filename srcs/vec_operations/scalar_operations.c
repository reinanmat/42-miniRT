/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scalar_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 11:06:54 by revieira          #+#    #+#             */
/*   Updated: 2023/07/07 11:22:46 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

t_vec3	s_multiply(t_vec3 a, double n)
{
	return ((t_vec3){a.x * n, a.y * n, a.z * n});
}

t_vec3	s_division(t_vec3 a, double n)
{
	return (s_multiply(a, 1 / n));
}

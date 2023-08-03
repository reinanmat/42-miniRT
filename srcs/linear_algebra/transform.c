/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnacarel <fnacarel@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 19:05:47 by fnacarel          #+#    #+#             */
/*   Updated: 2023/08/03 13:36:56 by fnacarel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../includes/minirt.h"

void	apply_transformation(t_point *pos, t_matrix transformation)
{
	t_point		new_pos;
	t_matrix	applied;
	t_matrix	m_point;

	m_point = point_to_matrix(*pos);
	applied = multiply_matrix(m_point, transformation);
	new_pos = point(m_point.matr[0][0], m_point.matr[1][0], m_point.matr[2][0]);
	*pos = new_pos;
}

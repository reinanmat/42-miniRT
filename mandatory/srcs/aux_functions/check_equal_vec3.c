/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_equal_vec3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnacarel <fnacarel@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 18:50:17 by fnacarel          #+#    #+#             */
/*   Updated: 2023/09/11 18:52:17 by fnacarel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../includes/minirt.h"

int	check_equal_vec3(t_vec3 a, t_vec3 b)
{
	int	ax_eq_bx;
	int	ay_eq_by;
	int	az_eq_bz;

	ax_eq_bx = double_equals(a.x, b.x);
	ay_eq_by = double_equals(a.y, b.y);
	az_eq_bz = double_equals(a.z, b.z);
	if (ax_eq_bx && ay_eq_by && az_eq_bz)
		return (1);
	return (0);
}

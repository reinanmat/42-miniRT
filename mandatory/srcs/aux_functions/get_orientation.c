/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_orientation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnacarel <fnacarel@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 17:17:16 by fnacarel          #+#    #+#             */
/*   Updated: 2023/09/19 17:46:33 by fnacarel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../includes/minirt.h"

static int	rotate_normalized_x(t_vec3 a)
{
	t_vec3	positive_x;
	t_vec3	negative_x;

	positive_x = vec3(1, 0, 0);
	negative_x = vec3(-1, 0, 0);
	if (check_equal_vec3(a, positive_x) || check_equal_vec3(a, negative_x))
		return (1);
	return (0);
}

static int	rotate_normalized_z(t_vec3 a)
{
	t_vec3	positive_z;
	t_vec3	negative_z;

	positive_z = vec3(0, 0, 1);
	negative_z = vec3(0, 0, -1);
	if (check_equal_vec3(a, positive_z) || check_equal_vec3(a, negative_z))
		return (1);
	return (0);
}

static t_matrix	rotate_x_y(t_vec3 a)
{
	t_matrix	rotation;
	t_matrix	rotation_x;
	t_matrix	rotation_y;

	rotation_x = rotate_x_matrix(M_PI / 2);
	rotation_y = rotate_y_matrix(atan(a.x / a.z));
	rotation = multiply_matrix(rotation_y, rotation_x);
	return (rotation);
}

static t_matrix	rotate_z_x(t_vec3 a)
{
	t_matrix	rotation;
	t_matrix	rotation_x;
	t_matrix	rotation_z;

	rotation_x = rotate_x_matrix(atan(a.z / a.y));
	rotation_z = rotate_z_matrix(atan(-a.x / a.y));
	rotation = multiply_matrix(rotation_z, rotation_x);
	return (rotation);
}

t_matrix	get_orientation(t_vec3 a)
{
	if (check_equal_vec3(a, vec3(0, 1, 0)))
		return (identity_matrix());
	else if (check_equal_vec3(a, vec3(0, -1, 0)))
		return (rotate_x_matrix(M_PI));
	else if (rotate_normalized_x(a))
		return (rotate_z_matrix(M_PI / 2));
	else if (rotate_normalized_z(a))
		return (rotate_x_matrix(M_PI / 2));
	if (double_equals(a.y, 0))
		return (rotate_x_y(a));
	else
		return (rotate_z_x(a));
}

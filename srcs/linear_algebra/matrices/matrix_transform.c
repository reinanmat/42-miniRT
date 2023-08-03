/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_transform.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnacarel <fnacarel@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 19:12:22 by fnacarel          #+#    #+#             */
/*   Updated: 2023/08/02 19:13:32 by fnacarel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../../includes/minirt.h"

t_matrix	translation_matrix(t_point x)
{
	t_matrix	a;

	a = identity_matrix();
	a.matr[0][3] = x.x;
	a.matr[1][3] = x.y;
	a.matr[2][3] = x.z;
	return (a);
}

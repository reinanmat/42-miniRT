/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_equals.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnacarel <fnacarel@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 18:10:54 by fnacarel          #+#    #+#             */
/*   Updated: 2023/09/08 18:13:03 by fnacarel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../includes/minirt.h"

int	double_equals(double a, double b)
{
	if (fabs(a - b) < EPSILON)
		return (1);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign_t_point.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnacarel <fnacarel@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 19:14:13 by fnacarel          #+#    #+#             */
/*   Updated: 2023/07/24 19:16:41 by fnacarel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../includes/minirt.h"

void	assign_t_point(t_point *coordinate, char *param)
{
	char	**splitted_param;

	splitted_param = ft_split(param, ',');
	coordinate->x = ft_atof(splitted_param[0]);
	coordinate->y = ft_atof(splitted_param[1]);
	coordinate->z = ft_atof(splitted_param[2]);
	ft_free_matrix((void **)splitted_param);
}

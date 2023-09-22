/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign_value_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnacarel <fnacarel@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 19:14:13 by fnacarel          #+#    #+#             */
/*   Updated: 2023/09/12 17:52:53 by fnacarel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../includes/minirt_bonus.h"

void	assign_t_point(t_point *coordinate, char *param)
{
	char	**splitted_param;

	splitted_param = ft_split(param, ',');
	coordinate->x = ft_atof(splitted_param[0]);
	coordinate->y = ft_atof(splitted_param[1]);
	coordinate->z = ft_atof(splitted_param[2]);
	ft_free_matrix((void **)splitted_param);
}

void	assign_t_color(t_color *color, char *param)
{
	t_color	tmp_color;

	assign_t_point(&tmp_color, param);
	*color = normalize_color(tmp_color);
}

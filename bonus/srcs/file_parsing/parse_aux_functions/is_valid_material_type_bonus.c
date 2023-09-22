/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_material_type_bonus.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnacarel <fnacarel@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 18:48:45 by fnacarel          #+#    #+#             */
/*   Updated: 2023/09/21 18:50:35 by fnacarel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../../includes/minirt_bonus.h"

int is_valid_material_type(char *str)
{
	int	valid_rgb;
	int	valid_texture;
	int	valid_pattern;

	valid_rgb = is_valid_rgb_set(str);
	valid_texture = is_valid_texture(str);
	valid_pattern = is_valid_pattern(str);
	return (valid_rgb || valid_texture || valid_pattern);
}


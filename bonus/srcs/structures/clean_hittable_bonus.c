/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_hittable_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 16:37:54 by revieira          #+#    #+#             */
/*   Updated: 2023/09/27 16:17:58 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../includes/minirt_bonus.h"

static void	clean_texture(t_texture t)
{
	int	 i;

	i = 0;
	while (i < t.height)
	{
		ft_free(t.map_texture[i]);
		i++;
	}
	ft_free(t.map_texture);
}

static void	clean_object(t_hittable *object)
{
	t_material	material;

	material = get_material(object);
	if (material.type_material == TEXTURE)
		clean_texture(material.texture);
	if (object->type == 1)
		ft_free(object->sp);
	else if (object->type == 2)
		ft_free(object->cy);
	else if (object->type == 3)
		ft_free(object->pl);
	else
		ft_free(object->co);
}

void	clean_hittable(t_hittable **hittable_lst)
{
	t_hittable	*next;
	t_hittable	*curr;

	if (!hittable_lst || !*hittable_lst)
		return ;
	curr = *hittable_lst;
	next = *hittable_lst;
	while (next)
	{
		curr = next;
		next = next->next;
		clean_object(curr);
		ft_free(curr);
	}
}

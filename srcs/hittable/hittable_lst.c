/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hittable_lst.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 13:33:59 by revieira          #+#    #+#             */
/*   Updated: 2023/07/11 16:55:01 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

static void	add_node(t_hittable *new_node, t_hittable **hittable_lst)
{
	t_hittable	*aux;

	if (hittable_lst && *hittable_lst)
	{
		aux = *hittable_lst;
		while (aux->next)
			aux = aux->next;
		aux->next = new_node;
	}
	else
		*hittable_lst = new_node;
}

void	add_sphere(t_sphere *sp, t_hittable **hittable_lst)
{
	t_hittable	*new_node;

	new_node = ft_calloc(sizeof(t_hittable), 1);
	new_node->type = 1;
	new_node->sp = sp;
	new_node->next = NULL;
	add_node(new_node, hittable_lst);
}

void	add_cylinder(t_cylinder *cy, t_hittable **hittable_lst)
{
	t_hittable	*new_node;

	new_node = ft_calloc(sizeof(t_hittable), 1);
	new_node->type = 2;
	new_node->cy = cy;
	new_node->next = NULL;
	add_node(new_node, hittable_lst);
}

void	add_plane(t_plane *pl, t_hittable **hittable_lst)
{
	t_hittable	*new_node;

	new_node = ft_calloc(sizeof(t_hittable), 1);
	new_node->type = 3;
	new_node->pl = pl;
	new_node->next = NULL;
	add_node(new_node, hittable_lst);
}

void	hittable_add(int type, void *object, t_hittable **hittable_lst)
{
	if (type == 1)
		add_sphere((t_sphere *)object, hittable_lst);
	else if (type == 2)
		add_cylinder((t_cylinder *)object, hittable_lst);
	else if (type == 3)
		add_plane((t_plane *)object, hittable_lst);
}

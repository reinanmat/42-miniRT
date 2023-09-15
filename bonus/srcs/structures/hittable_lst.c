/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hittable_lst.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 13:33:59 by revieira          #+#    #+#             */
/*   Updated: 2023/09/15 16:28:59 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../includes/minirt_bonus.h"

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
	new_node->cy = NULL;
	new_node->pl = NULL;
	new_node->co = NULL;
	new_node->next = NULL;
	add_node(new_node, hittable_lst);
}

void	add_cylinder(t_cylinder *cy, t_hittable **hittable_lst)
{
	t_hittable	*new_node;

	new_node = ft_calloc(sizeof(t_hittable), 1);
	new_node->type = 2;
	new_node->cy = cy;
	new_node->sp = NULL;
	new_node->pl = NULL;
	new_node->co = NULL;
	new_node->next = NULL;
	add_node(new_node, hittable_lst);
}

void	add_plane(t_plane *pl, t_hittable **hittable_lst)
{
	t_hittable	*new_node;

	new_node = ft_calloc(sizeof(t_hittable), 1);
	new_node->type = 3;
	new_node->pl = pl;
	new_node->sp = NULL;
	new_node->cy = NULL;
	new_node->co = NULL;
	new_node->next = NULL;
	add_node(new_node, hittable_lst);
}

void	add_cone(t_cone *co, t_hittable **hittable_lst)
{
	t_hittable	*new_node;

	new_node = ft_calloc(sizeof(t_hittable), 1);
	new_node->type = 4;
	new_node->co = co;
	new_node->sp = NULL;
	new_node->cy = NULL;
	new_node->pl = NULL;
	new_node->next = NULL;
	add_node(new_node, hittable_lst);
}

void	hittable_add(char *type, void *object, t_hittable **header)
{
	if (ft_strcmp(type, "sp") == 0)
		add_sphere((t_sphere *)object, header);
	else if (ft_strcmp(type, "cy") == 0)
		add_cylinder((t_cylinder *)object, header);
	else if (ft_strcmp(type, "pl") == 0)
		add_plane((t_plane *)object, header);
	else
		add_cone((t_cone *)object, header);
}

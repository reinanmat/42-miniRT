/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection_lst_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnacarel <fnacarel@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 16:48:18 by fnacarel          #+#    #+#             */
/*   Updated: 2023/09/12 18:01:15 by fnacarel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../includes/minirt_bonus.h"

t_intersections	*last_intersect(t_intersections *lst)
{
	if (!lst)
		return (0);
	while (lst -> next != 0)
		lst = lst -> next;
	return (lst);
}

void	intersect_add_back(t_intersections **lst, t_intersections *new)
{
	t_intersections	*last_node;

	if (lst && new)
	{
		if (*lst == NULL)
			*lst = new;
		else
		{
			last_node = last_intersect(*lst);
			last_node->next = new;
		}
	}
}

void	clear_intersect(t_intersections **lst)
{
	t_intersections	*store_previous_node;

	store_previous_node = *lst;
	while (*lst != 0 && store_previous_node != 0)
	{
		store_previous_node = *lst;
		*lst = (*lst)->next;
		ft_free(store_previous_node);
	}
	lst = NULL;
}

t_intersections	*new_intersect(double t, t_hittable *object)
{
	t_intersections	*new_node;

	new_node = (malloc(sizeof(t_node)));
	if (!new_node)
		return (0);
	new_node->t = t;
	new_node->object = object;
	new_node->next = NULL;
	return (new_node);
}

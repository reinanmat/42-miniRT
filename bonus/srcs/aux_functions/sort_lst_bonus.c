/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_lst_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnacarel <fnacarel@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 16:52:49 by fnacarel          #+#    #+#             */
/*   Updated: 2023/09/12 17:53:17 by fnacarel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../includes/minirt_bonus.h"

static void	swap_intersect_nodes(t_intersections *a, t_intersections *b)
{
	t_intersections	tmp;

	tmp = *a;
	a->t = b->t;
	a->object = b->object;
	b->t = tmp.t;
	b->object = tmp.object;
}

void	sort_lst(t_intersections **lst)
{
	int				swapped;
	t_intersections	*curr;

	if (!lst || !(*lst))
		return ;
	while (1)
	{
		swapped = 0;
		curr = *lst;
		while (curr->next)
		{
			if (curr->t > curr->next->t)
			{
				swap_intersect_nodes(curr, curr->next);
				swapped = 1;
			}
			curr = curr->next;
		}
		if (!swapped)
			break ;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_hittable.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 16:37:54 by revieira          #+#    #+#             */
/*   Updated: 2023/09/13 14:20:45 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../includes/minirt_bonus.h"

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
		ft_free(curr->sp);
		ft_free(curr->cy);
		ft_free(curr->pl);
		ft_free(curr->co);
		ft_free(curr);
	}
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnacarel <fnacarel@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 22:42:28 by fnacarel          #+#    #+#             */
/*   Updated: 2023/03/07 14:57:22 by fnacarel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_lstclear(t_node **lst, void (*del)(void *))
{
	t_node	*store_previous_node;

	store_previous_node = *lst;
	if (del)
	{
		while (*lst != 0 && store_previous_node != 0)
		{
			store_previous_node = *lst;
			*lst = (*lst)->next;
			del(store_previous_node->key);
			del(store_previous_node->value);
			free(store_previous_node);
		}
		lst = NULL;
	}
}

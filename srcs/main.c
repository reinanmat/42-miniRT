/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 11:11:03 by revieira          #+#    #+#             */
/*   Updated: 2023/08/07 19:32:24 by fnacarel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

typedef struct s_intersections
{
	double	t;
	void	*object;
	void	*next;
}	t_intersections;

typedef struct s_intersection_point
{
	int		hit_times;
	double	hit[2];
	void	*object;
}	t_intersection_point;

t_intersections	*lstlast(t_intersections *lst)
{
	if (!lst)
		return (0);
	while (lst -> next != 0)
		lst = lst -> next;
	return (lst);
}

void	lstclear(t_intersections **lst)
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

t_intersections	*lstnew(double t, void *object)
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

void	lstadd_back(t_intersections **lst, t_intersections *new)
{
	t_intersections	*last_node;

	if (lst && new)
	{
		if (*lst == NULL)
			*lst = new;
		else
		{
			last_node = lstlast(*lst);
			last_node -> next = new;
		}
	}
}


t_data	init_data(char *filename)
{
	t_data	data;

	data.world = init_world(filename);
	mlx_create_window(&data.mlx);
	mlx_create_img(&data.mlx);
	mlx_hooks(&data);
	return (data);
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 2)
		exit(1);
	else if (received_invalid_param(argv[1]))
		exit(1);
	data = init_data(argv[1]);
	render(data);
	mlx_loop(data.mlx.mlx_ptr);
}

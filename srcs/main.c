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

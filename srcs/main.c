/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 11:11:03 by revieira          #+#    #+#             */
/*   Updated: 2023/07/24 19:05:45 by fnacarel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

t_mlx	init_mlx(void)
{
	t_mlx	mlx;

	mlx_create_window(&mlx);
	mlx_create_img(&mlx);
	mlx_hooks(&mlx);
	return (mlx);
}

/* t_light	init_light(t_color color) */
/* { */
/* 	t_light	light; */

/* 	light.position = (t_point){0, 0, 0}; */
/* 	light.color = color; */
/* 	light.brightness = 0.5; */
/* 	return (light); */
/* } */

/* t_hittable	*add_objects(void) */
/* { */
/* 	t_hittable	*objects; */
/* 	t_sphere	*sp1; */
/* 	t_sphere	*floor; */

/* 	objects = NULL; */
/* 	sp1 = sp((t_point){0, 0, -1}, 0.75, (t_color){0, 0, 1}); */
/* 	floor = sp((t_point){0, -1000.5, 0}, 999.5, (t_color){0, 0, 1}); */
/* 	hittable_add(1, sp1, &objects); */
/* 	hittable_add(1, floor, &objects); */
/* 	return (objects); */
/* } */

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 2)
		exit(1);
	else if (received_invalid_param(argv[1]))
		exit(1);
	init_world(argv[1]);
	exit(0);
	data.mlx = init_mlx();
	render(data);
	mlx_loop(data.mlx.mlx_ptr);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 11:11:03 by revieira          #+#    #+#             */
/*   Updated: 2023/06/20 12:26:18 by revieira         ###   ########.fr       */
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

int	main(void)
{
	t_mlx	mlx;

	mlx = init_mlx();
	render(mlx);
	mlx_loop(mlx.mlx_ptr);
}

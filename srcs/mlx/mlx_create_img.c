/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_create_img.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 16:04:19 by revieira          #+#    #+#             */
/*   Updated: 2023/06/26 20:19:31 by fnacarel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

void	mlx_create_img(t_mlx *mlx)
{
	int		height;

	height = (WIDTH / 16) * 9;
	mlx->img.mlx_img = mlx_new_image(mlx->mlx_ptr, WIDTH, height);
	mlx->img.addr = mlx_get_data_addr(mlx->img.mlx_img, &mlx->img.bpp,
			&mlx->img.line_len, &mlx->img.endian);
}

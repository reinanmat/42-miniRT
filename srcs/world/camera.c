/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnacarel <fnacarel@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 20:29:27 by fnacarel          #+#    #+#             */
/*   Updated: 2023/08/23 22:36:16 by fnacarel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../includes/minirt.h"

void	set_pixel_size(t_cam *camera)
{
	double	aspect;
	double	half_view;

	half_view = tan(camera->fov / 2);
	aspect = (double) WIDTH / HEIGHT;
	if (aspect >= 1)
	{
		camera->viewport_width = half_view;
		camera->viewport_height = half_view / aspect;
	}
	else
	{
		camera->viewport_width = half_view * aspect;
		camera->viewport_height = half_view;
	}
	camera->pixel_size = (camera->viewport_width * 2) / WIDTH;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   world_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 11:58:43 by revieira          #+#    #+#             */
/*   Updated: 2023/09/28 19:02:29 by fnacarel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WORLD_BONUS_H
# define WORLD_BONUS_H

# include "vec3_bonus.h"
# include "hittable_bonus.h"

typedef struct s_cam
{
	double		fov;
	double		viewport_height;
	double		viewport_width;
	double		pixel_size;
	t_point		coordinate;
	t_vec3		orientation_vec;
	t_matrix	transform;
	t_matrix	inv_transform;
}	t_cam;

typedef struct s_light
{
	double	brightness;
	t_point	coordinate;
	t_color	color;
}	t_light;

typedef struct s_amb_light
{
	t_color	color;
	double	light_ratio;
}	t_amb_light;

typedef struct s_world
{
	int			amount_of_lights;
	t_cam		cam;
	t_light		*light;
	t_amb_light	ambient_light;
	t_hittable	*objects;
}	t_world;

t_world	init_world(char *filename);
t_cam	init_camera(char **lines);
void	set_pixel_size(t_cam *camera);

#endif

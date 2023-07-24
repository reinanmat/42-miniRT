/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   world.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 11:58:43 by revieira          #+#    #+#             */
/*   Updated: 2023/07/24 19:12:50 by fnacarel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WORLD_H
# define WORLD_H

# include "vec3.h"
# include "hittable.h"

typedef struct s_cam
{
	double	fov;
	double	viewport_height;
	double	viewport_width;
	double	focal_length;
	t_point	coordinate;
	t_vec3	horizontal;
	t_vec3	vertical;
	t_point	lower_left_corner;
}	t_cam;

typedef struct s_light
{
	t_color	color;
	t_point	coordinate;
	double	brightness;
}	t_light;

typedef struct s_world
{
	t_cam		cam;
	t_light		light;
	t_light		ambient_light;
	t_hittable	*objects;
}	t_world;

t_world	init_world(char *filename);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 11:44:27 by revieira          #+#    #+#             */
/*   Updated: 2023/08/23 21:19:57 by fnacarel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_H
# define RAY_H

# include "vec3.h"
# include "world.h"

typedef struct s_ray
{
	t_point	origin;
	t_vec3	direction;
}	t_ray;

//ray
t_vec3	position(t_ray ray, double t);
t_ray	ray(t_point origin, t_vec3 direction);
t_ray	ray_for_pixel(t_cam cam, int x, int y);

#endif

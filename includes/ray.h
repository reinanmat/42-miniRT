/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 11:44:27 by revieira          #+#    #+#             */
/*   Updated: 2023/08/09 18:22:23 by revieira         ###   ########.fr       */
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
t_ray	ray(t_point origin, t_vec3 direction);
t_ray	get_ray(double u, double v, t_cam cam);
t_color	ray_color(t_ray ray, t_world world);
t_vec3	position(t_ray ray, double t);

#endif

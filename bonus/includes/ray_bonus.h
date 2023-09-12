/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_bonus.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 11:44:27 by revieira          #+#    #+#             */
/*   Updated: 2023/09/12 17:43:07 by fnacarel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_BONUS_H
# define RAY_BONUS_H

# include "vec3_bonus.h"
# include "world_bonus.h"

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

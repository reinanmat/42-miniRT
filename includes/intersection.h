/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 18:05:51 by revieira          #+#    #+#             */
/*   Updated: 2023/08/09 18:16:05 by revieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERSECTION_H
# define INTERSECTION_H

# include "ray.h"
# include "hittable.h"

typedef struct s_intersections
{
	double					t;
	t_hittable				*object;
	struct s_intersections	*next;
}	t_intersections;

typedef struct s_intersection_point
{
	int		hit_times;
	double	hit[2];
	void	*object;
}	t_intersection_point;

t_intersections			*hit(t_intersections *intersections);
void					intersection_calculate(t_ray ray, t_hittable *objects, t_intersections **intersect);
t_intersection_point	intersect_sphere(t_ray ray, t_sphere *sphere);

//intersection list utils
void					sort_lst(t_intersections **lst);
void					intersect_add_back(t_intersections **lst, t_intersections *new);
t_intersections			*last_intersect(t_intersections *lst);
void					clear_intersect(t_intersections **lst);
t_intersections			*new_intersect(double t, t_hittable *object);

#endif

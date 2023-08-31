/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 18:05:51 by revieira          #+#    #+#             */
/*   Updated: 2023/08/30 19:26:54 by fnacarel         ###   ########.fr       */
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

typedef struct s_inter_point
{
	int		hit_times;
	double	hit[2];
	void	*object;
}	t_inter_point;

typedef struct	s_comps
{
	int			inside;
	double		t;
	t_hittable	*object;
	t_point		point;
	t_point		over_point;
	t_vec3		eyev;
	t_vec3		normalv;
}	t_comps;

typedef struct s_bhask
{
	double	a;
	double	b;
	double	c;
	double	discriminant;
	double	s1;
	double	s2;
}	t_bhask;

t_intersections	*intersection_calculate(t_ray ray, t_hittable *objects);
t_inter_point	intersect_sphere(t_ray ray, t_sphere *sphere);
t_intersections	*hit(t_intersections *intersections);

//intersection list utils
void			sort_lst(t_intersections **lst);
void			intersect_add_back(t_intersections **lst, t_intersections *new);
t_intersections	*last_intersect(t_intersections *lst);
void			clear_intersect(t_intersections **lst);
t_intersections	*new_intersect(double t, t_hittable *object);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hittable.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 12:13:50 by revieira          #+#    #+#             */
/*   Updated: 2023/07/25 19:31:58 by fnacarel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HITTABLE_H
# define HITTABLE_H

# include "objects.h"

typedef struct s_range
{
	double	min;
	double	max;
}	t_range;

typedef struct s_hit
{
	t_point	point;
	t_vec3	normal;
	double	t;
}	t_hit;

typedef struct s_hittable
{
	int					type;
	t_plane				*pl;
	t_sphere			*sp;
	t_cylinder			*cy;
	struct s_hittable	*next;
}	t_hittable;

void	hittable_add(char *identifier, void *object, t_hittable **hittable_lst);
void	clean_hittable(t_hittable **hittable_lst);

#endif

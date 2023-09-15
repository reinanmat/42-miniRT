/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hittable.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 12:13:50 by revieira          #+#    #+#             */
/*   Updated: 2023/09/15 19:19:21 by fnacarel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HITTABLE_H
# define HITTABLE_H

# include "objects.h"

typedef struct s_hittable
{
	int					type;
	t_plane				*pl;
	t_sphere			*sp;
	t_cylinder			*cy;
	struct s_hittable	*next;
}	t_hittable;

t_hittable	*init_objects(char **lines);
void		hittable_add(char *type, void *object, t_hittable **header);
void		clean_hittable(t_hittable **hittable_lst);
t_color		get_color(t_hittable *object);
t_material	get_material(t_hittable *object);
t_matrix	get_transform(t_hittable *object);
t_matrix	get_inv_transform(t_hittable *object);

#endif

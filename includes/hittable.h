/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hittable.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 12:13:50 by revieira          #+#    #+#             */
/*   Updated: 2023/08/21 15:53:07 by revieira         ###   ########.fr       */
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

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnacarel <fnacarel@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 00:16:55 by fnacarel          #+#    #+#             */
/*   Updated: 2023/09/28 17:21:25 by fnacarel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	int		len;
	char	*trimmed_str;

	trimmed_str = ft_strdup(s1);
	while (ft_strchr(set, *trimmed_str) && *trimmed_str != '\0')
	{
		len = ft_strlen(trimmed_str);
		ft_memmove(trimmed_str, trimmed_str + 1, len);
	}
	len = ft_strlen(trimmed_str);
	while (*trimmed_str != '\0' && ft_strchr(set, trimmed_str[len - 1]))
	{
		ft_memmove(trimmed_str + len - 1, trimmed_str + len, 1);
		len = ft_strlen(trimmed_str);
	}
	return (trimmed_str);
}

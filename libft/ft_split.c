/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 16:35:48 by revieira          #+#    #+#             */
/*   Updated: 2023/07/07 18:44:19 by fnacarel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	count_words(const char *s, char c)
{
	size_t	words;

	words = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s && *s != c)
			words++;
		while (*s && *s != c)
			s++;
	}
	return (words);
}

char	**ft_split(const char *s, char c)
{
	int		i;
	char	**lst;
	size_t	curr_word_len;

	i = 0;
	if (!s)
		return (0);
	lst = (char **)ft_calloc(sizeof(char *), count_words(s, c) + 1);
	if (!lst)
		return (0);
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
		{
			if (!ft_strchr(s, c))
				curr_word_len = ft_strlen((char *)s);
			else
				curr_word_len = ft_strchr(s, c) - s;
			lst[i++] = ft_substr(s, 0, curr_word_len);
			s += curr_word_len;
		}
	}
	return (lst);
}

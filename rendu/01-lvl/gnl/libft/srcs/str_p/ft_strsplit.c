/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alngo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 16:32:25 by alngo             #+#    #+#             */
/*   Updated: 2016/11/10 17:41:40 by alngo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_count_words(char *str, char c)
{
	size_t		nb_words;

	while (*str && *str == c)
		++str;
	nb_words = (*str ? 1 : 0);
	while (*str)
	{
		if (*str == c && str[1] && str[1] != c)
			++nb_words;
		++str;
	}
	return (nb_words);
}

char			**ft_strsplit(char const *str, char c)
{
	size_t		nb_words;
	char		*wrd_begin;
	char		**result;

	if (str == NULL)
		return (NULL);
	nb_words = ft_count_words((char *)str, c);
	result = (char **)malloc(sizeof(char *) * (nb_words + 1));
	if (!result)
		return (NULL);
	wrd_begin = (char *)str;
	while (*str)
	{
		if (*str == c)
		{
			if (wrd_begin != str)
				*(result++) = ft_strsub(wrd_begin, 0, str - wrd_begin);
			wrd_begin = (char *)str + 1;
		}
		++str;
	}
	if (wrd_begin != str)
		*(result++) = ft_strsub(wrd_begin, 0, str - wrd_begin);
	*result = NULL;
	return (result - nb_words);
}

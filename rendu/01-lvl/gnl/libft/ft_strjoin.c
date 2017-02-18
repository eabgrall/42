/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alngo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 20:18:16 by alngo             #+#    #+#             */
/*   Updated: 2016/11/09 18:35:50 by alngo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strjoin(char const *s1, char const *s2)
{
	char		*tmp;
	char		*start;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	tmp = (char *)malloc(sizeof(char) * (ft_strlen(s1)
			+ ft_strlen(s2)));
	start = tmp;
	if (tmp != NULL)
	{
		while (*s1)
			*tmp++ = *s1++;
		while (*s2)
			*tmp++ = *s2++;
		*tmp = '\0';
	}
	return (start);
}

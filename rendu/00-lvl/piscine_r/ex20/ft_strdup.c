/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_srcdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alngo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 17:33:52 by alngo             #+#    #+#             */
/*   Updated: 2016/11/04 10:56:32 by alngo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_strlen(char *src)
{
	int			i;

	i = 0;
	while (src[i])
		i++;
	return (i);
}

char	*ft_strdup(char *src)
{
	char	*tmp;
	int		i;

	tmp = (char*)malloc(sizeof(char) * (ft_strlen(src) + 1));
	if (tmp != NULL)
	{
		i = 0;
		while (src[i])
		{
			tmp[i] = src[i];
			i++;
		}
		tmp[i] = '\0';
	}
	return (tmp);
}

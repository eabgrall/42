/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alngo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 17:38:42 by alngo             #+#    #+#             */
/*   Updated: 2016/11/04 13:27:14 by alngo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int				*ft_range(int min, int max)
{
	int		*tmp;
	int		i;

	tmp = NULL;
	if (min >= max)
		return (tmp);
	tmp = (int *)malloc(sizeof(int) * (unsigned int)(min - max));
	if (tmp != NULL)
	{
		i = 0;
		while (min < max)
		{
			tmp[i] = min;
			min++;
			i++;
		}
	}
	return (tmp);
}

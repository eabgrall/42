/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alngo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 14:53:32 by alngo             #+#    #+#             */
/*   Updated: 2016/11/14 11:55:40 by alngo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	length_s(long n, int base)
{
	size_t		i;

	i = 0;
	if (n <= 0 && base == 10)
		i++;
	while (n != 0)
	{
		n = n / base;
		i++;
	}
	return (i);
}

char			*ft_itoa_base(int n, int base)
{
	int				div;
	char			*tmp;
	char			*start;
	unsigned int	nb;

	if ((tmp = (char *)malloc(sizeof(char) * (length_s(n, base) + 1))) == NULL)
		return (NULL);
	div = 1;
	start = tmp;
	if (n < 0 && base == 10)
		*tmp++ = '-';
	nb = ABS(n);
	while ((nb / div) >= (unsigned int)base)
		div *= base;
	while (div != 0)
	{
		if ((nb / div) < 10)
			*tmp++ = ((nb / div) + '0');
		else
			*tmp++ = ((nb / div) + 55);
		nb %= div;
		div /= base;
	}
	*tmp++ = '\0';
	return (start);
}

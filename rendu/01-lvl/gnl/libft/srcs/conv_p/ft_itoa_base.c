/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alngo <alngo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 19:45:11 by alngo             #+#    #+#             */
/*   Updated: 2017/01/10 15:12:43 by alngo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t		length_s(long n, int base)
{
	size_t			i;

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

char				*ft_itoa_base(int n, int base, char *s)
{
	char			*tmp;
	int				pos;
	unsigned int	nb;

	if (!(tmp = ft_strnew(length_s(n, base))))
		return (NULL);
	pos = length_s(n, base);
	if (!(n))
		tmp[--pos] = '0';
	nb = ft_abs(n);
	while (nb != 0)
	{
		tmp[--pos] = s[nb % base];
		nb = nb / base;
	}
	ft_putstr(tmp + ft_strlen(tmp));
	if (n < 0 && base == 10)
		tmp[--pos] = '-';
	return (tmp);
}

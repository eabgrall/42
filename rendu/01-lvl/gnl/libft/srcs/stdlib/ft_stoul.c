/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stoul.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alngo <alngo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 17:32:37 by alngo             #+#    #+#             */
/*   Updated: 2017/03/07 20:19:20 by alngo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int			pos(int c, int base)
{
	char			*hex;
	int				i;

	hex = "0123456789abcdef";
	i = 0;
	while (i < base)
	{
		if (hex[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

static int			lenght(char *s, int base)
{
	int				i;

	i = 0;
	while (s[i] && (pos(ft_tolower(s[i]), base) != -1))
		i++;
	return (i);
}

unsigned long		ft_stoul(const char *s, int base)
{
	unsigned long	n;
	char			sign;
	int				len;

	if (base < 0 || base == 1 || base > 16 || !(base))
		return (0);
	while (ft_isspace(*s))
		s++;
	sign = (*s == '-' || *s == '+') ? *s++ : '+';
	while (*s == '0')
		s++;
	len = lenght((char *)s, base) - 1;
	n = 0;
	while (len >= 0)
	{
		n = n + (pos(ft_tolower(*s), base) * ft_pow(base, len));
		len--;
		s++;
	}
	return (sign == '-' && base == 10 ? -n : n);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtol.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alngo <alngo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 17:32:09 by alngo             #+#    #+#             */
/*   Updated: 2017/02/07 20:15:03 by alngo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long					ft_strtol(const char *s, int base)
{
	char				*tmp;
	unsigned long		n;

	tmp = (char *)s;
	while (ft_isspace(*tmp))
		tmp++;
	n = ft_stoul(s, base);
	if (*tmp == '-' && n <= LONG_MAX)
		return (LONG_MIN);
	else if (*tmp != '-' && LONG_MAX < n)
		return (LONG_MAX);
	else
		return ((long)n);
}

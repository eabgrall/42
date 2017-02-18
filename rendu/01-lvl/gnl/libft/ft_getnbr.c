/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alngo <alngo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 14:20:11 by alngo             #+#    #+#             */
/*   Updated: 2016/11/29 14:23:38 by alngo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t			count_nbr(char *s)
{
	size_t				nb;

	nb = 0;
	while (*s)
	{
		if (ft_isdigit(*s))
		{
			nb++;
			while (ft_isdigit(*s) && *s)
				s++;
			if (!(*s))
				return (nb);
		}
		s++;
	}
	return (nb);
}

static int				nb_forward(char *s)
{
	if (*s == '+' || *s == '-')
		s++;
	return (ft_isdigit(*s));
}

int						ft_getnbr(char *s, int **tab)
{
	size_t				nb;
	int					*tmp;
	int					i;

	if (!(*s) || !(nb = count_nbr(s)))
		return (0);
	if (!(tmp = (int *)malloc(sizeof(int) * nb)))
		return (-1);
	i = 0;
	while (*s)
	{
		while (!(ft_isdigit(*s)) && *s != '+' && *s != '-')
			s++;
		if (ft_isdigit(*s) || *s == '+' || *s == '-')
		{
			if (nb_forward(s))
				tmp[i++] = ft_atoi(s);
			if (*s == '+' || *s == '-')
				s++;
			while (ft_isdigit(*s))
				s++;
		}
	}
	*tab = tmp;
	return (nb);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gather.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alngo <alngo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 20:27:05 by alngo             #+#    #+#             */
/*   Updated: 2017/02/23 18:04:01 by alngo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

int						set(char *s1, char *s2, int max, char c)
{
	int					i;

	i = 0;
	while (i <= max * max)
	{
		if (ft_isupper(s2[i]))
			s1[i] = c;
		i++;
	}
	return (1);
}

int						pc_shift(t_pc **dock, int n)
{
	int					max;
	int					i;

	i = 0;
	while (dock[i])
	{
		max = n * dock[i]->h;
		while (max > n - 2)
		{
			if (ft_isupper((dock[i]->pc)[max]))
			{
				(dock[i]->pc)[max] = '.';
				(dock[i]->pc)[(max + (max / (n - 1)))] = dock[i]->l;
			}
			max--;
		}
		i++;
	}
	return (1);
}

int						simili(char *s1, char *s2, int max)
{
	int					i;

	i = 0;
	while (i <= max * max)
	{
		if (ft_isupper(s1[i]) && ft_isupper(s2[i]))
			return (0);
		i++;
	}
	return (1);
}

int						pc_deshift(t_pc **dock, int n)
{
	int					y;
	int					i;

	i = 0;
	y = -1;
	while (dock[++y])
		if (dock[y]->w > n)
			return (0);
	while (dock[i])
	{
		y = n;
		while (y < (dock[i]->h * 4))
		{
			if (ft_isupper((dock[i]->pc)[y]))
			{
				(dock[i]->pc)[y] = '.';
				(dock[i]->pc)[(y - (y / (n + 1)))] = dock[i]->l;
			}
			y++;
		}
		i++;
	}
	return (1);
}

int						leveling(t_pc **dock, int n, int *base)
{
	int					lvl;

	lvl = 0;
	if (n < *base)
	{
		while (*base - lvl++ > n)
			pc_deshift(dock, *base - lvl);
	}
	else
	{
		while (*base + lvl++ < n)
			pc_shift(dock, *base + lvl);
	}
	*base = n;
	return (n);
}

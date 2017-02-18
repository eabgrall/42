/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alngo <alngo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 20:26:52 by alngo             #+#    #+#             */
/*   Updated: 2016/12/13 20:34:36 by alngo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

int						error(char *s)
{
	ft_putstr(s);
	return (0);
}

int						cleaner(t_pc **dock, t_field *field)
{
	int					i;

	if (field)
		free(field);
	if (dock)
	{
		if (*dock)
		{
			i = 0;
			while (dock[i])
			{
				free(dock[i]);
				i++;
			}
		}
		free(dock);
	}
	return (0);
}

int						dock_pc(t_pc **dock, char *buf, int i)
{
	int					y;
	char				*tmp;

	y = 0;
	if (!(string_look(buf)))
		return (0);
	if (!(dock[i] = (t_pc *)ft_memalloc(sizeof(t_pc))))
		return (0);
	if (!(dock[i]->pc = ft_strnew(128)))
		return (0);
	ft_memset(dock[i]->pc, '.', 128);
	tmp = dock[i]->pc;
	dock[i]->x = 4;
	dock[i]->y = 4;
	padding(&(dock[i]->x), &(dock[i]->y), buf, dock[i]);
	while (buf[y])
	{
		if (buf[y] == '#')
			tmp[(y - (5 * dock[i]->x)) - ((y - (5 * dock[i]->x)) / 5)
			- dock[i]->y] = i + 'A';
		y++;
	}
	dock[i]->l = i + 'A';
	return (1);
}

int						print_resolution(t_field *field, int sqr)
{
	char				*tmp;
	int					i;

	tmp = field->field;
	i = 0;
	while (i < (sqr * sqr))
	{
		ft_putchar(tmp[i]);
		if ((i + 1) == sqr * ((i + 1) / sqr))
			ft_putchar('\n');
		i++;
	}
	return (1);
}

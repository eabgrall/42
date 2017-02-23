/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alngo <alngo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 20:27:19 by alngo             #+#    #+#             */
/*   Updated: 2017/02/23 18:48:47 by alngo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

int						backtrack(t_pc **pc, t_field *field, int sqr, int i)
{
	if (!(pc[i]))
		return (1);
	pc[i]->y = 0;
	while (pc[i]->y <= sqr - pc[i]->h)
	{
		pc[i]->x = 0;
		while (pc[i]->x <= sqr - pc[i]->w)
		{
			if (simili((field->field) + pc[i]->x + (pc[i]->y * sqr),
						pc[i]->pc, sqr))
			{
				set((field->field) + pc[i]->x + (pc[i]->y * sqr),
						pc[i]->pc, sqr, pc[i]->l);
				if (backtrack(pc, field, sqr, i + 1))
					return (1);
				set((field->field) + pc[i]->x + (pc[i]->y * sqr),
						pc[i]->pc, sqr, '.');
			}
			pc[i]->x++;
		}
		pc[i]->y++;
	}
	return (0);
}

int						algo(t_pc **dock, t_field *field)
{
	int					sqr;
	int					lvl;
	int					base;

	if (!(*dock))
		return (0);
	if (!(field->field = ft_strnew(128)))
		return (0);
	sqr = field->min_w;
	lvl = 0;
	ft_memset(field->field, '.', 128);
	while (sqr * sqr < (field->size * 4))
		sqr++;
	base = 4;
	leveling(dock, sqr, &base);
	while (!(backtrack(dock, field, sqr, 0)) && sqr < 12)
	{
		ft_memset(field->field, '.', 128);
		sqr++;
		leveling(dock, sqr, &base);
	}
	if (sqr == 12)
		return (0);
	return (sqr);
}

int						core(const int fd, t_pc **dock, t_field *field)
{
	int					ret;
	char				buf[21];

	if (!(dock = (t_pc **)ft_memalloc(sizeof(t_pc *) * 27)))
		return (0);
	field->size = 0;
	field->length = 0;
	field->min_w = 2;
	while ((ret = read(fd, buf, 21)) >= 20 && field->size < 26 && ret > 0)
	{
		buf[ret] = '\0';
		if (!(dock_pc(dock, buf, field->size, field)))
			return (cleaner(dock, field));
		field->size++;
		field->length += ret;
	}
	if (ret || (field->length + 1) % 21)
		return (cleaner(dock, field));
	if (!(ret = algo(dock, field)))
		return (cleaner(dock, field));
	if (!(print_resolution(field, ret)))
		return (cleaner(dock, field));
	cleaner(dock, field);
	return (1);
}

int						main(int ac, char **av)
{
	int					fd;
	t_pc				**dock;
	t_field				field;

	dock = NULL;
	if (ac != 2)
		return (error("fillit: <one input file>\n"));
	if ((fd = open(av[1], O_RDONLY)) == -1)
		return (error("error\n"));
	if (!(core(fd, dock, &field)))
		return (error("error\n"));
	return (0);
}

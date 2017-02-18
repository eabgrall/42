/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alngo <alngo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 20:32:42 by alngo             #+#    #+#             */
/*   Updated: 2017/01/06 15:26:07 by alngo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

int					side_hashtag(char *s)
{
	int				i;
	int				side;
	int				hashtag;

	i = 0;
	side = 0;
	hashtag = 0;
	while (s[i] && (s[i] == '.' || s[i] == '\n' || s[i] == '#'))
	{
		if (s[i] == '#')
		{
			hashtag++;
			if ((i - 1) >= 0 && s[i - 1] == '#')
				side++;
			if ((i + 1) <= 21 && s[i + 1] == '#')
				side++;
			if ((i - 5) >= 0 && s[i - 5] == '#')
				side++;
			if ((i + 1) <= 21 && s[i + 5] == '#')
				side++;
		}
		i++;
	}
	return ((side == 6 || side == 8) && hashtag == 4);
}

int					string_look(char *s)
{
	char			*tmp;
	int				i;

	if (!(side_hashtag(s)))
		return (0);
	tmp = s;
	i = 0;
	while (tmp[i] && i < 20)
	{
		if ((i + 1) % 5 && tmp[i] == '\n')
			return (0);
		i++;
	}
	return (1);
}

void				padding(int *heigth, int *width, char *tab, t_pc *pc)
{
	int				padbot;
	int				padright;
	int				pos;

	padbot = 0;
	padright = 0;
	pos = 0;
	while (tab[pos])
	{
		if (tab[pos] == '#')
		{
			if (pos / 5 < *heigth)
				*heigth = pos / 5;
			if (pos % 5 < *width)
				*width = pos % 5;
			if (pos / 5 > padbot)
				padbot = pos / 5;
			if (pos % 5 > padright)
				padright = pos % 5;
		}
		pos++;
	}
	pc->h = (padbot - *heigth) + 1;
	pc->w = (padright - *width) + 1;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alngo <alngo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 14:25:28 by alngo             #+#    #+#             */
/*   Updated: 2016/11/29 18:21:45 by alngo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_page				*ft_open_book(const int fd, t_page **book)
{
	t_page					*tmp;

	if (!(*book))
	{
		if (!(*book = (t_page *)ft_memalloc(sizeof(t_page))))
			return (NULL);
		(*book)->fd = fd;
		(*book)->next = NULL;
	}
	tmp = *book;
	while (tmp)
	{
		if (tmp->fd == fd)
			return (tmp);
		if (!(tmp->next))
		{
			if (!(tmp->next = (t_page *)ft_memalloc(sizeof(t_page))))
				return (NULL);
			tmp->next->fd = fd;
			tmp->next->next = NULL;
		}
		tmp = tmp->next;
	}
	return (NULL);
}

static int					ft_machin(char **s, char *buf, int n)
{
	size_t					max;
	char					*tmp;

	if (!(*s) && n > 0)
		*s = ft_strsub(buf, 0, n);
	else if (*s && n > 0)
	{
		if (!(tmp = ft_strnew(ft_strlen(*s) + n)))
			return (-1);
		ft_strcpy(tmp, *s);
		ft_strlcat(tmp, buf, ft_strlen(*s) + n + 1);
		ft_strdel(s);
		*s = tmp;
	}
	tmp = *s;
	max = ft_strlen(*s);
	ft_memset(buf, '\0', n);
	while (max--)
	{
		if (*tmp == '\n')
			return (max);
		tmp++;
	}
	return (0);
}

static int					ft_truc(char **s, char **line)
{
	char					*tmp;
	char					*tmps;
	size_t					max;

	max = ft_strlen(*s);
	tmps = *s;
	while (max--)
	{
		if (*tmps == '\n')
		{
			*line = ft_strsub(*s, 0, ft_strlen(*s) - max - 1);
			tmp = ft_strsub(*s, ft_strlen(*s) - max, max);
			ft_strdel(s);
			*s = tmp;
			return (1);
		}
		tmps++;
	}
	if (*tmps == '\0' && **s != '\0')
	{
		*line = *s;
		ft_strdel(s);
		return (1);
	}
	return (0);
}

int							get_next_line(const int fd, char **line)
{
	char					buf[BUFF_SIZE];
	static t_page			*book;
	t_page					*page;
	int						ret;
	int						nfinder;

	page = ft_open_book(fd, &book);
	while ((ret = read(fd, buf, BUFF_SIZE)))
	{
		if (ret == -1)
			return (-1);
		buf[ret] = '\0';
		nfinder = ft_machin(&(page->str), buf, BUFF_SIZE);
		if (nfinder == -1)
			return (-1);
		else if (nfinder)
			break ;
	}
	if (page->str)
		return (ft_truc(&(page->str), line));
	return (0);
}

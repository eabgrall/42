/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alngo <alngo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 14:25:28 by alngo             #+#    #+#             */
/*   Updated: 2017/02/21 15:17:17 by alngo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "get_next_line.h"

static t_page		*ft_open_book(const int fd, t_page **book)
{
	t_page			*tmp;

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

static int			ft_stack(char **s, char *buf, int n)
{
	size_t			max;
	char			*tmp;

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

static void			ft_page_del(const int fd, t_page **book)
{
	t_page			*del;
	t_page			*before;
	t_page			*after;

	del = *book;
	before = *book;
	while (del->fd != fd)
	{
		before = del;
		del = del->next;
	}
	after = del->next;
	ft_strdel(&(del->str));
	free(del);
	before->next = after;
}

static int			ft_destack(char **s, char **line, const int fd,
		t_page **book)
{
	char			*tmp;
	char			*tmps;
	size_t			max;

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
		*line = ft_strsub(*s, 0, ft_strlen(*s));
		ft_page_del(fd, book);
		return (1);
	}
	return (0);
}

int					get_next_line(const int fd, char **line)
{
	char			buf[BUFF_SIZE];
	static t_page	*book;
	t_page			*page;
	int				ret;
	int				nfinder;

	page = ft_open_book(fd, &book);
	while ((ret = read(fd, buf, BUFF_SIZE)))
	{
		if (ret == -1)
			return (-1);
		buf[ret] = '\0';
		nfinder = ft_stack(&(page->str), buf, BUFF_SIZE);
		if (nfinder == -1)
			return (-1);
		else if (nfinder)
			break ;
	}
	if (page->str)
		return (ft_destack(&(page->str), line, fd, &book));
	return (0);
}

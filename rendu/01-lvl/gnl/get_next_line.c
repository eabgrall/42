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

#include "get_next_line.h"
# include "libft.h"

t_gnl				*get_p(t_list *lst, int fd)
{
	t_list			*tmp;
	t_gnl			*this;

	tmp = lst;
	while(tmp)
	{
		this = (t_gnl *)(tmp->content);
		if (this->fd == fd)
			return (this);
		tmp = tmp->next;
	}
	if (!(this = (t_gnl *)ft_memalloc(sizeof(t_gnl))))
		return (NULL);
	this->fd = fd;
	this->ret = 0;
	this->str = ft_strnew(0);
	this->nl = 0;
	if (!(tmp = ft_lstnew(this, sizeof(t_gnl))))
		return (NULL);
	ft_lstadd(&lst, tmp);
	ft_memdel((void **)&this);
	return ((t_gnl *)(tmp->content));
}

int					del_p(t_list *lst, t_gnl *p, char *line)
{
	return (1);
}

int					stack(t_list *lst, t_gnl *p, char **line, char *buf)
{
	char			*tmp;
	int				i;

	if (p->ret == -1)
		return (-1);
	i = -1;
	p->nl = 0;
	while (i++ < p->ret && !(p->nl))
		p->nl = (buf[i] == '\n' || buf[i] == '\0') ? 1 : 0;
	tmp = ft_strnew(p->ret);
	ft_strncpy(tmp, buf, p->ret);
	p->str = ft_strmerge(p->str, tmp);
	if (p->nl)
	{
		*line = ft_strsub(p->str, 0, (i = ft_strlenchr(p->str, '\n')));
		p->str = ft_strsub(p->str, i, ft_strlen(&((p->str)[i])));
	}
	miniprintf("tmp :%s\n", tmp);
	miniprintf("str :%s\n", p->str);
	miniprintf("line :%s\n", *line);
	return (p->nl ? 1 : 0);
}

int					get_next_line(int fd, char **line)
{
	static t_list	*lst;
	t_gnl			*p;
	char			buf[BUFF_SIZE];
	int				ret;

	if (fd < 0 || !line || !(p = get_p(lst, fd)))
		return (-1);
	miniprintf("str :%s\n", p->str);
	while ((p->ret = read(fd, buf, BUFF_SIZE)))
	{
		if ((ret = stack(lst, p, line, buf)))
			return ((ret == -1) ? -1 : 1);
	}
	//del_page
	return (0);
}

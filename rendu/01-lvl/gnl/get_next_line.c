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

t_page				*get_page(t_list *lst, int fd)
{
	t_list			*tmp;
	t_page			*this;

	tmp = lst;
	while (tmp)
	{
		this = (t_page *)(tmp->content);
		if (this->fd == fd)
			return (this);
		tmp = tmp->next;
	}
	if (!(this = (t_page *)ft_memalloc(sizeof(t_page))))
		return (NULL);
	if (!(page->buf = ft_strnew(BUFF_SIZE)))
		return (NULL);
	this->fd = fd;
	this->ret = BUFF_SIZE;
	this->len = BUFF_SIZE;
	this->nl = 0;
	if (!tmp = ft_lstnew(this, sizeof(t_page)))
		return (NULL);
	ft_memdel((void **)&this);
	ft_lstadd(&lst, tmp);
	return ((t_page *)(tmp->content));
}

int					get_next_line(int const fd, char **line)
{
	static t_list	*lst;
	t_page			*p;
	char			*tmp;
	char			buf[BUFF_SIZE];

	if (fd < 0 || !(line) || !(p = find_page(lst, fd)))
		return (-1);
	while ((p->ret = read(p->fd, buf, BUFF_SIZE)))
	{
		if (p->ret == -1)
			return (-1)
		buf[ret] = '\0';
		if (p->nl = stack(line, buf, BUFF_SIZE);
	}

}

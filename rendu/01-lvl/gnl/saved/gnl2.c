
#include "libft.h"
#include "get_next_line.h"
#include <unistd.h>

char			*find_line(t_page *page)
{
	int			i;

	i = 0;
	page->line = 0;
	while (page->length + i < page->ret)
	{
		if (page->buf[page->length + i] == '\n')
		{
			page->line = 1;
			i++;
			break ;
		}
		i++;
	}
	page->length = page->length + i;
	return (ft_strsub(page->buf, page->length - i, i - page->line));
}

t_page			*find_page(t_list *lst, int fd)
{
	t_page		*page;
	t_list		*tmp;

	tmp = lst;
	while (tmp)
	{
		page = (t_page *)(tmp->content);
		if (page->fd == fd)
			return (page);
		tmp = tmp->next;
	}
	if (!(page = (t_page *)ft_memalloc(sizeof(t_page))))
		return (NULL);
	if (!(page->buf = ft_strnew(BUFF_SIZE)))
		return (NULL);
	page->ret = BUFF_SIZE;
	page->length = BUFF_SIZE;
	page->fd = fd;
	page->line = 1;
	if(!(tmp = ft_lstnew(page, sizeof(t_page))))
		return (NULL);
	ft_memdel((void **)&page);
	ft_lstadd(&lst, tmp);
	return ((t_page *)(tmp->content));
}

void			del_page(t_list **lst, int fd, char **str)
{
	t_page		*page;
	t_list		**tmp;
	t_list		*ptr;

	tmp = lst;
	while (*tmp)
	{
		page = (t_page *)((*tmp)->content);
		if (page->fd == fd)
			break ;
		*tmp = ((*tmp)->next);
	}
	if (*tmp)
	{
		ptr = (*tmp)->next;
		ft_strdel(&(page->buf));
		ft_memdel((void **)&page);
		ft_memdel((void **)tmp);
		*tmp = ptr;
	}
	ft_strdel(str);
}

int		read_buf(t_page *page, t_list *lst, char **tmp, char **line)
{
	if (page->length == page->ret)
	{
		page->ret = read(page->fd, page->buf, BUFF_SIZE);
		if (page->ret == -1)
		{
			del_page(&lst, page->fd, tmp);
			return (-1);
		}
		page->length = 0;
		if (page->ret == 0 && page->line == 0)
		{
				*line = *tmp;
				return (1);
		}
	}
	return (0);
}

int		get_next_line(int const fd, char **line)
{
	static t_list	*lst;
	t_page			*page;
	char			*tmp;
	int				ret;

	if (fd < 0 || line == NULL || !(page = find_page(lst, fd)))
		return (-1);
	tmp = ft_strnew(0);
	while (page->ret > 0)
	{
		if ((ret = read_buf(page, lst, &tmp, line)))
			return (ret);
		while (page->length < page->ret)
		{
			tmp = ft_strconcat(tmp, find_line(page));
			if (page->line)
			{
				*line = tmp;
				return (1);
			}
		}
	}
	del_page(&lst, fd, &tmp);
	return (0);
}

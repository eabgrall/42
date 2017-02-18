/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alngo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 11:11:21 by alngo             #+#    #+#             */
/*   Updated: 2016/11/04 12:16:26 by alngo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>

int			ft_strlen(char *str)
{
	int			i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void		ft_putstr_fd(char *str, int fd)
{
	write(fd, str, ft_strlen(str));
}

void		ft_display_file(int fd)
{
	int			ret;
	char		buf[11];

	ret = read(fd, buf, 10);
	while (ret != 0)
	{
		buf[ret] = '\0';
		ft_putstr_fd(buf, 1);
		ret = read(fd, buf, 10);
	}
}

int			main(int ac, char **av)
{
	int			fd;

	if (ac < 2)
		ft_putstr_fd("File name missing.\n", 2);
	else if (ac > 2)
		ft_putstr_fd("Too many arguments.\n", 2);
	else if (ac == 2)
	{
		fd = open(av[1], O_RDONLY);
		if (fd == -1)
		{
			ft_putstr_fd("open() error\n", 2);
			return (1);
		}
		ft_display_file(fd);
		if (close(fd) == -1)
		{
			ft_putstr_fd("close() error\n", 2);
			return (1);
		}
	}
	return (0);
}

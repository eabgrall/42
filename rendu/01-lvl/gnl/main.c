/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alngo <alngo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 17:35:08 by alngo             #+#    #+#             */
/*   Updated: 2017/03/07 18:00:52 by alngo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"
//#include "gnl.h"
#include <fcntl.h>

char	*ft_strmerge(char *a, char *b);

int			main(int ac, char **av)
{
	char	*line;
	int		ret;
	int		fd;
	int		i;

	if (ac && **av)
	{
		i = 0;
		fd = open(av[1], O_RDONLY);
		while ((ret = get_next_line(fd, &line)))
		{
			ft_putnbr(ret);
			ft_putendl(line);
			if (ret == -1)
				break ;
			i++;
		}
		close(fd);
	}
	return (1);
}

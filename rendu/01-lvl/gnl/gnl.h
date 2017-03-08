/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: palatorr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/21 10:06:52 by palatorr          #+#    #+#             */
/*   Updated: 2016/09/21 10:07:50 by palatorr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GNL_H
# define GNL_H

# include <fcntl.h>
# include "libft.h"
# define BUFF_SIZE 6
# define MAX_PACKS 1000

typedef struct	s_pack
{
	char	*str;
	long	len;
	long	cur;
	int		has_read;
	char	*endl;
}				t_pack;


int				get_next_line(const int fd, char **line);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alngo <alngo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 14:24:01 by alngo             #+#    #+#             */
/*   Updated: 2016/11/29 14:24:10 by alngo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 21

typedef struct	s_page
{
	int			fd;
	char		*str;
	short		nl;
	int			ret;
	int			len;
}				t_page;

int				get_next_line(int const fd, char **line);

#endif

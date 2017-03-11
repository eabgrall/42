#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 4096

typedef struct	s_page
{
	int			fd;
	char		*buf;
	short		line;
	int			ret;
	int			length;
}				t_page;

int				get_next_line(int const fd, char **line);

#endif

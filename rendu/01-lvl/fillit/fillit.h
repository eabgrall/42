/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alngo <alngo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 20:28:25 by alngo             #+#    #+#             */
/*   Updated: 2017/02/23 18:48:50 by alngo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include <fcntl.h>
# define MAX(a, b) (a > b ? a : b)

typedef struct	s_pc
{
	char		*pc;
	int			l;
	int			h;
	int			w;
	int			x;
	int			y;
}				t_pc;

typedef struct	s_field
{
	char		*field;
	int			size;
	int			length;
	int			min_w;
}				t_field;

/*
**__________MAIN__________
*/
int				core(const int fd, t_pc **dock, t_field *field);
int				algo(t_pc **dock, t_field *field);
int				backtrack(t_pc **pc, t_field *field, int sqr, int i);
/*
**__________UTILS_________
*/
int				error(char *s);
int				cleaner(t_pc **dock, t_field *field);
int				dock_pc(t_pc **dock, char *buf, int i, t_field *field);
int				print_resolution(t_field *field, int sqr);
/*
**__________GATHER________
*/
int				leveling(t_pc **dock, int n, int *base);
int				pc_shift(t_pc **dock, int n);
int				pc_deshift(t_pc **dock, int n);
int				simili(char *s1, char *s2, int max);
int				set(char *s1, char *s2, int max, char c);
/*
**__________DATA__________
*/
int				side_hashtag(char *s);
void			padding(int *heigth, int *width, char *tab, t_pc *pc);
int				string_look(char *s);

#endif

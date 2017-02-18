# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alngo <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/04 11:18:55 by alngo             #+#    #+#              #
#    Updated: 2016/11/04 11:20:35 by alngo            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_display_file

SRCS =	ft_display_file.c\

OBJS = ft_display_file.o\

FLAG = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): 
		gcc $(FLAG) -c $(SRCS)
		gcc -o $(NAME) $(OBJS)

clean:
		/bin/rm -f $(OBJS)

fclean: clean
		/bin/rm -f $(NAME)

re: fclean all

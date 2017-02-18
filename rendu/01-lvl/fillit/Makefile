# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alngo <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/04 14:00:05 by alngo             #+#    #+#              #
#    Updated: 2017/01/10 14:51:06 by alngo            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRCS = main.c utils.c gather.c data.c

INCLUDES = ./libft/includes/

OBJS = $(SRCS:.c=.o)

CFLAGS = -Wall -Wextra -Werror

CC = clang

all: $(NAME)

.c.o:
	$(CC) $(CFLAGS) -c -I $(INCLUDES) $<

$(NAME): $(OBJS)
	make -C libft/ fclean && make -C libft/
	clang -o $(NAME) $(OBJS) -I $(INCLUDES) -L libft/ -lft

clean:
	make -C libft/ fclean
	/bin/rm -f $(OBJS)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

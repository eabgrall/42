# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alngo <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/03 18:38:00 by alngo             #+#    #+#              #
#    Updated: 2016/11/03 18:48:30 by alngo            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRCS =	./srcs/ft_putchar.c\
		./srcs/ft_putstr.c\
		./srcs/ft_strcmp.c\
		./srcs/ft_strlen.c\
		./srcs/ft_swap.c

INCLUDES = ./includes/

OBJS = ft_putchar.o\
	   ft_putstr.o\
	   ft_strcmp.o\
	   ft_strlen.o\
	   ft_swap.o

FLAG = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): 
		gcc $(FLAG) -c $(SRCS) -I $(INCLUDES)
		ar rc $(NAME) $(OBJS)
		ranlib $(NAME)

test: all
		gcc $(FLAG) main.c -L. -lft

clean:
		/bin/rm -f $(OBJS)

fclean: clean
		/bin/rm -f $(NAME)

re: fclean all

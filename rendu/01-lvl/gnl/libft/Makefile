# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alngo <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/04 14:00:05 by alngo             #+#    #+#              #
#    Updated: 2017/02/03 14:56:44 by alngo            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror

SRCDIR = ./srcs/
OBJDIR = ./objs/
INCDIR = ./includes

STRINGPATH = string/
STDLIBPATH = stdlib/
CTYPEPATH = ctype/
LISTPPATH = list_p/
STRPPATH = str_p/
PUTPPATH = put_p/
MEMPPATH = mem_p/
MATHPPATH = math_p/
PERSPPATH = pers_p/
CONVPPATH = conv_p/

SRC = $(STRINGPATH)ft_memchr.c\
	  $(STRINGPATH)ft_memcmp.c\
	  $(STRINGPATH)ft_memcpy.c\
	  $(STRINGPATH)ft_memmove.c\
	  $(STRINGPATH)ft_memset.c\
	  $(STRINGPATH)ft_strcat.c\
	  $(STRINGPATH)ft_strchr.c\
	  $(STRINGPATH)ft_strcmp.c\
	  $(STRINGPATH)ft_strcpy.c\
	  $(STRINGPATH)ft_strlen.c\
	  $(STRINGPATH)ft_strncat.c\
	  $(STRINGPATH)ft_strncmp.c\
	  $(STRINGPATH)ft_strncpy.c\
	  $(STRINGPATH)ft_strrchr.c\
	  $(STRINGPATH)ft_strstr.c\
	  $(STDLIBPATH)ft_abs.c\
	  $(STDLIBPATH)ft_labs.c\
	  $(STDLIBPATH)ft_div.c\
	  $(STDLIBPATH)ft_ldiv.c\
	  $(STDLIBPATH)ft_atoi.c\
	  $(STDLIBPATH)ft_atol.c\
	  $(STDLIBPATH)ft_strtol.c\
	  $(STDLIBPATH)ft_stoul.c\
	  $(CTYPEPATH)ft_isdigit.c\
	  $(CTYPEPATH)ft_isupper.c\
	  $(CTYPEPATH)ft_islower.c\
	  $(CTYPEPATH)ft_isalpha.c\
	  $(CTYPEPATH)ft_isalnum.c\
	  $(CTYPEPATH)ft_isspace.c\
	  $(CTYPEPATH)ft_isascii.c\
	  $(CTYPEPATH)ft_isprint.c\
	  $(CTYPEPATH)ft_toupper.c\
	  $(CTYPEPATH)ft_tolower.c\
	  $(LISTPPATH)ft_lstnew.c\
	  $(LISTPPATH)ft_lstat.c\
	  $(LISTPPATH)ft_lstmap.c\
	  $(LISTPPATH)ft_lstiter.c\
	  $(LISTPPATH)ft_lstdelone.c\
	  $(LISTPPATH)ft_lstdel.c\
	  $(LISTPPATH)ft_lstadd.c\
	  $(LISTPPATH)ft_lstaddafter.c\
	  $(LISTPPATH)ft_lstcount.c\
	  $(STRPPATH)ft_strdup.c\
	  $(STRPPATH)ft_strlcat.c\
	  $(STRPPATH)ft_strnstr.c\
	  $(STRPPATH)ft_strcasestr.c\
	  $(STRPPATH)ft_strnew.c\
	  $(STRPPATH)ft_strdel.c\
	  $(STRPPATH)ft_strclr.c\
	  $(STRPPATH)ft_striter.c\
	  $(STRPPATH)ft_striteri.c\
	  $(STRPPATH)ft_strmap.c\
	  $(STRPPATH)ft_strmapi.c\
	  $(STRPPATH)ft_strequ.c\
	  $(STRPPATH)ft_strnequ.c\
	  $(STRPPATH)ft_strsub.c\
	  $(STRPPATH)ft_strjoin.c\
	  $(STRPPATH)ft_strtrim.c\
	  $(STRPPATH)ft_strsplit.c\
	  $(STRPPATH)ft_strrenew.c\
	  $(STRPPATH)ft_chachange.c\
	  $(STRPPATH)ft_foreachar.c\
	  $(STRPPATH)ft_foreachstr.c\
	  $(STRPPATH)ft_countpad.c\
	  $(STRPPATH)ft_strlenchr.c\
	  $(STRPPATH)ft_strmerge.c\
	  $(PUTPPATH)ft_putchar_fd.c\
	  $(PUTPPATH)ft_putstr_fd.c\
	  $(PUTPPATH)ft_putnbr_fd.c\
	  $(PUTPPATH)ft_putendl_fd.c\
	  $(PUTPPATH)ft_putchar.c\
	  $(PUTPPATH)ft_putstr.c\
	  $(PUTPPATH)ft_putnbr.c\
	  $(PUTPPATH)ft_putendl.c\
	  $(PUTPPATH)ft_putstrtab.c\
	  $(PUTPPATH)ft_putinttab.c\
	  $(MEMPPATH)ft_memalloc.c\
	  $(MEMPPATH)ft_memrealloc.c\
	  $(MEMPPATH)ft_memdel.c\
	  $(MEMPPATH)ft_memccpy.c\
	  $(MEMPPATH)ft_bzero.c\
	  $(MATHPPATH)ft_sqrt.c\
	  $(MATHPPATH)ft_iterative_factorial.c\
	  $(MATHPPATH)ft_foreach.c\
	  $(MATHPPATH)ft_pow.c\
	  $(PERSPPATH)miniprintf.c\
	  $(CONVPPATH)ft_itoa_base.c\
	  $(CONVPPATH)ft_itoa.c\

OBJS = $(SRCS:.c=.o)

.PHONY: all build clean fclean re

SRC := $(filter $(addprefix %, .c), $(SRC))
SRCS = $(addprefix $(SRCDIR), $(SRC))
OBJS = $(addprefix $(OBJDIR), $(addsuffix .o, $(basename $(SRC))))
OBJS_DIRS = $(sort $(dir $(OBJS)))

INCS_DIRS = $(addsuffix /, $(INCDIR))
INCS = $(addprefix -I, $(INCS_DIRS))

all: $(NAME)

$(NAME): build $(LIBS) $(OBJS)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

build:
	mkdir -p $(OBJDIR)
	mkdir -p $(OBJS_DIRS)

clean:
	/bin/rm -f $(LIBS)
	/bin/rm -rf $(OBJDIR)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

test:
	$(CC) $(CFLAGS) -fsanitize=address main.c -I $(INCDIR) -L. -lft

testclean:
	/bin/rm -f a.out

testfclean:
	/bin/rm -f main.c

$(OBJDIR)%.o: $(SRCDIR)%.c
	$(CC) -c -o $@ $< $(INCS) $(CFLAGS)

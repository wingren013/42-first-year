# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kyork <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/08/22 09:02:39 by kyork             #+#    #+#              #
#    Updated: 2016/10/07 13:54:50 by kyork            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FILENAMES	+= main.c read.c tet_shapes.c solve.c field.c
FILENAMES	+=

LIBFILES	+= ft_memcmp.c

HEADFILES	+= fillit.h

LIBHEADS	+= libft.h

NAME		= fillit
CC			= gcc
CFLAGS		+= -Wall -Wextra -Werror
LDFLAGS		+= -Wall -Wextra -Werror

ifeq ($(DEBUG), 1)
	#CFLAGS	+= -fsanitize=address
	#LDFLAGS	+= -fsanitize=address
else
endif

ifdef ALLOCWRAP
	LDFLAGS += alloc_wrap.c -DHAVE_ALLOCWRAP
	CFLAGS	+= -DHAVE_ALLOCWRAP
endif

SRCS	= $(addprefix srcs/, $(FILENAMES))
LIBSRCS	= $(addprefix lib/, $(LIBFILES))
SHEADS	= $(addprefix srcs/, $(HEADFILES))
LHEADS	= $(addprefix includes/, $(LIBHEADS))
FOBJS	= $(addprefix build/, $(FILENAMES:.c=.o))
LOBJS	= $(addprefix build/, $(LIBFILES:.c=.o))

OBJS	= $(FOBJS) $(LOBJS)

OBJS_NO_MAIN = $(filter-out build/main.o, $(OBJS))

.PHONY: all clean fclean re test

all: $(NAME)

re: fclean all

clean:
	rm -rf build/

fclean: clean
	rm -f $(NAME)

build:
	mkdir build/

$(NAME): $(OBJS)
	$(CC) $(LDFLAGS) -o $@ $(OBJS)

build/%.o: srcs/%.c $(SHEADS) $(LHEADS) | build
	$(CC) $(CFLAGS) -Iincludes/ -c $< -o $@

build/ft_%.o: lib/ft_%.c $(LHEADS) | build
	$(CC) $(CFLAGS) -Iincludes/ -c $< -o $@

norm:
	norminette srcs/ includes/ | grep -e 'Warning' -e 'Error' -B1 || true

test1: srcs/test_print_tets.c $(OBJS_NO_MAIN)
	$(CC) $(LDFLAGS) -o $@ $< $(OBJS_NO_MAIN)
	./$@
	rm $@

test2: srcs/test_read.c $(OBJS_NO_MAIN)
	$(CC) $(LDFLAGS) -o $@ $< $(OBJS_NO_MAIN)

.PHONY: test1 test2

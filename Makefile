# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: joseoliv <joseoliv@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/30 22:18:11 by joseoliv          #+#    #+#              #
#    Updated: 2024/04/30 22:19:28 by joseoliv         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS = ft_printf.c some_put_nbr.c some_funcs.c

OBJS = $(SRCS:.c=.o)

CC = cc

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME) : $(OBJS)
	@ar rcs $(NAME) $(OBJS)

$(OBJS) : $(SRCS)
	@$(CC) $(CFLAGS) -c $(SRCS)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)
	rm -rf main.o

re: fclean all
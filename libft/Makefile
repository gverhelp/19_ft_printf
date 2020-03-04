# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gverhelp <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/11 15:39:59 by gverhelp          #+#    #+#              #
#    Updated: 2020/01/13 15:44:55 by gverhelp         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = *.c
NAME = libft.a
OBJS = $(SRC:%.c=%.o)
CFLAGS = -Wall -Wextra -Werror -I$(HEADER)
GCC = gcc
RM = rm -rf
HEADER = ./

all: $(NAME)

$(OBJS): $(SRC)
	$(GCC) $(CFLAGS) -c $(SRC)

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all test clean fclean re

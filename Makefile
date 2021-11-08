# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fasad <fasad@student.42abudhabi.ae>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/08 09:46:25 by fasad             #+#    #+#              #
#    Updated: 2021/11/08 09:54:51 by fasad            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libftprintf.a

SRCS		= ft_printf.c \
			  ft_printf_utils.c \
			  ft_printf_assist.c \

OBJS		= $(SRCS:%.c=%.o)
FLAGS		= -Wall -Werror -Wextra

$(NAME):
		gcc $(LFAGS) -c $(SRCS) 
		ar rc $(NAME) $(OBJS)

all: $(NAME)

clean:
		rm -f $(OBJS)

fclean:	clean
		rm -f $(NAME)

re: fclean all

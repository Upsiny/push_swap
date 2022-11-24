# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hguillau <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/26 09:54:42 by hguillau          #+#    #+#              #
#    Updated: 2022/11/24 16:25:53 by hguillau         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS    	=		main.c						\
					includes/movement_1.c		\
					includes/movement_2.c		\
					includes/movement_3.c		\
					includes/ps_utils.c			\
					includes/algo.c				\
					includes/algo2.c			\
					includes/algo3.c			\
					printf/ft_printf.c			\
					printf/ft_printf_func.c		\
					printf/ft_printf_func2.c	\

LIBFT		= 		libft/libft.a

OBJS    	=		${SRCS:.c=.o}

NAME    	=		push_swap

CC      	=		gcc

RM      	=		rm -f

CFLAGS  	=		-Wall -Wextra -Werror -g -fsanitize=address

all:				LIBFT_M ${NAME}

LIBFT_M		:
					make -C libft/ all

${NAME}:			${OBJS}
					${CC} ${CFLAGS} -o ${NAME} ${OBJS} ${LIBFT}

clean:
					${RM} ${OBJS}

fclean: 			clean
					${RM} ${NAME}

re:     			fclean all

.PHONY: 			all clean fclean re

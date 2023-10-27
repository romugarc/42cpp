# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rgarcia <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/09 10:28:48 by rgarcia           #+#    #+#              #
#    Updated: 2023/10/20 16:43:40 by rgarcia          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= easyfind

SRCS	=	main.cpp

OBJS	=	${SRCS:.cpp=.o}

HEADER_FILES	=	pmergeme.hpp

CC		=	c++
RM		=	rm -f

CFLAGS	=	-Wall -Wextra -Werror -std=c++17 -fsanitize=address -g

all:		${NAME}

%.o : %.cpp 	${HEADER_FILES}
		${CC} ${CFLAGS} -c $< -o ${<:.cpp=.o}

$(NAME):	${OBJS}
			@${CC} ${CFLAGS} ${OBJS} -o ${NAME}

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re ${NAME}

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rgarcia <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/09 06:55:19 by rgarcia           #+#    #+#              #
#    Updated: 2023/11/09 10:55:44 by rgarcia          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= btc

SRCS	=	main.cpp			\
			BitcoinExchange.cpp	\
			exception.cpp

OBJS	=	${SRCS:.cpp=.o}

HEADER_FILES	=	BitcoinExchange.hpp

CC		=	c++
RM		=	rm -f

CFLAGS	=	-Wall -Wextra -Werror -std=c++98 -fsanitize=address

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

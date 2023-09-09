# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rgarcia <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/09 10:26:01 by rgarcia           #+#    #+#              #
#    Updated: 2023/09/09 10:26:03 by rgarcia          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= bureaucrat01

SRCS	=	main.cpp		\
			Bureaucrat.cpp	\
			Form.cpp		\

OBJS	=	${SRCS:.cpp=.o}

HEADER_FILES	=	Bureaucrat.hpp	\
					Form.hpp		\

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

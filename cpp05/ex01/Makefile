# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: warnora <warnora@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/24 09:27:10 by rgarcia           #+#    #+#              #
#    Updated: 2023/09/05 03:20:50 by warnora          ###   ########.fr        #
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

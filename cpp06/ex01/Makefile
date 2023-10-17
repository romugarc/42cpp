# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rgarcia <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/09 10:28:48 by rgarcia           #+#    #+#              #
#    Updated: 2023/09/09 10:28:49 by rgarcia          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= serialize

SRCS	=	main.cpp	\
			Serializer.cpp	\
			Data.cpp

OBJS	=	${SRCS:.cpp=.o}

HEADER_FILES	=	Serializer.hpp \
					Data.hpp

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

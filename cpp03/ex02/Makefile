# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rgarcia <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/24 09:06:42 by rgarcia           #+#    #+#              #
#    Updated: 2023/07/24 09:06:43 by rgarcia          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= fragtrap

SRCS	=	main.cpp		\
			ClapTrap.cpp	\
			ScavTrap.cpp	\
			FragTrap.cpp	\

OBJS	=	${SRCS:.cpp=.o}

HEADER_FILES	=	ClapTrap.hpp	\
					ScavTrap.hpp	\
					FragTrap.hpp	\

CC		=	c++
RM		=	rm -f

CFLAGS	=	-Wall -Wextra -Werror -std=c++98

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

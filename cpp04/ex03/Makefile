# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: warnora <warnora@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/24 09:27:10 by rgarcia           #+#    #+#              #
#    Updated: 2023/09/06 04:50:33 by warnora          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= materia

SRCS	=	main.cpp			\
			AMateria.cpp		\
			Character.cpp		\
			MateriaSource.cpp	\
			Cure.cpp			\
			Ice.cpp				\

OBJS	=	${SRCS:.cpp=.o}

HEADER_FILES	=	AMateria.hpp		\
					Character.hpp		\
					ICharacter.hpp		\
					IMateriaSource.hpp	\
					MateriaSource.hpp	\
					Cure.hpp			\
					Ice.hpp				\

CC		=	c++
RM		=	rm -f

CFLAGS	=	-Wall -Wextra -Werror -std=c++98 -g -fsanitize=address

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

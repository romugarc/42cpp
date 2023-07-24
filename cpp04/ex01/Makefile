# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rgarcia <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/24 09:25:32 by rgarcia           #+#    #+#              #
#    Updated: 2023/07/24 09:25:33 by rgarcia          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= animal

SRCS	=	main.cpp		\
			Animal.cpp		\
			Dog.cpp			\
			Cat.cpp			\
			WrongAnimal.cpp	\
			WrongCat.cpp	\
			Brain.cpp		\

OBJS	=	${SRCS:.cpp=.o}

HEADER_FILES	=	Animal.hpp		\
					Dog.hpp			\
					Cat.hpp			\
					WrongAnimal.hpp	\
					WrongCat.hpp	\
					Brain.hpp		\

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

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: warnora <warnora@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/24 09:27:10 by rgarcia           #+#    #+#              #
#    Updated: 2023/09/05 06:46:15 by warnora          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= shrubbery

SRCS	=	main.cpp					\
			Bureaucrat.cpp				\
			AForm.cpp					\
			PresidentialPardonForm.cpp	\
			RobotomyRequestForm.cpp		\
			ShrubberyCreationForm.cpp	\

OBJS	=	${SRCS:.cpp=.o}

HEADER_FILES	=	Bureaucrat.hpp				\
					AForm.hpp					\
					PresidentialPardonForm.hpp	\
					RobotomyRequestForm.hpp		\
					ShrubberyCreationForm.hpp	\

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

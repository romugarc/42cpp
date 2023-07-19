NAME	= scavtrap

SRCS	=	main.cpp		\
			ClapTrap.cpp	\
			ScavTrap.cpp	\

OBJS	=	${SRCS:.cpp=.o}

HEADER_FILES	=	ClapTrap.hpp	\
					ScavTrap.hpp	\

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
NAME	= megaphone

SRCS	=	megaphone.cpp

OBJS	=	${SRCS:.cpp=.o}

CC		=	c++
RM		=	rm -f

CFLAGS	=	-Wall -Wextra -Werror -std=c++98

all:		${NAME}

%.o : %.cpp 	${HEADER_FILES}
		${CC} ${CFLAGS} -c $< -o ${<:.cpp=.o}

$(NAME):	${OBJS}
			@${CC} ${CFLAGS} ${OBJS} -o megaphone

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} megaphone

re:			fclean all

.PHONY:		all clean fclean re megaphone
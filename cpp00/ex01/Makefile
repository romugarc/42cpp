NAME	= phonebook

SRCS	=	main.cpp		\
			Contact.cpp		\
			PhoneBook.cpp	\

OBJS	=	${SRCS:.cpp=.o}

HEADER_FILES	=	PhoneBook.hpp	\
					Contact.hpp		\

CC		=	c++
RM		=	rm -f

CFLAGS	=	-Wall -Wextra -Werror -std=c++98

all:		${NAME}

%.o : %.cpp 	${HEADER_FILES}
		${CC} ${CFLAGS} -c $< -o ${<:.cpp=.o}

$(NAME):	${OBJS}
			@${CC} ${CFLAGS} ${OBJS} -o phonebook

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} phonebook

re:			fclean all

.PHONY:		all clean fclean re phonebook
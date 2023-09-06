# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: warnora <warnora@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/28 10:53:54 by jrinna            #+#    #+#              #
#    Updated: 2023/09/06 06:42:17 by warnora          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LST_SRC := AMateria.cpp Ice.cpp Cure.cpp Character.cpp MateriaSource.cpp main.cpp
LST_INC := AMateria.hpp Ice.hpp Cure.hpp Character.hpp MateriaSource.hpp ICharacter.hpp IMateriaSource.hpp
LST_OBJ := ${LST_SRC:.cpp=.o}

DIR_SRC := source
DIR_INC := include
DIR_OBJ := .object

SRC := ${addprefix ${DIR_SRC}/,${LST_SRC}}
OBJ := ${addprefix ${DIR_OBJ}/,${LST_OBJ}}
INC := ${addprefix ${DIR_INC}/,${LST_INC}}

CC := c++ -std=c++98
CFLAGS := -Wall -Wextra -Werror -Wshadow -fsanitize=address -g3
NAME := micro_rpg

all : ${NAME}

${NAME} : ${OBJ}
	${CC} ${CFLAGS} ${OBJ} -o ${NAME}

${DIR_OBJ}/%.o : ${DIR_SRC}/%.cpp ${INC} Makefile | ${DIR_OBJ}
	${CC} ${CFLAGS} -c $< -o $@ -I ${DIR_INC}

${DIR_OBJ} :
	mkdir -p ${DIR_OBJ}

clean :
	rm -rf ${DIR_OBJ}

fclean : clean
	rm -rf ${NAME}

re : fclean	all

.PHONY : all re clean fclean

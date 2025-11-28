#### VARIABLES ####
NAME = libftprintf.a
# HEADER_PATH = include
CC= cc
CFLAGS=-Wall -Wextra -Werror
# OBJ=ft_*.c =.o
# SRCS = $(HEADER_PATH)ft_atoi
#### SOURCE ####
SRC_FILES = ft_printf.c \
		ft_printf_2.c

OBJ_FILES = $(SRC_FILES:.c=.o)
# OBJ_BONUS = $(SRC_BONUS:.c=.o)
# OBJ_FILES = $(addsuffix .o, $(SRC_FILES))
#### RULES ####
all: ${NAME}

${NAME} : ${OBJ_FILES}
	ar rcs ${NAME} ${OBJ_FILES}

%.o: %.c
	${CC} ${CFLAGS} -c $< -o $@

clean:
	rm -f ${OBJ_FILES}

fclean: clean
	rm -f ${NAME}

re: fclean  all

.PHONY: all clean fclean re

SRC =  srcs/main.c			\
	srcs/put_line.c			\


CFLAGS = #-Wall -Werror -Wextra

OBJ = ${SRC:.c=.o}

NAME = fdf

CC = gcc

MLX = ~/minilibx/libmlx_Linux.a -lXext -lX11 -I ~/minilibx/include/

LIBFT = libft/libft.a

INCLUDE = -I ~/minilibx/include/ -Iinclude/

all: ${NAME}

.c.o:
	${CC} ${INCLUDE} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}: ${OBJ}
	${CC} ${INCLUDE} ${OBJ} ${MLX} ${LIBFT} -o ${NAME}
clean:
	rm -f ${OBJ}

fclean: clean
	rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re

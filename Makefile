# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nguiard <nguiard@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/16 15:42:20 by nguiard           #+#    #+#              #
#    Updated: 2022/01/31 12:31:29 by nguiard          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC =  srcs/main.c			\
	srcs/put_line.c			\
	srcs/mega_split.c		\
	srcs/parsing_fdf.c		\
	srcs/init.c				\
	srcs/math.c				\
	srcs/get_info.c			\
	srcs/ft_draw.c			\
	srcs/all_draw.c			\
	srcs/mlx_colors.c		\
	srcs/get_color.c		\
	srcs/key_touched.c		\
	srcs/key_touched2.c		\

CFLAGS = -Wall -Werror -Wextra

OBJ = ${SRC:.c=.o}

NAME = fdf

CC = gcc

MLX = mlx/libmlx_Linux.a -lXext -lX11 -Imlx/include/

LIBFT = libft/libft.a

MATH = -lm

INCLUDE = -Imlx/include/ -Iinclude/

all: ${NAME}

nb:=1

n:=0

a:=0

.c.o:
	@${CC} ${INCLUDE} ${CFLAGS} -c $< -o ${<:.c=.o}
	$(eval n=$(shell echo $$(($(nb)/5 * 70))))
	$(eval a=$(shell echo $$((202 - $(n)))))
	@printf "\033[0;38;5;%dm" "${a}"
	@echo -n "\rCompilation de l'objet" ${nb} "terminee\033[0m"
	$(eval nb=$(shell echo $$(($(nb)+1))))

${NAME}: ${OBJ}
	@echo -n "\n"
	@make -C libft
	@echo -n "\n"
	@make -C mlx
	@echo -n "\n"
	@${CC} ${INCLUDE} ${OBJ} ${MLX} ${MATH} ${LIBFT} -o ${NAME}
	@echo "\033[1;92mFdF pret!\033[0m"

bonus: all

clean:
	@rm -f ${OBJ}
	@echo "clean ok!"

fclean:
	@rm -f ${OBJ} ${NAME}
	@echo "fclean ok!"

re: fclean all

.PHONY: all clean fclean re normal renormal bonus

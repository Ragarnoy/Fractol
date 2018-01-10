# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tlernoul <tlernoul@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/21 23:59:53 by tlernoul          #+#    #+#              #
#    Updated: 2018/01/10 18:35:09 by tlernoul         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g
CPPFLAGS = -Iinclude
LDLIBS = -lft -lmlx
ASAN_OPTIONS = detect_leaks=1
LDFLAGS = -Llibft -Lmlx -framework OpenGL -framework AppKit -lpthread -fsanitize=address
INC_PATH = include/
OBJ_PATH = obj
SRC_PATH = src
SRC_NAME = main.c \
		colors.c \
		f_julia.c \
		f_bship.c \
		m_events.c \
		f_tricorn.c \
		kb_events.c \
		movements.c \
		setup_env.c \
		rendering.c \
		f_mandelbrot.c \

OBJ_NAME = $(SRC_NAME:c=o)
SRC = $(addprefix $(SRC_PATH)/,$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))

all: $(NAME)
	@printf "Fractol ready. \033[32m✔\033[0m                                 \n"

$(NAME): $(OBJ)
	@printf "Making necessary libs                                           \n"
	@make -C libft 2> /dev/null || true
	@make -C mlx 2> /dev/null || true
	@printf "Libraries done \033[32m✔\033[0m \nLinking...                    \n"
	@$(CC) $(LDLIBS) $(LDFLAGS) $^ -o $@
	@printf "OBJs linked. 🔗                                                  \n"

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	@$(CC) $(CFLAGS) $(CPPFLAGS) -o $@ -c $<

clean:
	@printf "Following files have been removed:                              \n"
	@rm -fv $(OBJ)
	@rmdir $(OBJ_PATH) 2> /dev/null || true
	@printf "_________________________________\n"

fclean: clean
	@rm -f $(NAME)
	@make -C libft fclean 2> /dev/null || true
	@printf "All files have been cleaned. \033[32m✔\033[0m                   \n"

re: fclean all

norme:
	@norminette $(SRC)
	@norminette $(INC_PATH)*.h

NAME = CUB3D

CC = gcc

CFLAGS = -Wall -Wextra -Werror -fsanitize=address -g

GLFW = MLX42/build/_deps/glfw-build/src/libglfw3.a

MLX = MLX42/build/libmlx42.a

LIBS = parsing/lbft/libft.a 

FLG = -framework Cocoa -framework OpenGL -framework IOKit

RM = rm -rf

SRC =	ray_casting.c player_control.c mini_map.c main.c texture.c utils.c \
		parsing/parsing.c parsing/parcing2.c \
		parsing/check1.c parsing/check2.c parsing/chyata.c \
		parsing/gnl/get_next_line.c \
		parsing/gnl/get_next_line_utils.c \


OBJ = $(SRC:.c=.o)

all : $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LIBS) $(MLX) $(FLG) $(GLFW) -o $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re : fclean all
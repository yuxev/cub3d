NAME = cub3d

CC = cc

CFLAGS =#-fsanitize=address -g

LIBS = libft/libft.a 

SRC = 

OBJ = ${SRC:.c=.o}

RM = rm -rf

all : $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) $(SRC) $(LIBS) -o $(NAME)

clean :
	$(RM) $(OBJ)

fclean : clean
	$(RM) $(NAME)

re : fclean all
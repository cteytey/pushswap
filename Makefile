CC = cc -Wall -Wextra -Werror

NAME = push_swap.a

ARCS = -ar rcs

SOURCE = libft/ft_atoi.c \
	libft/ft_memmove.c \
	libft/ft_split.c \
	libft/ft_strjoin.c \
	libft/ft_strlen.c \
	parsing/ft_parsing.c \
	parsing/is_same_number.c \
	parsing/is_valid_number.c \
	utils/sort_utils.c \
	utils/stack_utils.c \
	ft_indexizer.c \
	ft_create_chunks.c \
	algo.c

HEADER = -Ipush_swap.h

OBJ = $(SOURCE:.c=.o)

all : $(NAME) main

$(NAME) : $(OBJ)
	$(ARCS) $(NAME) $(OBJ)

clean :
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(NAME)
	rm a.out

re : fclean all

main: $(NAME)
	$(CC) $(CFLAGS) -o a.out main.c $(NAME)

.PHONY: all clean fclean re main
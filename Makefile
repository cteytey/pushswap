CC = cc -Wall -Wextra -Werror

NAME = push_swap

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
          chunks_utils.c \
          small_sort.c \
          complex_sort.c \
          main.c

HEADER = -Ipush_swap.h

OBJ = $(SOURCE:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
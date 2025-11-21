CC = cc -Wall -Wextra -Werror

NAME = push_swap.a

ARCS = -ar rcs

SOURCE = sort_utils.c \
	stack_utils.c

HEADER = -Ipush_swap.h  -I../libft/libft.h

OBJ = $(SOURCE:.c=.o)

all : $(NAME) main

$(NAME) : $(OBJ)
	make -C ../libft
	$(ARCS) $(NAME) $(OBJ)

clean :
	rm -rf $(OBJ)
	make -C ../libft clean

fclean : clean
	rm -rf $(NAME)
	make -C ../libft fclean
	rm a.out

re : fclean all

main: $(NAME)
	$(CC) $(CFLAGS) -o a.out main.c $(NAME) ../libft/libft.a

.PHONY: all clean fclean re main
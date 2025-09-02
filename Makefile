NAME = push_swap
SRC = push_swap.c input_validations.c free_memory.c error.c create_stack.c\
		  order_stack.c order_small_stack.c swap.c push.c rotate.c\
		  reverse_rotate.c 

OBJS = $(SRC:.c=.o)
LIBFT = libft.a
CFLAGS = -Wall -Wextra -Werror -g
INCLUDE = -I.

RM = rm -f

all: $(NAME) 

$(NAME): $(OBJS) 
	make -C ./libft bonus
	cp ./libft/libft.a .
	gcc $(CFLAGS) $(INCLUDE) $(OBJS) $(LIBFT) -o $(NAME)

clean:
	$(RM) $(OBJS)
	make -C libft clean

fclean: clean
	$(RM) $(NAME) libft.a

re: fclean all

.PHONY: all clean fclean re

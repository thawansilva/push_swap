NAME = push_swap
SRC = push_swap.c input_validations.c utils_functions.c create_stack.c\
		  numbers.c order_stack.c order_small_stack.c swap.c push.c rotate.c\

OBJS = $(SRC:.c=.o)
LIBFT = libft.a
CFLAGS = -Wall -Wextra -Werror -g

RM = rm -f

all: $(NAME) 

$(NAME): $(OBJS) 
	make -C ./libft bonus
	cp ./libft/libft.a .
	gcc $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

clean:
	$(RM) $(OBJS)
	make -C libft clean

fclean: clean
	$(RM) $(NAME) libft.a

re: fclean all

.PHONY: all clean fclean re

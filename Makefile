NAME = push_swap
SRC = push_swap.c input_validations.c ultils_functions.c

OBJS = $(SRC:.c=.o)
LIBFT = libft/libft.a
CFLAGS = -Wall -Wextra -Werror -g

RM = rm -f

all: $(NAME) 

$(NAME): $(OBJS) 
	make -C ./libft
	gcc $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

clean:
	$(RM) $(OBJS)
	make -C libft clean

fclean: clean
	$(RM) $(NAME) libft.a

re: fclean all

.PHONY: all clean fclean re

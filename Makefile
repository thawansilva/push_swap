NAME:=push_swap

SRC:= push_swap.c
OBJS= $(SRC:.c=.o)

LIBS:= -L. -lft -lftprintf

CFLAGS:=-Wall -Wextra -Werror -g

RM:= rm -f

all: $(NAME)

$(NAME): $(OBJS) libs
	gcc $(LIBS) $(OBJS) -o $@

%.o: %.c
	gcc $(SRC) $(CFLAGS) -I. $^ -o $@

libs: 
	make -C ./libft
	mv ./libft/libft.a .

clean:
	$(RM) $(OBJS)

fclean: clear
	$(RM) $(NAME) libft.a

re: fclean all

.PHONY: all clean fclean re

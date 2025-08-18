NAME:=push_swap

SRC:= push_swap.c
OBJS:= $(SRC:.c=.o)
LIBFTSRC:= libft
LIBS:= -L. -lft -lftprintf

CFLAGS:=-Wall -Wextra -Werror -g

RM:= rm -f

all: $(NAME)

$(NAME): $(OBJS) libs
	gcc $(LIBS) $(OBJS) -o $@

%.o: %.c
	gcc $(SRC) $(CFLAGS) -I. -I./$(LIBFTSRC) $^ -o $@

libs: 
	make -C ./libft
	cp $(LIBFTSRC)/libft.a .

clean:
	$(RM) $(OBJS)
	make -C $(LIBFTSRC) clean

fclean: clear
	$(RM) $(NAME) libft.a

re: fclean all

.PHONY: all clean fclean re

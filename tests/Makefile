NAME = push_swap_test
SRCDIR = ../
LIBDIR = $(SRCDIR)lib/libft/
INCDIR = $(SRCDIR)include $(LIBDIR)
TEST_FILES = tpush_swap.c
CFLAGS = -g -Wall -Wextra -Werror
LIB = -lft 
CPPFLAGS := $(addprefix -I, $(INCDIR)) -I.

all: $(NAME)

$(NAME): $(MAINFILE) fclean
	$(MAKE) -C $(SRCDIR)
	@cc $(TEST_FILES) $(CFLAGS) $(CPPFLAGS) -L$(LIBDIR) $(LIB) -o $@
	./$(NAME)
	@echo "Certinho ✅"

leak:
	valgrind --tool=memcheck --leak-check=full --show-leak-kinds=all --track-origins=yes --vgdb=yes --error-limit=no ./$(NAME)

clean: 
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all re fclean clean

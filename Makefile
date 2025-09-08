NAME := ./bin/push_swap
# Directories
SRCDIR := src/
OBJDIR := obj/
INCDIR := include/ lib/libft/

# Source files and Objects
SRC := main.c  input_validations.c free_memory.c error.c create_stack.c\
	   order_stack.c order_small_stack.c swap.c push.c rotate.c\
	   reverse_rotate.c refresh_stack.c moviment_stack.c stack_utils.c\
	   init_a.c init_b.c

SRC := $(SRC:%=$(SRCDIR)%)
OBJS := $(SRC:$(SRCDIR)%.c=$(OBJDIR)%.o)

# Libs
LIBS := ft
LIBS_TARGET := lib/libft/libft.a

# Flags
CC := clang
CFLAGS := -Wall -Wextra -Werror -g2 -O0
CPPFLAGS := $(addprefix -I, $(INCDIR))
LDFLAGS := $(addprefix -L, $(dir $(LIBS_TARGET)))
LDLIBS := $(addprefix -l, $(LIBS))

# Useful variables
RM := rm -f
RMDIR := rm -fr
DUP_DIR = mkdir -p $(@D)
COLOR_GREEN := \033[0;32m
END_COLOR := \033[0m

all: $(NAME) 

$(NAME): $(OBJS) $(LIBS_TARGET)
	$(CC) $(LDFLAGS) $(OBJS) $(LDLIBS) -o $(NAME)
	@echo "$(COLOR_GREEN) $(NAME) CREATED $(END_COLOR)"

$(LIBS_TARGET):
	$(MAKE) -C $(@D)

$(OBJDIR)%.o: $(SRCDIR)%.c
	$(DUP_DIR)
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

clean:
	for f in $(dir $(LIBS_TARGET)); do $(MAKE) -C $$f clean; done
	$(RM) $(OBJS)

fclean: clean
	for f in $(dir $(LIBS_TARGET)); do $(MAKE) -C $$f fclean; done
	$(RM) $(NAME) 
	$(RMDIR) $(OBJDIR)

re: fclean all

.PHONY: all clean fclean re

NAME	:= push_swap
NAME_BONUS	:=	checker
CFLAGS	:= -Wextra -Wall -Werror -g3
LIBFT	:= ./libft

HEADERS	:= -I $(LIBFT)
LIBS	:= $(LIBFT)/libft.a

SRCS	:= $(addprefix ./mandatory/, push_swap.c args_check.c binary_tree.c linked_list.c fill_stack.c\
				movements.c operations_push.c operations_reverse.c operations_rotate.c operations_swap.c \
				cost_calculation.c cost_movement.c target_position.c \
				sort_two_or_three.c sort_stack.c utils.c)

OBJS	:= ${SRCS:.c=.o}

SRCS_BONUS := $(addprefix ./bonus/, args_check_bonus.c binary_tree_bonus.c checker_bonus.c linked_list_bonus.c \
				fill_stack_bonus.c move_bonus.c movements_bonus.c utils_bonus.c)

OBJS_BONUS := ${SRCS_BONUS:.c=.o}

all: libft $(NAME)

libft:
	@make -C $(LIBFT)

$(NAME): $(OBJS)
	@$(CC) $(OBJS) $(LIBS) $(HEADERS) -o $(NAME)

$(NAME_BONUS): $(OBJS_BONUS)
	@$(CC) $(OBJS_BONUS) $(LIBS) $(HEADERS) -o $(NAME_BONUS)

%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS) && printf "Compiling: $(notdir $<)"

bonus: libft $(NAME_BONUS)

clean:
	@rm -rf $(OBJS)
	@rm -rf $(OBJS_BONUS)
	@make -C $(LIBFT) clean

fclean: clean
	@rm -rf $(NAME)
	@rm -rf $(NAME_BONUS)
	@make -C $(LIBFT) fclean

re: clean all

test2: all
	$(eval ARG = $(shell shuf -i 0-100 -n 2))
	./push_swap $(ARG) | ./checker_linux $(ARG)
	@echo -n "Instructions: "
	@./push_swap $(ARG) | wc -l

test3: all	
	$(eval ARG = $(shell shuf -i 0-100 -n 3))
	./push_swap $(ARG) | ./checker_linux $(ARG)
	@echo -n "Instructions: "
	@./push_swap $(ARG) | wc -l

test10: all	
	$(eval ARG = $(shell shuf -i 0-100 -n 10))
	./push_swap $(ARG) | ./checker_linux $(ARG)
	@echo -n "Instructions: "
	@./push_swap $(ARG) | wc -l

test100: all
	$(eval ARG = $(shell shuf -i 0-5000 -n 100))
	./push_swap $(ARG) | ./checker_linux $(ARG)
	@echo -n "Instructions: "
	@./push_swap $(ARG) | wc -l

test500: all	
	$(eval ARG = $(shell shuf -i 0-5000 -n 500))
	./push_swap $(ARG) | ./checker_linux $(ARG)
	@echo -n "Instructions: "
	@./push_swap $(ARG) | wc -l

mytest500: all	
	$(eval ARG = $(shell shuf -i 0-5000 -n 500))
	./push_swap $(ARG) | ./checker $(ARG)
	@echo -n "Instructions: "
	@./push_swap $(ARG) | wc -l

.PHONY: all, clean, fclean, re, libft
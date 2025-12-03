YELLOW = \033[33m
GREEN  = \033[32m
WHITE  = \033[37m
RESET  = \033[0m

CC = cc
CFLAGS = -Wall -Wextra -Werror -g

NAME = push_swap
NAME_BONUS = checker

SRCS = push_swap.c

SRCS_COMMON = push_swap_utils.c\
			  op_push.c\
			  op_rev_rotate.c\
			  op_rotate.c\
			  op_swap.c\
			  parse_args.c\
			  sort.c\
			  sort_utils.c\
			  stack.c\
			  stack_utils.c

SRCS_BONUS = bonus/checker.c\
			 GNL/get_next_line.h\
			 GNL/get_next_line_utils.h

OBJS = $(SRCS:.c=.o) $(SRCS_COMMON:.c=.o)
OBJS_BONUS = $(SRCS_BONUS:.c=.o) $(SRCS_COMMON:.c=.o)

LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a
FTPRINTF_DIR = ./ft_printf
FTPRINTF = $(FTPRINTF_DIR)/libftprintf.a

all: $(NAME)

bonus: $(NAME_BONUS)

$(NAME): $(OBJS)
	@$(MAKE) -C $(LIBFT_DIR)	
	@$(MAKE) -C $(FTPRINTF_DIR)	
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT) $(FTPRINTF)
	@echo "$(GREEN) Making push_swap$(RESET)"

$(NAME_BONUS): $(OBJS_BONUS)
	@$(MAKE) -C $(LIBFT_DIR)	
	@$(MAKE) -C $(FTPRINTF_DIR)	
	@$(CC) $(CFLAGS) -o $(NAME_BONUS) $(OBJS_BONUS) $(LIBFT) $(FTPRINTF)
	@echo "$(GREEN) Making checker$(RESET)"

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean: 
	@rm -f $(OBJS) $(OBJS_BONUS)
	@$(MAKE) -C $(LIBFT_DIR)	clean
	@$(MAKE) -C $(FTPRINTF_DIR)	clean
	@echo "$(GREEN)Making clean$(RESET)"

fclean: clean
	@rm -f $(NAME)
	@rm -f $(NAME_BONUS)
	@rm -f $(LIBFT)
	@rm -f $(FTPRINTF)
	@echo "$(GREEN)Making fclean$(RESET)"

# re: fclean all 
re:
	@$(MAKE) fclean
	@$(MAKE) all
	@$(MAKE) clean
	@echo "$(GREEN)Making re$(RESET)"
	
.PHONY: all bonus clean fclean re

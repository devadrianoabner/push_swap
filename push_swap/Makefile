NAME		= push_swap

CC			= cc
CFLAGS		= -Wall -Wextra -Werror

SRC_DIR		= src
INC_DIR		= include

SRCS		=	$(SRC_DIR)/main.c \
				$(SRC_DIR)/parse.c \
				$(SRC_DIR)/strategy.c \
				$(SRC_DIR)/stack_utils.c \
				$(SRC_DIR)/stack_utils2.c \
				$(SRC_DIR)/operations_push.c \
				$(SRC_DIR)/operations_swap.c \
				$(SRC_DIR)/operations_rotate.c \
				$(SRC_DIR)/operations_rrotate.c \
				$(SRC_DIR)/rotate_utils.c \
				$(SRC_DIR)/disorder.c \
				$(SRC_DIR)/sort_simple.c \
				$(SRC_DIR)/sort_simple_three.c \
				$(SRC_DIR)/sort_medium.c \
				$(SRC_DIR)/sort_medium2.c \
				$(SRC_DIR)/sort_complex.c \
				$(SRC_DIR)/sort_complex_cost.c \
				$(SRC_DIR)/sort_complex_move.c \
				$(SRC_DIR)/sort_complex_insert.c \
				$(SRC_DIR)/sort_complex_radix.c \
				$(SRC_DIR)/sort_adaptive.c \
				$(SRC_DIR)/sort_helpers1.c \
				$(SRC_DIR)/sort_helpers2.c \
				$(SRC_DIR)/sort_helpers3.c \
				$(SRC_DIR)/benchmark.c \
				$(SRC_DIR)/ft_atoi.c \
				$(SRC_DIR)/ft_nbr.c \
				$(SRC_DIR)/ft_str.c

# sort_complex_radix.c ainda nao fecha (radix_sort pela metade,
# bug com indices negativos). Enquanto isso nao for resolvido, "make"
# vai quebrar nesse arquivo. Pra testar o resto (simple/medium/complex)
# usa "make dev", que builda tudo SEM o radix.

DEV_SRCS	= $(filter-out $(SRC_DIR)/sort_complex_radix.c, $(SRCS))

OBJS		= $(SRCS:.c=.o)
DEV_OBJS	= $(DEV_SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -I $(INC_DIR) -c $< -o $@

dev: CFLAGS += -DNO_RADIX
dev: $(DEV_OBJS)
	$(CC) $(CFLAGS) $(DEV_OBJS) -o $(NAME)
	@echo "build de dev sem radix_sort ok - da pra testar simple/medium/complex"

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re dev

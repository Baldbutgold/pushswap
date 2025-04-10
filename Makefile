#------------------ Srcs & Objs -------------------#

SRCS = push_swap.c utils.c ft_atoi_push.c
OBJS = $(SRCS:.c=.o)

#----------------- Constant namings ---------------------#

CC = cc
RM = rm -f
#CFLAGS = -Wall -Werror -Wextra
LIB_INC = -Ilibft

#------------------ Library Paths ------------------#

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

#--------------------- RULES --------------------#

NAME = push_swap

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
		$(CC) $(CFLAGS) $(LIB_INC) $(OBJS) $(LIBFT) -o $(NAME)

$(LIBFT):
		@cd libft && make

%.o: %.c
		$(CC) $(CFLAGS) -c $< -o $@

clean:
		$(RM) $(OBJS)
		@cd $(LIBFT_DIR) && make clean


fclean : clean
		$(RM) $(NAME)
		@cd $(LIBFT_DIR) && make fclean

re: fclean all

.PHONY: all clean fclean re

SRCS			= ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_memchr.c ft_memcmp.c ft_strlen.c ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c ft_strncmp.c ft_strlcpy.c ft_strlcat.c ft_strnstr.c ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_striteri.c ft_putchar.c ft_puthex.c ft_putstr.c ft_putnbr.c ft_putunsigned.c ft_treat_pointer.c ft_put_pointer.c ft_printf.c get_next_line.c ft_gnl_strchr.c ft_strcmp.c free_grid.c

OBJS		= ${SRCS:.c=.o}

NAME		= libft.a

CC			= cc
RM			= rm -f
AR			= ar rcs

CFLAGS		= -Wall -Wextra -Werror

%.o: %.c
		${CC} ${CFLAGS} -c $< -o $@

all:		$(NAME)

$(NAME):	${OBJS}
			@${AR} ${NAME} ${OBJS}

clean:
			@${RM} ${OBJS}

fclean:		clean
			@${RM} $(NAME)

re:			@fclean all

.PHONY:		all clean fclean re

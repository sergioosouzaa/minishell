NAME	= minishell

SRCS	= pipex.c utils_pipex.c utils_error.c main.c

OBJS	=  $(SRCS:.c=.o)

CFLAGS	= -Wall -Wextra -Werror

.c.o:
			cc $(CFLAGS) -c $< -o $(<:.c=.o)

$(NAME):	$(OBJS)
			make -C ./src/libft
			cc $(SRCS) ./src/libft/libft.a -lreadline -o minishell

all:		$(NAME)

clean:
			rm -f $(OBJS)
			make clean -C ./src/libft

fclean:		clean
			rm -f $(NAME)
			make fclean -C ./src/libft

re:			fclean all

.PHONY:		all clean fclean re

NAME	= libftprintf.a

SRCS	= ft_printf.c ft_printf_utils.c ft_printf_utils2.c \
		  ft_printf_utils3.c ft_find.c

OBJS	=  $(SRCS:.c=.o)

CFLAGS	= -Wall -Wextra -Werror

.c.o:
			cc $(CFLAGS) -c $< -o $(<:.c=.o) -I ./ft_printf.h

$(NAME):	$(OBJS)
			ar rc $(NAME) $(OBJS)
			ranlib $(NAME)

all:		$(NAME)

clean:
			rm -f $(OBJS)

fclean:		clean
			rm -f $(NAME)

re:			fclean all

.PHONY:		all bonus clean fclean re

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sdos-san < sdos-san@student.42.rio >       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/15 10:42:20 by sdos-san          #+#    #+#              #
#    Updated: 2022/08/24 18:14:08 by sdos-san         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
RM = rm -f

FILES = ft_isalpha \
		ft_isdigit \
		ft_tolower \
		ft_isalnum \
		ft_isascii \
		ft_isprint \
		ft_strlen \
		ft_memset \
		ft_bzero  \
		ft_memcpy \
		ft_memmove \
		ft_strlcpy \
		ft_strlcat \
		ft_toupper \
		ft_toupper \
		ft_strchr \
		ft_strrchr \
		ft_strncmp \
		ft_memchr \
		ft_memcmp \
		ft_strnstr \
		ft_atoi \
		ft_calloc \
		ft_strdup \
		ft_substr \
		ft_strjoin \
		ft_strtrim \
		ft_split \
		ft_itoa \
		ft_strmapi \
		ft_striteri \
		ft_putchar_fd \
		ft_putstr_fd \
		ft_putendl_fd \
		ft_putnbr_fd \

SRCS_DIR = ./
SRCS = $(addprefix $(SRCS_DIR), $(addsuffix .c, $(FILES)))

OBJS_DIR = ./
OBJS = $(addprefix $(OBJS_DIR), $(addsuffix .o, $(FILES)))

##      PRINTF     ##
FT_PRINTF = ft_print_hex \
			ft_printf \
			ft_putnums \

PRINTF_DIR = ./printf/
PRINTF = $(addprefix $(PRINTF_DIR), $(addsuffix .c, $(FT_PRINTF)))

OBJ_PRINTF_DIR = ./printf/
OBJ_PRINTF = $(addprefix $(OBJ_PRINTF_DIR), $(addsuffix .o, $(FT_PRINTF)))

.c.o: $(SRCS) $(PRINTF)
	@$(CC) $(CFLAGS) -c -o $@ $<


$(NAME): $(OBJS) $(OBJ_PRINTF)
	@$(AR) $@ $(PRINTF_PATH) $^
	@printf "$(GREEN)Libft Compiled 😎\n"

all: $(NAME)
	
clean:
	@printf "$(YELLOW)Deleting Libft Objects...\n"
	@$(RM) $(OBJS) $(OBJ_PRINTF)
	@printf "$(GREEN)Libft Objects Deleted 😎 🗑\n"

fclean: clean
	@printf "$(YELLOW)Deleting libft.a ...\n"
	@$(RM) $(NAME)
	@printf "$(GREEN)Libft Output file Deleted 😎 🗑\n"

re: clean all

.PHONY: all clean fclean re

GREEN=\033[0;32m
YELLOW=\033[0;33m

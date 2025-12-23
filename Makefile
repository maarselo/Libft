# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mvillavi <mvillavi@student.42barcelon      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/05 16:51:09 by mvillavi          #+#    #+#              #
#    Updated: 2025/01/12 20:20:41 by mvillavi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

DIR_INCLUDE = include
OBJ_DIR = obj

DIR_FILES_LIBFT = src/libft

HEADER_LIBFT = $(DIR_INCLUDE)/libft.h

FILES_LIBFT = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
       ft_isspace.c ft_ismetachar.c ft_toupper.c ft_tolower.c ft_atoi.c ft_memcmp.c \
       ft_strlen.c ft_strlcpy.c ft_strlcat.c ft_itoa.c ft_strchr.c ft_strncmp.c \
       ft_strdup.c ft_strrchr.c ft_calloc.c ft_strjoin.c ft_memmove.c \
       ft_strtrim.c ft_substr.c ft_strmapi.c ft_strnstr.c ft_putnbr_fd.c \
       ft_bzero.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_memset.c \
       ft_memchr.c ft_striteri.c ft_memcpy.c ft_split.c \

SRCS_LIBFT = $(addprefix $(DIR_FILES_LIBFT)/, $(FILES_LIBFT))

OBJS_LIBFT = $(addprefix $(OBJ_DIR)/, $(FILES_LIBFT:.c=.o))

CC = cc
CC_LIB = ar -rcs
CFLAGS = -Wall -Werror -Wextra -Iinclude
RM = rm -rf

all: $(NAME)

$(NAME): $(OBJS_LIBFT) $(HEADER_LIBFT) Makefile
	$(CC_LIB) $(NAME) $(OBJS_LIBFT)

$(OBJ_DIR)/%.o: $(DIR_FILES_LIBFT)/%.c | $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean :
	$(RM) $(OBJ_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re


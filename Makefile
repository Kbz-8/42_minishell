# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vvaas <vvaas@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/18 10:57:27 by maldavid          #+#    #+#              #
#    Updated: 2023/07/28 20:47:23 by vvaas            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= ./minishell

SRCS	=	src/core/main.c \
			src/core/init.c \
			src/core/env.c \
			src/core/errors.c \
			src/core/memory.c \
			src/core/interactive.c \
			src/core/prompt_manager.c \
			src/core/prompt_manager2.c \
			src/utils/ft_joinfree.c \
			src/utils/ft_freesplit.c \
			src/utils/ft_strdup_malloc.c \
			src/utils/ft_changedir.c \
			src/exec/command.c \
			src/exec/ft_execve.c \
			src/exec/r_in.c \
			src/exec/r_out.c \
			src/exec/r_utils.c \
			src/exec/c_pipe.c \
			src/exec/builtin/ft_exit.c \
			src/exec/builtin/ft_cd.c \
			src/exec/builtin/ft_pwd.c \
			src/exec/builtin/ft_echo.c \
			src/exec/builtin/ft_env.c \
			src/exec/builtin/ft_export.c \
			src/exec/builtin/ft_unset.c \
			src/exec/environment.c \
			src/parser/parser.c \
			src/parser/AST/ast_visitor.c \
			src/parser/AST/ast_visitor2.c \
			src/parser/AST/sanitizer.c \
			src/parser/AST/ast.c \
			src/parser/AST/node.c \
			src/parser/AST/lexer.c \
			src/parser/AST/lexer2.c \

OBJ_DIR	= objs
OBJS	= $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))

CC		= clang
CFLAGS	= -Wall -Wextra -Werror -I third_party/libft -I include

DEBUG		?= false
MODE		=  "release"
TOOLCHAIN	?= clang

ifeq ($(TOOLCHAIN), gcc)
	CC = gcc
endif

ifeq ($(DEBUG), true)
	CFLAGS += -g -D DEBUG
	MODE = "debug"
endif

RM		= rm -rf

$(OBJ_DIR)/%.o: %.c
	@echo "\e[1;32m[compiling "$(MODE)" {"$(CC)"}...]\e[1;00m "$<
	@$(CC) $(CFLAGS) $(COPTS) -c $< -o $@

all:		libft $(NAME)

libft:
	@make -C third_party/libft

$(NAME):	$(OBJ_DIR) $(OBJS)
	@echo "\e[1;32m[linking   "$(MODE)" {"$(CC)"}...]\e[1;00m "$@
	@$(CC) -o $(NAME) $(OBJS) third_party/libft/libft.a -lreadline
	@echo "\e[1;32m[build finished]\e[1;00m"

$(OBJ_DIR):
	@mkdir -p $(sort $(addprefix $(OBJ_DIR)/, $(dir $(SRCS))))

clean:
	@$(RM) $(OBJ_DIR)

fclean:		clean
	@$(RM) $(NAME)

re:			fclean all

norminette:
	norminette | grep Error | wc -l

.PHONY:		all clean fclean re 

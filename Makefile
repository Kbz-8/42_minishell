# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vvaas <vvaas@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/18 10:57:27 by maldavid          #+#    #+#              #
#    Updated: 2023/05/31 20:15:32 by maldavid         ###   ########.fr        #
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
			src/utils/ft_joinfree.c \
			src/utils/ft_freesplit.c \
			src/exec/command.c \
			src/exec/ft_execve.c \
			src/exec/builtin/ft_exit.c \
			src/exec/builtin/ft_cd.c \
			src/exec/builtin/ft_pwd.c \
			src/exec/builtin/ft_echo.c \
			src/parser/parser.c \
			src/parser/AST/ast_visitor.c \
			src/parser/AST/ast_visitor2.c \
			src/parser/AST/sanitizer.c \
			src/parser/AST/ast.c \
			src/parser/AST/node.c \
			src/parser/AST/lexer.c \
			src/parser/AST/lexer2.c \

OBJS	= $(SRCS:.c=.o)

CC		= clang
CFLAGS	= -Wall -Wextra -Werror -I third_party/libft -I include -g

RM		= rm -f

%.o: %.c
	@echo "\e[1;32m[compiling...   ]\e[1;00m "$<
	@$(CC) $(CFLAGS) $(COPTS) -c $< -o $@

all:		libft $(NAME)

libft:
	@make -C third_party/libft

$(NAME):	$(OBJS)
	@echo "\e[1;32m[ linking ...]\e[1;00m "$@
	@$(CC) -o $(NAME) $(OBJS) third_party/libft/libft.a -lreadline
	@echo "\e[1;32m[build finished]\e[1;00m"

clean:
	@$(RM) $(OBJS)

fclean:		clean
	@$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re 

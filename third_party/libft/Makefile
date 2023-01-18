# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: maldavid <kbz_8.dev@akel-engine.com>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/20 14:27:52 by maldavid          #+#    #+#              #
#    Updated: 2023/01/05 15:37:43 by maldavid         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libft.a

SRCS	=	./string/ft_atoi.c \
			./string/ft_isalpha.c \
			./string/ft_itoa.c \
			./memory/ft_memcmp.c \
			./memory/ft_memset.c \
			./io/ft_putnbr.c \
			./string/ft_split.c \
			./string/ft_strclr.c \
			./string/ft_strdup.c \
			./string/ft_strlen.c \
			./string/ft_strndup.c \
			./string/ft_strrev.c \
			./string/ft_toupper.c \
			./memory/ft_bzero.c \
			./string/ft_isascii.c \
			./string/ft_isprint.c \
			./memory/ft_memalloc.c \
			./memory/ft_memcpy.c \
			./utils/ft_nbrlen.c \
			./io/ft_putnbr_fd.c \
			./string/ft_splits.c \
			./string/ft_strcmp.c \
			./string/ft_striteri.c \
			./string/ft_strncat.c \
			./string/ft_strnew.c \
			./string/ft_strstr.c \
			./memory/ft_calloc.c \
			./string/ft_isdigit.c \
			./string/ft_isspace.c \
			./memory/ft_memccpy.c \
			./memory/ft_memdel.c \
			./io/ft_putchar.c \
			./io/ft_putstr.c \
			./string/ft_strcat.c \
			./string/ft_strcpy.c \
			./string/ft_strlcat.c \
			./string/ft_strncmp.c \
			./string/ft_strnstr.c \
			./memory/ft_swap.c \
			./string/ft_isalnum.c \
			./string/ft_islower.c \
			./string/ft_isupper.c \
			./memory/ft_memchr.c \
			./memory/ft_nmemchr.c \
			./memory/ft_memmove.c \
			./io/ft_putchar_fd.c \
			./io/ft_putstr_fd.c \
			./string/ft_strchr.c \
			./string/ft_nstrchr.c \
			./string/ft_strdel.c \
			./string/ft_strlcpy.c \
			./string/ft_strncpy.c \
			./string/ft_strrchr.c \
			./string/ft_tolower.c \
			./string/ft_substr.c \
			./string/ft_strjoin.c \
			./io/ft_putendl_fd.c \
			./string/ft_strmapi.c \
			./string/ft_strtrim.c \
			./utils/ft_lstnew.c \
			./utils/ft_lstsize.c \
			./utils/ft_lstlast.c \
			./utils/ft_lstclear.c \
			./utils/ft_lstadd_front.c \
			./utils/ft_lstadd_back.c \
			./utils/ft_lstdelone.c \
			./utils/ft_lstiter.c \
			./utils/ft_lstmap.c \
			./string/ft_nlltoa.c \
			./io/get_next_line.c \
			./io/get_next_line_utils.c \
			./io/ft_printf.c \

OBJS	= $(SRCS:.c=.o)

CC		= gcc
CFLAGS	= -Wall -Wextra -Werror -I./

RM		= rm -f

%.o: %.c
	@echo "\e[1;32m[compiling...   ]\e[1;00m "$<
	@$(CC) $(CFLAGS) -c $< -o $@

all:	 	$(NAME)

$(NAME):	$(OBJS)
	@echo "\e[1;32m[ linking ...]\e[1;00m "$@
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)
	@echo "\e[1;32m[build finished]\e[1;00m"

clean:
	@$(RM) $(OBJS)
	@$(RM) $(OBJS_B)

fclean:		clean
	@$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re

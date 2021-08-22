# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rtournet <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/22 14:01:08 by rtournet          #+#    #+#              #
#    Updated: 2021/08/07 17:28:36 by rtournet         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libftprintf.a

CC		= gcc

FLAGS	= -Wall -Wextra -Werror

DEL		= /bin/rm -f

SRCS = $(addprefix sources/, $(FILES))
BONUS = $(addprefix bonus/, $(FBONUS))

FILES	= 	ft_printf.c \
			charac.c \
			flags_value.c \
			hexa.c \
			integer.c \
			linker.c \
			percent.c \
			pointer.c \
			string.c \
			unsigned.c \
			utils.c \
			utils_numbers.c

FBONUS	=	ft_printf_bonus.c \
			charac_bonus.c \
			flags_value_bonus.c \
			hexa_bonus.c \
			integer_bonus.c \
			linker_bonus.c \
			percent_bonus.c \
			pointer_bonus.c \
			string_bonus.c \
			unsigned_bonus.c \
			utils_bonus.c \
			utils_numbers_bonus.c

SRCS_O	= ${SRCS:.c=.o}
BONUS_O	= ${BONUS:.c=.o}
all: $(NAME)

LIBC		= ar -rcs

%.o: %.c
	${CC} ${FLAGS} -c $< -o ${<:.c=.o}

$(NAME): ${SRCS_O}
	${LIBC} $(NAME) $(SRCS_O)

bonus: $(BONUS_O)
	${LIBC} $(NAME) $(BONUS_O)

fclean: clean
	$(DEL) $(NAME) 

clean:
	$(DEL) $(SRCS_O) $(BONUS_O)

re: fclean all

.PHONY: fclean clean re all

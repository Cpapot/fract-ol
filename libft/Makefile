# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cpapot <cpapot@student.42lyon.fr >         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/08 14:44:54 by cpapot            #+#    #+#              #
#    Updated: 2022/11/28 23:19:34 by cpapot           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libft.a

SRCS	=	ft_isalpha.c ft_putnbr_fd.c ft_putendl_fd.c \
			ft_isdigit.c ft_putstr_fd.c ft_putchar_fd.c \
			ft_strmapi.c ft_striteri.c ft_isalnum.c \
			ft_substr.c ft_isascii.c ft_isprint.c \
			ft_strlen.c ft_memset.c ft_bzero.c \
			ft_memcpy.c ft_memmove.c ft_strlcpy.c \
			ft_strlcat.c ft_toupper.c ft_tolower.c \
			ft_strchr.c ft_strrchr.c ft_memchr.c \
			ft_memcmp.c ft_strnstr.c ft_atoi.c \
			ft_strncmp.c ft_calloc.c ft_strdup.c \
			ft_strtrim.c ft_split.c ft_itoa.c \
			ft_strjoin.c

SRCBONUS =	ft_lstnew.c ft_lstadd_front.c \
			ft_lstadd_back.c ft_lstsize.c ft_lstlast.c \
			ft_lstdelone.c ft_lstiter.c ft_lstclear.c \
			ft_lstmap.c

OBJBONUS	= ${SRCBONUS:.c=.o}

OBJS	= ${SRCS:.c=.o}

HEADERS = libft.h

CFLAGS = -Wall -Wextra -Werror

%.o:	%.c ${HEADERS} Makefile
	$(CC) -I ${CFLAGS} -c $< -o $@

${NAME}:	${OBJS}
	ar rcs ${NAME} ${OBJS}

all: ${NAME}

bonus:		$(OBJBONUS) ${OBJS}
	ar rcs ${NAME} ${OBJS} $(OBJBONUS)

clean:
	${RM} ${OBJS} ${OBJBONUS}

fclean:		clean
	${RM} ${NAME}

re:	fclean all

.PHONY : re all clean fclean bonus

NAME	=	Fract_ol

SRCS	=	main.c ft_create_window.c ft_convert_axis.c
			ft_create_window.c ft_is_divergent.c ft_mandelbrot

MLXSRC	= mlx/libmlx.a

LIBFTSRC = libft/libft.a ft_printf/libftprintf.a

HEADERS = Fract_ol.h
GCCFLAGS = -Wall -Wextra -Werror
FLAGS =  -framework OpenGL -framework AppKit -Lmlx -lmlx
CC = gcc -I
OBJS	= ${SRCS:.c=.o}

${NAME}:	${SRCS}	${LIBFTSRC}
	$(CC) ${GGFLAGS} ${MLXSRC} ${LIBFTSRC} ${SRCS}  ${FLAGS} -o ${NAME}
all: ${NAME}

clean:
	${RM} ${OBJS}

fclean:		clean
	${RM} ${NAME}

re:	fclean all

.PHONY : re all clean fclean

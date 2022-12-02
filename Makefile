#				______ _ _
#				|  ____(_) |
#				| |__   _| | ___  ___
#				|  __| | | |/ _ \/ __|
#				| |    | | |  __/\__ \.
#				|_|    |_|_|\___||___/

HEADERS 	=	fract_ol.h

SRCS		=	ft_graphic.c main.c \
				ft_mandelbrot.c ft_color.c\
				 printinfo.c

MLXSRC		=	libmlx.a

LIBFTSRC	=	libft.a libftprintf.a

#					Directories

MLXDIR		=	lib/mlx/

LIBFTDIR	=	lib/libft/

OBJSDIR		=	.objs/

#					Full Path

LIBFT		=	$(addprefix $(LIBFTDIR),$(LIBFTSRC))

MLX			=	$(addprefix $(MLXDIR),$(MLXSRC))

OBJS		=	$(SRCS:.c=.o)

#		 __      __        _       _     _
#		 \ \    / /       (_)     | |   | |
#		  \ \  / /_ _ _ __ _  __ _| |__ | | ___  ___
#		   \ \/ / _` | '__| |/ _` | '_ \| |/ _ \/ __|
#		    \  / (_| | |  | | (_| | |_) | |  __/\__ \.
#		     \/ \__,_|_|  |_|\__,_|_.__/|_|\___||___/

AR			=	ar rc

NAME		=	fract_ol

FLAGS		=	-framework OpenGL -framework AppKit -o

CFLAGS		=	-Wall -Wextra -Werror

CC			=	gcc

RM			=	rm -rf

MKDIR		=	mkdir -p

#				  _____       _
#				 |  __ \     | |
#				 | |__) |   _| | ___  ___
#				 |  _  / | | | |/ _ \/ __|
#				 | | \ \ |_| | |  __/\__ \.
#				 |_|  \_\__,_|_|\___||___/

all : lib ${NAME}

${NAME}:	lib ${OBJS}
	${MAKE} lib
	${CC} -I ${CFLAGS} ${FLAGS} ${LIBFT} ${MLX} ${OBJS} -o ${NAME}

%.o: ${SRCSDIR}%.c ${INCLUDES}

	$(CC) -I ${CFLAGS} -c $< -o $@

clean:
	${MAKE} clean -C ${LIBFTDIR}
	${RM} ${OBJS}

fclean:
	${RM} ${OBJS}
	${RM} ${NAME}
	${MAKE} fclean -C ${LIBFTDIR}
	${MAKE} clean -C ${MLXDIR}

re:
	${MAKE} fclean
	${MAKE} all

lib:
	${MAKE}	-C ${LIBFTDIR}
	${MAKE}	-C ${MLXDIR}

.PHONY : re all clean fclean printf lib

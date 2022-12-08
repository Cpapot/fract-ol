#				______ _ _
#				|  ____(_) |
#				| |__   _| | ___  ___
#				|  __| | | |/ _ \/ __|
#				| |    | | |  __/\__ \.
#				|_|    |_|_|\___||___/


ifeq ($(shell uname -s), Linux)
  MLXDIR	= ./minilibx-linux/
  FLAGS		+= -lX11 -lXext -L$(MLXDIR)
else
  MLXDIR	= ./mlx/
  FLAGS		+= -framework OpenGL -framework AppKit
endif


HEADERS 	=	fract_ol.h

SRCSFILE		=	ft_graphic.c main.c \
				ft_mandelbrot.c ft_color.c\
				printinfo.c ft_julia.c \
				ft_hook.c ft_newton.c \
				ft_preset.c

MLXSRC		=	libmlx.a

LIBFTSRC	=	libftprintf.a libft.a

#					Directories

HEADERSDIR	=	./inc/

SRCSDIR		=	./src/

LIBFTDIR	=	libft/

OBJSDIR		=	./.objs/

#					Full Path

HEAD		=	$(addprefix $(HEADERSDIR),$(HEADERS))

SRCS		=	$(addprefix $(SRCSDIR),$(SRCSFILE))

LIBFT		=	$(addprefix $(LIBFTDIR),$(LIBFTSRC))

MLX			=	$(addprefix $(MLXDIR),$(MLXSRC))

OBJS		=	$(SRCS:$(SRCSDIR)%.c=$(OBJSDIR)%.o)

#		 __      __        _       _     _
#		 \ \    / /       (_)     | |   | |
#		  \ \  / /_ _ _ __ _  __ _| |__ | | ___  ___
#		   \ \/ / _` | '__| |/ _` | '_ \| |/ _ \/ __|
#		    \  / (_| | |  | | (_| | |_) | |  __/\__ \.
#		     \/ \__,_|_|  |_|\__,_|_.__/|_|\___||___/

AR			=	ar rc

NAME		=	fract_ol

CFLAGS		=	-Wall -Wextra -Werror -O3

CC			=	gcc

RM			=	rm -rf

MKDIR		=	mkdir -p

#				  _____       _
#				 |  __ \     | |
#				 | |__) |   _| | ___  ___
#				 |  _  / | | | |/ _ \/ __|
#				 | | \ \ |_| | |  __/\__ \.
#				 |_|  \_\__,_|_|\___||___/

all : ${NAME}

${NAME}:	${OBJS} Makefile
	${MAKE} lib
	${CC} ${OBJS} ${LIBFT} ${MLX} ${FLAGS} -o ${NAME}

$(OBJSDIR)%.o: ${SRCSDIR}%.c ${HEAD}
	$(CC) ${CFLAGS} -c $< -o $@ -I$(HEADERSDIR)

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

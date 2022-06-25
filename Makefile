SRCS	=	main.c \

OBJS	=	${SRCS:.c=.o}
INCL	=	-I./includes -I./libft -I./minilibx-linux

NAME	=	so_long
CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror -g3

RM		=	rm -f

LIBFT	=	libft/libft.a
LIBMLX	=   minilibx-linux/libmlx_Linux.a
MLXUTILS=	-lmlx -lbsd -lX11 -lXext

.c.o:
				${CC} ${CFLAGS} ${INCL} -c $< -o ${<:.c=.o}

all:		${NAME}
bonus:		${NAME}

$(NAME):	${OBJS} ${LIBFT} ${LIBMLX}
				${CC} -o ${NAME} ${OBJS} ${LIBFT} ${LIBMLX} ${MLXUTILS}

$(LIBFT):
				$(MAKE) -C libft all

$(LIBMLX):
				$(MAKE) -C minilibx-linux all

clean:
				${RM} ${OBJS}

fclean:		clean
				${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re bonus
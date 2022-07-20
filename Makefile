SRCS	=	src/display_assets.c \
			src/free_all.c \
			src/load_assets.c \
			src/map_parsing.c \
			src/movements.c \
			src/so_long.c \
			src/utils.c \
			src/verif_map.c \

BONUS	=	bonus/display_assets_bonus.c \
			bonus/free_all_bonus.c \
			bonus/load_assets_bonus.c \
			bonus/map_parsing_bonus.c \
			bonus/movements_bonus.c \
			bonus/so_long_bonus.c \
			bonus/utils_bonus.c \
			bonus/verif_map_bonus.c \
			bonus/animation_bonus.c \

OBJS	=	${SRCS:.c=.o}
OBJS_BONUS	=	${BONUS:.c=.o}
INCL	=	-I./includes -I./libft/includes -I./minilibx-linux

NAME	=	so_long
NAME_BONUS = so_long_bonus
CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror -g3

RM		=	rm -f

LIBFT_PATH = libft/
LIBFT	=	libft/libft.a
LIBMLX	=   minilibx-linux/libmlx_Linux.a
MLXUTILS=	-lm -lbsd -lX11 -lXext

.c.o:
					${CC} ${CFLAGS} ${INCL} -c $< -o ${<:.c=.o}

all:			${NAME}

bonus:			$(NAME_BONUS)

$(NAME):		${OBJS} ${LIBFT} ${LIBMLX} 
					${CC} -o ${NAME} ${OBJS} ${LIBFT} ${LIBMLX} ${MLXUTILS}

$(NAME_BONUS):	${OBJS_BONUS} ${LIBFT} ${LIBMLX} 
					${CC} -o ${NAME_BONUS} ${OBJS_BONUS} ${LIBFT} ${LIBMLX} ${MLXUTILS}

$(LIBFT):
					$(MAKE) -C libft all

$(LIBMLX):
					$(MAKE) -C minilibx-linux all

clean:
					${RM} ${OBJS}

clean_bonus:
					${RM} ${OBJS_BONUS}

fclean:			clean
					$(MAKE) fclean -C ${LIBFT_PATH}
					${RM} ${NAME}

fclean_bonus:	clean_bonus
					$(MAKE) fclean -C ${LIBFT_PATH}
					${RM} ${NAME_BONUS}

re:				fclean all

re_bonus:		fclean_bonus bonus

.PHONY:			all clean clean_bonus fclean fclean_bonus re re_bonus
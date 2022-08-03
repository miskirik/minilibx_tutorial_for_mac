NAME = tutorial

SRCS = $(tutorial.c)
OBJS = $(SRCS:.c=.o)

LIBFT_DIR	=	libft

MLX_DIR	=	minilibx

CC	=	gcc
CFLAGS	=	-Wall -Wextra #-Werror
MFLAGS	=	./minilibx ./minilibx/libmlx.a ./libft/libft.a \
			./ft_printf/libftprintf.a -framework OpenGL -framework Appkit

all:	$(NAME)

$(NAME): $(OBJS)
		make -C ./libft
		make -C ./minilibx
		make -C ./ft_printf
		gcc -o $(NAME) tutorial2.c -I $(MFLAGS) $(CFLAGS)

fclean: clean
		${RM} ./libft/*.a
		${RM} ./minilibx/*.a
		${RM} ./ft_printf/*.a
		${RM} $(NAME)
clean:
		${RM} ./libft/*.o
		${RM} ./minilibx/*.o
		${RM} ./ft_printf/*.o

re:		fclean all

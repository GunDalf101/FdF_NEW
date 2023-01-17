NAME = fdf
SRCS = coolorspal.c \
	fdf.c \
	draw_pixels.c \
	antileak.c \
	map_reader.c \
	mat_init.c \
	transformations.c\
	views.c

OBJS = $(SRCS:.c=.o)
INCS = fdf.h
LIBFT = libft/libft.a
GNL = gnl/gnl.a
PRINTF = ft_printf/libftprintf.a
LINEAR = linear_alg/linear_alg.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror
MINIFLAGS = -lmlx -framework OpenGL -framework AppKit

all: $(NAME)

$(NAME):$(OBJS)
	make -C libft
	make -C linear_alg
	make -C gnl
	make -C ft_printf
	$(CC) -o $@ $(OBJS) $(LIBFT) $(GNL) $(PRINTF) $(LINEAR) $(MINIFLAGS)

%.o: %.c $(INCS)
	$(CC) -c $(CFLAGS) $<

clean:
	make -C libft clean
	make -C linear_alg clean
	make -C gnl clean
	make -C ft_printf clean
	rm -f $(OBJS)

fclean: clean
	make -C libft fclean
	make -C linear_alg fclean
	make -C gnl fclean
	make -C ft_printf fclean
	rm -f client server client_bonus server_bonus

re: fclean all

.PHONY: all bonus clean fclean re
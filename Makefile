NAME = fdf
SRCS = coolorspal.c \
	fdf.c \
	draw_pixels.c \
	antileak.c \
	map_reader.c \
	mat_init.c \
	transformations.c\
	views.c \
	addons.c \
	utils.c \
	battleground.c
SRCS_BONUS = $(SRCS:%.c=fdf_bonus/%_bonus.c)

OBJS = $(SRCS:%.c=%.o)
OBJS_BONUS = $(OBJS:%.o=fdf_bonus/%_bonus.o)
INCS = fdf.h
LIBFT = libft/libft.a
GNL = gnl/gnl.a
PRINTF = ft_printf/libftprintf.a
LINEAR = linear_alg/linear_alg.a

CC = cc
CFLAGS = -Wall -Wextra -Werror
MINIFLAGS = -lmlx -framework OpenGL -framework AppKit

all: $(NAME)

$(NAME):$(OBJS)
	make -C libft
	make -C linear_alg
	make -C gnl
	make -C ft_printf
	$(CC) -o $@ $(OBJS) $(LIBFT) $(GNL) $(PRINTF) $(LINEAR) $(MINIFLAGS)

bonus: $(OBJS_BONUS)
	make -C libft
	make -C linear_alg
	make -C gnl
	make -C ft_printf
	$(CC) -o $@ $(OBJS_BONUS) $(LIBFT) $(GNL) $(PRINTF) $(LINEAR) $(MINIFLAGS)

OBJS: $(SRCS) $(INCS)
	$(CC) -c $(CFLAGS) $<

OBJS_BONUS: $(SRCS_BONUS) $(INCS)
	$(CC) -c $(CFLAGS) $<

clean:
	make -C libft clean
	make -C linear_alg clean
	make -C gnl clean
	make -C ft_printf clean
	rm -f $(OBJS) $(OBJS_BONUS)

fclean: clean
	make -C libft fclean
	make -C linear_alg fclean
	make -C gnl fclean
	make -C ft_printf fclean
	rm -f $(NAME) bonus

re: fclean all

.PHONY: all bonus clean fclean re
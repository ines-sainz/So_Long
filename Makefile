# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: isainz-r <isainz-r@student.42madrid>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/02 11:55:04 by isainz-r          #+#    #+#              #
#    Updated: 2024/06/13 11:00:59 by isainz-r         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= so_long
NAME_BONUS	= so_long_bonus
CC			= gcc
CFLAGS		= -Wall -Werror -Wextra -I/src -I/usr/include -Imlx_linux -g3 -I .
MLX_FLAGS	= -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm 
MLX_FLAGS  += -lz

SRCS		=	ft_so_long.c ft_check_map.c ft_check_caracters.c \
				ft_draw_map.c ft_moves.c ft_putstr_fd.c \
				ft_libft2.c main.c
SRCS_BONUS	=	src_bonus/ft_check_caracters_bonus.c \
				src_bonus/ft_animation_bonus.c \
				src_bonus/ft_check_map_bonus.c src_bonus/ft_draw_map_bonus.c \
				src_bonus/ft_libft2_bonus.c src_bonus/ft_moves_bonus.c \
				src_bonus/ft_putstr_fd_bonus.c src_bonus/ft_so_long_bonus.c \
				src_bonus/main_bonus.c

OBJS		=	$(SRCS:.c=.o)
OBJS_BONUS	=	$(SRCS_BONUS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) mlx_linux
	$(MAKE) -C libft
	$(MAKE) -C mlx_linux
	$(CC) $(CFLAGS) $(OBJS) -L libft -lft $(MLX_FLAGS) -o $(NAME)

bonus: $(NAME_BONUS)

$(NAME_BONUS) : $(OBJS_BONUS)
	$(MAKE) -C libft
	$(MAKE) -C mlx_linux
	$(CC) $(CFLAGS) $(OBJS_BONUS) -L libft -lft $(MLX_FLAGS) -o $(NAME_BONUS)

clean:
	$(MAKE) -C libft clean
	$(MAKE) -C mlx_linux clean
	rm -f	$(OBJS)
	rm -f	$(OBJS_BONUS)

fclean: clean
	$(MAKE) -C libft fclean
	rm -f	mlx_linux/libmlx.a
	rm -f	$(NAME)
	rm -f	$(NAME_BONUS)

re: fclean all

.PHONY: clean fclean re all bonus

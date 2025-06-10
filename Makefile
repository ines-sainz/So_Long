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

# Main executable name for mandatory part
NAME		= so_long

# Executable name for bonus part
NAME_BONUS	= so_long_bonus

# Compiler to use
CC			= cc

# Compiler flags: warnings, errors, extra warnings, include directories, debug info
CFLAGS		= -Wall -Werror -Wextra -I/src -I/usr/include -Imlx_linux -g3 -I .

# MiniLibX linking flags: library path, X11 libraries, math library
MLX_FLAGS	= -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm 

# Additional compression library flag
MLX_FLAGS  += -lz

# Source files for mandatory part
SRCS		=	ft_so_long.c ft_check_map.c ft_check_caracters.c \
				ft_draw_map.c ft_moves.c ft_putstr_fd.c \
				ft_add.c main.c

# Source files for bonus part (located in src_bonus directory)
SRCS_BONUS	=	src_bonus/ft_check_caracters_bonus.c \
				src_bonus/ft_animation_bonus.c \
				src_bonus/ft_check_map_bonus.c src_bonus/ft_draw_map_bonus.c \
				src_bonus/ft_add_bonus.c src_bonus/ft_moves_bonus.c \
				src_bonus/ft_putstr_fd_bonus.c src_bonus/ft_so_long_bonus.c \
				src_bonus/main_bonus.c

# Object files generated from mandatory source files
OBJS		=	$(SRCS:.c=.o)

# Object files generated from bonus source files
OBJS_BONUS	=	$(SRCS_BONUS:.c=.o)

# Default target - builds the mandatory version
all: $(NAME)

# Rule to build the main executable
$(NAME): $(OBJS) mlx_linux
	$(MAKE) -C libft		# Compile libft library
	$(MAKE) -C mlx_linux		# Compile MiniLibX library
	# Link all object files with libraries to create final executable
	$(CC) $(CFLAGS) $(OBJS) -L libft -lft $(MLX_FLAGS) -o $(NAME)

# Target to build bonus version
bonus: $(NAME_BONUS)

# Rule to build the bonus executable
$(NAME_BONUS) : $(OBJS_BONUS)
	$(MAKE) -C libft		# Compile libft library
	$(MAKE) -C mlx_linux		# Compile MiniLibX library
	# Link all bonus object files with libraries to create bonus executable
	$(CC) $(CFLAGS) $(OBJS_BONUS) -L libft -lft $(MLX_FLAGS) -o $(NAME_BONUS)

# Remove object files and clean sub-libraries
clean:
	$(MAKE) -C libft clean		# Clean libft object files
	$(MAKE) -C mlx_linux clean	# Clean MiniLibX object files
	rm -f	$(OBJS)			# Remove mandatory object files
	rm -f	$(OBJS_BONUS)		# Remove bonus object files

# Full clean - removes all generated files
fclean: clean
	$(MAKE) -C libft fclean		# Fully clean libft (remove library file)
	rm -f	mlx_linux/libmlx.a	# Remove MiniLibX library file
	rm -f	$(NAME)			# Remove mandatory executable
	rm -f	$(NAME_BONUS)		# Remove bonus executable

# Rebuild everything from scratch
re: fclean all

# Declare phony targets (targets that don't create files with same name)
.PHONY: clean fclean re all bonus

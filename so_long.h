/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isainz-r <isainz-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 11:59:59 by isainz-r          #+#    #+#             */
/*   Updated: 2024/06/10 20:22:22 by isainz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx_linux/mlx.h>
# include "libft/libft.h"
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdint.h>

# define UP  65362
# define DOWN  65364
# define LEFT 65361
# define RIGHT 65363
# define ESC 65307

typedef struct s_game
{
	void	*mlx;
	void	*mlx_win;
	char	**map;
	char	**map_copy;
	char	*map_one_line;
	int		num_player;
	int		num_collectibles;
	int		num_exit;
	int		x_player;
	int		y_player;
	int		moves;
	int		map_width;
	int		map_height;
	void	*wall;
	void	*floor;
	void	*player;
	void	*collectibles;
	void	*exit;
}	t_game;

int		ft_error(int i, t_game *game);
int		ft_check_map(t_game *game, char *argv);
void	ft_free_map(t_game *game);
int		ft_check_characters(t_game *game);
int		ft_check_path(t_game *game);
void	ft_free_map_copy(t_game *game);
int		ft_so_long(t_game *game);
void	ft_print_map(t_game *game);
size_t	ft_strlen2(const char *s);
char	*ft_strjoin2(char const *s1, char const s2);
char	*ft_add(char *s1, char *s2);
void	ft_draw_map(t_game *game);
void	ft_draw_images(t_game *game, char c, int i, int j);
int		ft_destroy_window(t_game *game);
void	ft_moves(int key, t_game *game);
void	ft_putnbr(int number);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isainz-r <isainz-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 16:15:15 by isainz-r          #+#    #+#             */
/*   Updated: 2024/06/07 11:45:14 by isainz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_draw_images(t_game *game, char c, int i, int j)
{
	if (c == '0')
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->floor,
			j * 64, i * 64);
	if (c == '1')
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->wall,
			j * 64, i * 64);
	if (c == 'C')
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->collectibles,
			j * 64, i * 64);
	if (c == 'E')
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->exit,
			j * 64, i * 64);
	if (c == 'P')
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->player,
			j * 64, i * 64);
}

int	ft_load_images(t_game *game)
{
	int	x;
	int	y;

	game->wall = mlx_xpm_file_to_image(game->mlx, "textures/1.xpm", &x, &y);
	game->player = mlx_xpm_file_to_image(game->mlx, "textures/P.xpm", &x, &y);
	game->floor = mlx_xpm_file_to_image(game->mlx, "textures/0.xpm", &x, &y);
	game->collectibles = mlx_xpm_file_to_image(game->mlx,
			"textures/C.xpm", &x, &y);
	game->exit = mlx_xpm_file_to_image(game->mlx, "textures/E.xpm", &x, &y);
	if (game->wall && game->player && game->floor && game->collectibles
		&& game->exit)
		return (0);
	return (1);
}

void	ft_draw_map(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (ft_load_images(game) == 1)
		ft_destroy_window(game);
	while (i < game->map_height)
	{
		while (j < game->map_width)
		{
			ft_draw_images(game, game->map[i][j], i, j);
			j++;
		}
		i++;
		j = 0;
	}
}

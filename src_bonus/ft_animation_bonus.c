/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_animation_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isainz-r <isainz-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 17:15:06 by isainz-r          #+#    #+#             */
/*   Updated: 2024/06/15 13:34:49 by isainz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_animation_enemy(t_game *game, int i, int j, int k)
{
	if (k < 4000)
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->enemy1,
			j * 64, i * 64);
	else if (k < 8000)
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->enemy2,
			j * 64, i * 64);
	else if (k < 12000)
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->enemy3,
			j * 64, i * 64);
	else
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->enemy4,
			j * 64, i * 64);
}

int	ft_animations(t_game *game)
{
	int			i;
	int			j;
	static int	enemy;

	i = 0;
	if (!enemy)
		enemy = 0;
	while (i < game->map_height)
	{
		j = 0;
		while (j < game->map_width)
		{
			if (game->map[i][j] == 'X')
				ft_animation_enemy(game, i, j, enemy);
			j++;
		}
		i++;
	}
	enemy++;
	if (enemy == 16000)
		enemy = 0;
	return (0);
}

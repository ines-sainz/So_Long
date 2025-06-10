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

/**
 * @brief Renders enemy animation frame based on animation counter.
 * 
 * This function displays different enemy sprites in sequence to create
 * an animation effect. The sprite selection is based on the animation
 * counter value k, cycling through 4 different enemy images.
 * 
 * @param game Pointer to the game structure containing display data
 * @param i Row position on the map grid
 * @param j Column position on the map grid  
 * @param k Animation counter determining which sprite to display
 * @return void
 */
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

/**
 * @brief Updates and renders all enemy animations on the game map.
 * 
 * This function iterates through the entire game map, finds enemy
 * positions marked with 'X', and calls the animation function for each.
 * It maintains a static counter for animation timing that cycles from
 * 0 to 15999.
 * 
 * @param game Pointer to the game structure containing map and display data
 * @return int Always returns 0
 */
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

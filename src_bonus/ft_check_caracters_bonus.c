/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_caracters_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isainz-r <isainz-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 12:23:54 by isainz-r          #+#    #+#             */
/*   Updated: 2024/06/10 20:18:32 by isainz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_flood_fill(t_game *game, int x, int y)
{
	if (game->map_copy[x][y] && (game->map_copy[x][y] != '1')
		&& game->map_copy[x][y] != 'X')
	{
		game->map_copy[x][y] = '1';
		ft_flood_fill(game, x + 1, y);
		ft_flood_fill(game, x - 1, y);
		ft_flood_fill(game, x, y + 1);
		ft_flood_fill(game, x, y - 1);
	}
}

int	ft_check_path(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	ft_flood_fill(game, game->x_player, game->y_player);
	while (game->map_copy[i])
	{
		j = 0;
		while (game->map_copy[i][j])
		{
			if (game->map_copy[i][j] == 'C' || game->map_copy[i][j] == 'E')
				return (ft_error(0, game));
			j++;
		}
		i++;
	}
	ft_free_map_copy(game);
	return (0);
}

int	ft_char_organizer(t_game *game, char c, int i, int j)
{
	if (c != '1' && c != '0' && c != 'P' && c != 'C' && c != 'E' && c != 'X')
		return (ft_error(4, game));
	if ((i == 0 || i == game->map_height - 1 || j == 0
			|| j == game->map_width - 1) && (c != '1'))
		return (ft_error(5, game));
	if (c == 'C')
		game->num_collectibles++;
	if (c == 'P')
	{
		game->num_player++;
		if (game->num_player != 1)
			return (ft_error(4, game));
		game->x_player = i;
		game->y_player = j;
	}
	if (c == 'E')
	{
		game->num_exit++;
		if (game->num_exit != 1)
			return (ft_error(4, game));
	}
	return (0);
}

int	ft_check_characters(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (game->map[i])
	{
		while (game->map[i][j])
		{
			if (ft_char_organizer(game, game->map[i][j], i, j) == 1)
				return (1);
			if (game->map[i][j] == 'X')
				game->num_enemy++;
			j++;
		}
		i++;
		j = 0;
	}
	if (game->num_collectibles == 0 || game->num_exit == 0
		|| game->num_player == 0 || game->num_enemy == 0)
		return (ft_error(4, game));
	return (0);
}

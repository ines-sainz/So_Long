/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_caracters.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isainz-r <isainz-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 12:23:54 by isainz-r          #+#    #+#             */
/*   Updated: 2024/06/10 20:18:32 by isainz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/**
 * @brief Performs flood fill algorithm to mark reachable tiles.
 * 
 * This recursive function implements a flood fill algorithm starting from
 * the given coordinates. It marks all reachable non-wall tiles by setting
 * them to '1' in the map copy, effectively identifying all areas accessible
 * from the starting position.
 * 
 * @param game Pointer to the game structure containing the map copy
 * @param x Row coordinate for the current flood fill position
 * @param y Column coordinate for the current flood fill position
 */
void	ft_flood_fill(t_game *game, int x, int y)
{
	if (game->map_copy[x][y] && game->map_copy[x][y] != '1')
	{
		game->map_copy[x][y] = '1';
		ft_flood_fill(game, x + 1, y);
		ft_flood_fill(game, x - 1, y);
		ft_flood_fill(game, x, y + 1);
		ft_flood_fill(game, x, y - 1);
	}
}

/**
 * @brief Validates that all collectibles and exits are reachable.
 * 
 * This function uses flood fill starting from the player position to
 * determine reachability, then checks if any collectibles ('C') or exits
 * ('E') remain unmarked. If unreachable items are found, it indicates an
 * invalid path configuration.
 * 
 * @param game Pointer to the game structure containing map data
 * @return 0 if all items are reachable, error code if path is invalid
 */
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

/**
 * @brief Validates individual map characters and handles game element counts.
 * 
 * This function checks if a character is valid for the game map, ensures
 * border tiles are walls, and manages counters for game elements. It also
 * validates that there is exactly one player and one exit, storing the
 * player's position for later use.
 * 
 * @param game Pointer to the game structure for element counting
 * @param c Character to validate from the map
 * @param i Row index of the character in the map
 * @param j Column index of the character in the map
 * @return 0 if character is valid, error code if invalid
 */
int	ft_char_organizer(t_game *game, char c, int i, int j)
{
	if (c != '1' && c != '0' && c != 'P' && c != 'C' && c != 'E')
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

/**
 * @brief Validates all characters in the game map and required elements.
 * 
 * This function iterates through every character in the map, validating
 * each one using ft_char_organizer. After processing all characters, it
 * ensures that the map contains at least one collectible, exactly one
 * exit, and exactly one player.
 * 
 * @param game Pointer to the game structure containing the map to validate
 * @return 0 if all characters and requirements are valid, 1 on error
 */
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
			j++;
		}
		i++;
		j = 0;
	}
	if (game->num_collectibles == 0 || game->num_exit == 0
		|| game->num_player == 0)
		return (ft_error(4, game));
	return (0);
}

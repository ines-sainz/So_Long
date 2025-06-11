/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_moves.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isainz-r <isainz-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 18:34:49 by isainz-r          #+#    #+#             */
/*   Updated: 2024/06/24 19:06:55 by isainz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/**
 * @brief Restores exit tile at previous player position
 * 
 * Places the exit character back on the map and redraws it when the player
 * moves away from an exit tile, based on movement direction.
 * 
 * @param game Pointer to the game structure containing map and graphics data
 * @param key Key code indicating movement direction
 * @param i Current row position of the player
 * @param j Current column position of the player
 */
void	ft_put_exit(t_game *game, int key, int i, int j)
{
	if (key == UP)
	{
		game->map[++i][j] = 'E';
		ft_draw_images(game, game->map[i][j], i, j);
		i--;
	}
	if (key == DOWN)
	{
		game->map[--i][j] = 'E';
		ft_draw_images(game, game->map[i][j], i, j);
		i++;
	}
	if (key == LEFT)
	{
		game->map[i][++j] = 'E';
		ft_draw_images(game, game->map[i][j], i, j);
		j--;
	}
	if (key == RIGHT)
	{
		game->map[i][--j] = 'E';
		ft_draw_images(game, game->map[i][j], i, j);
		j++;
	}
}

/**
 * @brief Handles special tile interactions during player movement
 * 
 * Manages collectible pickup, exit restoration, and win condition checking
 * when player moves to non-floor tiles.
 * 
 * @param game Pointer to the game structure containing game state
 * @param key Key code indicating movement direction
 * @param i Row position where player is moving to
 * @param j Column position where player is moving to
 * @return 1 if exit was restored, 0 otherwise
 */
int	ft_no_floor(t_game *game, int key, int i, int j)
{
	if (game->map[i][j] == 'C')
		game->num_collectibles--;
	if (game->num_exit == 0)
	{
		ft_put_exit(game, key, i, j);
		game->num_exit = 1;
		return (1);
	}
	if (game->map[i][j] == 'E')
	{
		if (game->num_collectibles == 0)
		{
			write(1, "YOU HAVE WON!!!!!\n", 18);
			ft_destroy_window(game);
		}
		else
			game->num_exit = 0;
	}
	return (0);
}

/**
 * @brief Executes player movement and updates game state
 * 
 * Increments move counter, clears old position, updates player coordinates,
 * handles tile interactions, and redraws player at new position.
 * 
 * @param key Key code indicating movement direction
 * @param game Pointer to the game structure containing all game data
 */
void	ft_moves(int key, t_game *game)
{
	game->moves++;
	write(1, "Moves: ", 7);
	ft_putnbr_fd(game->moves, 1);
	write(1, "\n", 1);
	game->map[game->x_player][game->y_player] = '0';
	ft_draw_images(game, game->map[game->x_player][game->y_player],
		game->x_player, game->y_player);
	if (key == RIGHT)
		game->y_player++;
	if (key == LEFT)
		game->y_player--;
	if (key == UP)
		game->x_player--;
	if (key == DOWN)
		game->x_player++;
	ft_no_floor(game, key, game->x_player, game->y_player);
	game->map[game->x_player][game->y_player] = 'P';
	ft_draw_images(game, game->map[game->x_player][game->y_player],
		game->x_player, game->y_player);
}

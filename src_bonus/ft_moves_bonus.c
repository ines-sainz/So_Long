/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_moves_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isainz-r <isainz-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 18:34:49 by isainz-r          #+#    #+#             */
/*   Updated: 2024/06/08 10:56:10 by isainz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

/**
 * @brief Displays the move counter on the game window.
 * 
 * This function renders the current number of moves in the top-left corner
 * of the game window. It first draws wall images as background, then converts
 * the move count to a string and displays it with a custom font.
 * 
 * @param game Pointer to the game structure containing move count and MLX data
 */
void	ft_moves_in_win(t_game *game)
{
	char	*str;
	char	*str_aux;

	mlx_put_image_to_window(game->mlx, game->mlx_win, game->wall,
		0 * 64, 0 * 64);
	mlx_put_image_to_window(game->mlx, game->mlx_win, game->wall,
		1 * 64, 0 * 64);
	str_aux = ft_itoa(game->moves);
	str = ft_strjoin("Moves:", str_aux);
	mlx_set_font(game->mlx, game->mlx_win, "12x24romankana");
	mlx_string_put(game->mlx, game->mlx_win, 20, 30, 0x0FFB6C1, str);
	free(str_aux);
	free(str);
}

/**
 * @brief Redraws the exit tile after player movement.
 * 
 * This function restores the exit ('E') tile at the position the player just
 * vacated, based on the movement direction. It updates the map array and
 * redraws the exit image at the appropriate coordinates.
 * 
 * @param game Pointer to the game structure containing map and image data
 * @param key Movement key pressed (UP, DOWN, LEFT, RIGHT)
 * @param i Row coordinate of the player's current position
 * @param j Column coordinate of the player's current position
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
 * @brief Handles non-floor tile interactions and win condition checks.
 * 
 * This function processes what happens when the player moves to a tile that
 * isn't a floor. It decrements collectibles when picked up, manages exit
 * visibility, and checks for win conditions when all collectibles are
 * collected and the player reaches the exit.
 * 
 * @param game Pointer to the game structure
 * @param key Movement key pressed for exit restoration
 * @param i Row coordinate of the player's new position
 * @param j Column coordinate of the player's new position
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
 * @brief Checks for enemy collision and handles game over condition.
 * 
 * This function verifies if the player's next move would result in a
 * collision with an enemy ('X'). If a collision is detected in any direction,
 * it displays a game over message and destroys the game window.
 * 
 * @param key Movement key pressed (UP, DOWN, LEFT, RIGHT)
 * @param game Pointer to the game structure containing player position and map
 */
void	ft_enemy(int key, t_game *game)
{
	if (key == RIGHT && game->map[game->x_player][game->y_player + 1] == 'X')
	{
		write(1, "YOU LOOSE!!! :(\n", 17);
		ft_destroy_window(game);
	}
	else if (key == LEFT
		&& game->map[game->x_player][game->y_player - 1] == 'X')
	{
		write(1, "YOU LOOSE!!! :(\n", 17);
		ft_destroy_window(game);
	}
	else if (key == UP
		&& game->map[game->x_player - 1][game->y_player] == 'X')
	{
		write(1, "YOU LOOSE!!! :(\n", 17);
		ft_destroy_window(game);
	}
	else if (key == DOWN
		&& game->map[game->x_player + 1][game->y_player] == 'X')
	{
		write(1, "YOU LOOSE!!! :(\n", 17);
		ft_destroy_window(game);
	}
}

/**
 * @brief Handles player movement and game state updates.
 * 
 * This function processes a player move by checking for enemy collisions,
 * incrementing the move counter, updating the player's position on the map,
 * and redrawing the affected tiles. It also handles special tile interactions
 * and updates the move counter display.
 * 
 * @param key Movement key pressed (UP, DOWN, LEFT, RIGHT)
 * @param game Pointer to the game structure containing all game data
 */
void	ft_moves(int key, t_game *game)
{
	ft_enemy(key, game);
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
	ft_moves_in_win(game);
}

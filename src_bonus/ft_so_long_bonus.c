/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_so_long_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isainz-r <isainz-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 16:55:54 by isainz-r          #+#    #+#             */
/*   Updated: 2024/06/24 09:31:22 by isainz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

/**
 * @brief Frees all loaded game images from memory.
 * 
 * This function safely destroys all MLX image structures that were loaded
 * for the game, including walls, floors, collectibles, exit, player, and
 * enemy animation frames. It checks for NULL pointers before destroying
 * each image to prevent segmentation faults.
 * 
 * @param game Pointer to the game structure containing image pointers
 */
void	ft_free_images(t_game *game)
{
	if (game->wall != NULL)
		mlx_destroy_image(game->mlx, game->wall);
	if (game->floor != NULL)
		mlx_destroy_image(game->mlx, game->floor);
	if (game->collectibles != NULL)
		mlx_destroy_image(game->mlx, game->collectibles);
	if (game->exit != NULL)
		mlx_destroy_image(game->mlx, game->exit);
	if (game->player != NULL)
		mlx_destroy_image(game->mlx, game->player);
	if (game->enemy1 != NULL)
		mlx_destroy_image(game->mlx, game->enemy1);
	if (game->enemy2)
		mlx_destroy_image(game->mlx, game->enemy2);
	if (game->enemy3)
		mlx_destroy_image(game->mlx, game->enemy3);
	if (game->enemy4)
		mlx_destroy_image(game->mlx, game->enemy4);
}

/**
 * @brief Properly destroys the game window and cleans up all resources.
 * 
 * This function handles the complete cleanup process when the game ends.
 * It calls error handling, destroys the MLX window, frees all images,
 * destroys the display connection, frees the MLX instance, and exits
 * the program.
 * 
 * @param game Pointer to the game structure containing MLX data
 * @return Always returns 0 (though function exits before returning)
 */
int	ft_destroy_window(t_game *game)
{
	ft_error(0, game);
	mlx_destroy_window(game->mlx, game->mlx_win);
	ft_free_images(game);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	exit(0);
	return (0);
}

/**
 * @brief Handles keyboard input and player movement validation.
 * 
 * This function processes keyboard events and validates movement before
 * executing it. It checks if the target position is not a wall ('1')
 * before allowing movement in any direction. It also handles the escape
 * key for quitting the game.
 * 
 * @param key Key code of the pressed key
 * @param game Pointer to the game structure containing map and player data
 * @return Always returns 0
 */
int	ft_key(int key, t_game *game)
{
	if (key == RIGHT && game->map[game->x_player][game->y_player + 1] != '1')
		ft_moves(key, game);
	else if (key == LEFT
		&& game->map[game->x_player][game->y_player - 1] != '1')
		ft_moves(key, game);
	else if (key == UP
		&& game->map[game->x_player - 1][game->y_player] != '1')
		ft_moves(key, game);
	else if (key == DOWN
		&& game->map[game->x_player + 1][game->y_player] != '1')
		ft_moves(key, game);
	else if (key == ESC)
		ft_destroy_window(game);
	return (0);
}

/**
 * @brief Initializes the MLX system and starts the game loop.
 * 
 * This function sets up the MLX graphics system, validates screen size
 * compatibility, creates the game window, draws the initial map, and
 * establishes event hooks for keyboard input and window closing. It then
 * starts the main game loop with animations.
 * 
 * @param game Pointer to the game structure containing all game data
 * @return 0 on success, error code on failure
 */
int	ft_so_long(t_game *game)
{
	int	height;
	int	width;

	game->mlx = mlx_init();
	if (!game->mlx)
	{
		ft_putstr_fd("Error\nProblem with the mlx", 2);
		return (ft_error(0, game));
	}
	mlx_get_screen_size(game->mlx, &width, &height);
	if (width < game->map_width * 64 || height < game->map_height * 64)
		return (free(game->mlx), ft_error(7, game));
	game->mlx_win = mlx_new_window(game->mlx, game->map_width * 64,
			game->map_height * 64, "SO_LONG");
	if (!game->mlx_win)
	{
		ft_putstr_fd("Error\nProblem with the mlx", 2);
		return (free(game->mlx), ft_error(0, game));
	}
	ft_draw_map(game);
	mlx_hook(game->mlx_win, 2, 1L << 0, ft_key, game);
	mlx_hook(game->mlx_win, 17, 1L << 17, ft_destroy_window, game);
	mlx_loop_hook(game->mlx, ft_animations, game);
	mlx_loop(game->mlx);
	return (0);
}

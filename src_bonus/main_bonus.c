/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isainz-r <isainz-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 11:04:57 by isainz-r          #+#    #+#             */
/*   Updated: 2024/06/24 09:30:55 by isainz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

/**
 * @brief Frees the memory allocated for the game map.
 * 
 * This function deallocates all memory used by the game map array. It
 * iterates through each row of the map, frees the individual string
 * memory, then frees the array of pointers and sets the map pointer
 * to NULL to prevent dangling references.
 * 
 * @param game Pointer to the game structure containing the map
 */
void	ft_free_map(t_game *game)
{
	int	i;

	i = 0;
	while (game->map[i])
	{
		free(game->map[i]);
		i++;
	}
	free(game->map);
	game->map = NULL;
}

/**
 * @brief Frees the memory allocated for the game map copy.
 * 
 * This function deallocates all memory used by the game map copy array,
 * which is typically used for pathfinding validation. It follows the same
 * pattern as ft_free_map, freeing each row then the array itself and
 * setting the pointer to NULL.
 * 
 * @param game Pointer to the game structure containing the map copy
 */
void	ft_free_map_copy(t_game *game)
{
	int	i;

	i = 0;
	while (game->map_copy[i])
	{
		free(game->map_copy[i]);
		i++;
	}
	free(game->map_copy);
	game->map_copy = NULL;
}

/**
 * @brief Initializes all fields of the game structure to default values.
 * 
 * This function sets up the initial state of the game structure by
 * initializing all pointers to NULL, counters to zero, and preparing
 * the structure for map loading and game initialization. This prevents
 * undefined behavior from uninitialized variables.
 * 
 * @param game Pointer to the game structure to initialize
 */
void	inicialize_structure(t_game *game)
{
	game->map = NULL;
	game->map_copy = NULL;
	game->map_one_line = NULL;
	game->num_player = 0;
	game->num_collectibles = 0;
	game->num_exit = 0;
	game->num_enemy = 0;
	game->moves = 0;
	game->map_height = 0;
	game->wall = NULL;
	game->floor = NULL;
	game->player = NULL;
	game->collectibles = NULL;
	game->exit = NULL;
	game->enemy1 = NULL;
	game->enemy2 = NULL;
	game->enemy3 = NULL;
	game->enemy4 = NULL;
	game->x_player = 0;
	game->y_player = 0;
}

/**
 * @brief Handles error messages and cleanup based on error type.
 * 
 * This function displays appropriate error messages for different types
 * of map validation failures and game initialization errors. It also
 * performs cleanup by freeing allocated memory for maps and temporary
 * data structures before returning an error code.
 * 
 * @param i Error code indicating the type of error that occurred
 * @param game Pointer to the game structure for cleanup operations
 * @return Always returns 1 to indicate an error occurred
 */
int	ft_error(int i, t_game *game)
{
	if (i == 1)
		ft_putstr_fd("Error\nInvalid map, it doesn't end with .ber.\n", 2);
	if (i == 2)
		ft_putstr_fd("Error\nNot able to open map, read or null map.\n", 2);
	if (i == 3)
		ft_putstr_fd("Error\nInvalid map, not a rectangle.\n", 2);
	if (i == 4)
		ft_putstr_fd("Error\nInvalid map, problem with characters.\n", 2);
	if (i == 5)
		ft_putstr_fd("Error\nInvalid map, map not surrounded by 1.\n", 2);
	if (i == 6)
		ft_putstr_fd("Error\nInvalid map, not a valid path.\n", 2);
	if (i == 7)
		ft_putstr_fd("Error\nMap does not fit in the screen.\n", 2);
	if (game->map_one_line)
		free(game->map_one_line);
	if (game->map)
		ft_free_map(game);
	if (game->map_copy)
		ft_free_map_copy(game);
	return (1);
}

/**
 * @brief Main function that validates arguments and starts the game.
 * 
 * This function serves as the entry point for the program. It validates
 * that exactly one argument (the map file) is provided, initializes the
 * game structure, validates the map file, and starts the game if all
 * checks pass successfully.
 * 
 * @param argc Number of command line arguments
 * @param argv Array of command line argument strings
 * @return 0 on successful execution, 1 on error
 */
int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
	{
		ft_putstr_fd("Error\nInvalid number of arguments.\n", 2);
		return (1);
	}
	inicialize_structure(&game);
	if (ft_check_map(&game, argv[1]) == 1)
		return (1);
	ft_so_long(&game);
	return (0);
}

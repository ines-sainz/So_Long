/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isainz-r <isainz-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 11:04:57 by isainz-r          #+#    #+#             */
/*   Updated: 2024/06/24 09:26:46 by isainz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/**
 * @brief Frees memory allocated for the main game map
 * 
 * Iterates through each row of the map array, frees individual strings,
 * then frees the array pointer and sets it to NULL.
 * 
 * @param game Pointer to the game structure containing the map to free
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
 * @brief Frees memory allocated for the backup copy of the game map
 * 
 * Iterates through each row of the map copy array, frees individual strings,
 * then frees the array pointer and sets it to NULL.
 * 
 * @param game Pointer to the game structure containing the map copy to free
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
 * @brief Initializes all game structure fields to default values
 * 
 * Sets all pointers to NULL, counters to zero, and prepares the game
 * structure for use with clean initial state.
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
	game->moves = 0;
	game->map_height = 0;
	game->wall = NULL;
	game->floor = NULL;
	game->player = NULL;
	game->collectibles = NULL;
	game->exit = NULL;
	game->x_player = 0;
	game->y_player = 0;
}

/**
 * @brief Handles error reporting and memory cleanup
 * 
 * Prints appropriate error messages based on error code and cleans up
 * allocated memory before returning error status.
 * 
 * @param i Error code indicating the type of error that occurred
 * @param game Pointer to the game structure for memory cleanup
 * @return 1 to indicate error status
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
 * @brief Main program entry point
 * 
 * Validates command line arguments, initializes game structure, performs
 * map validation, and starts the game if everything is valid.
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

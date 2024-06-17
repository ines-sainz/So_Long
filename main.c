/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isainz-r <isainz-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 11:04:57 by isainz-r          #+#    #+#             */
/*   Updated: 2024/06/11 18:23:09 by isainz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

int	ft_error(int i, t_game *game)
{
	if (i == 1)
		ft_putstr_fd("Invalid map, it doesn't end with .ber.\n", 2);
	if (i == 2)
		ft_putstr_fd("Not able to open map, read or null map.\n", 2);
	if (i == 3)
		ft_putstr_fd("Invalid map, not a rectangle.\n", 2);
	if (i == 4)
		ft_putstr_fd("Invalid map, problem with characters.\n", 2);
	if (i == 5)
		ft_putstr_fd("Invalid map, map not surrounded by 1.\n", 2);
	if (i == 6)
		ft_putstr_fd("Invalid map, not a valid path.\n", 2);
	if (i == 7)
		ft_putstr_fd("Map does not fit in the screen.\n", 2);
	if (game->map_one_line)
		free(game->map_one_line);
	if (game->map)
		ft_free_map(game);
	if (game->map_copy)
		ft_free_map_copy(game);
	return (1);
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
	{
		ft_putstr_fd("Invalid number of arguments.\n", 2);
		return (1);
	}
	inicialize_structure(&game);
	if (ft_check_map(&game, argv[1]) == 1)
		return (1);
	ft_so_long(&game);
	return (0);
}

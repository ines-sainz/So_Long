/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isainz-r <isainz-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 11:22:29 by isainz-r          #+#    #+#             */
/*   Updated: 2024/06/10 20:15:44 by isainz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	ft_check_longitude(t_game *game)
{
	int	j;

	j = 0;
	while (game->map[game->map_height])
	{
		while (game->map[game->map_height][j])
			j++;
		if (game->map_height == 0)
			game->map_width = j;
		if (game->map_width != j)
			return (1);
		game->map_height++;
		j = 0;
	}
	return (0);
}

int	ft_map_in_matrix(t_game *game)
{
	int	i;

	i = 0;
	if (!game->map_one_line)
		return (1);
	if (game->map_one_line[0] == '\n' || game->map_one_line[0] == '\0')
		return (1);
	while (game->map_one_line[i])
	{
		if (game->map_one_line[i] == '\n' && game->map_one_line[i + 1] == '\n')
			return (1);
		i++;
	}
	if (game->map_one_line[--i] == '\n')
		return (1);
	game->map = ft_split(game->map_one_line, '\n');
	if (game->map == NULL)
		return (1);
	game->map_copy = ft_split(game->map_one_line, '\n');
	if (!game->map_copy)
		return (1);
	free(game->map_one_line);
	game->map_one_line = NULL;
	return (0);
}

int	ft_open_map(t_game *game, int fd, int n_bytes)
{
	char	*temp;
	char	*buffer;

	buffer = ft_calloc(100 + 1, sizeof(char));
	if (!buffer)
		return (ft_error(2, game));
	while (n_bytes)
	{
		n_bytes = read(fd, buffer, 100);
		buffer[n_bytes] = '\0';
		if (n_bytes < 0)
			return (free(buffer), ft_error(2, game));
		temp = game->map_one_line;
		game->map_one_line = ft_add(temp, buffer);
		free(temp);
		if (!game->map_one_line)
			return (free(buffer), ft_error(2, game));
	}
	free(buffer);
	if (ft_map_in_matrix(game) == 1)
		return (ft_error(3, game));
	return (0);
}

int	ft_check_ber(char *argv)
{
	char	*extension_map;
	int		len_extension;

	len_extension = ft_strlen(argv);
	extension_map = ft_substr(argv, len_extension - 4, 4);
	if (!extension_map)
		return (1);
	if (ft_strncmp(".ber", extension_map, 4) == 0
		&& len_extension > 4 && argv[len_extension - 5] != '/')
	{
		free(extension_map);
		return (0);
	}
	free(extension_map);
	return (1);
}

int	ft_check_map(t_game *game, char *argv)
{
	int	fd;
	int	n_bytes;

	if (ft_check_ber(argv) == 1)
		return (ft_error(1, game));
	fd = open(argv, O_RDONLY);
	if (fd < 0)
		return (ft_error(2, game));
	n_bytes = 1;
	if (ft_open_map(game, fd, n_bytes) == 1)
		return (1);
	if (ft_check_longitude(game) == 1)
		return (ft_error(3, game));
	if (game->map_width > 200 || game->map_height > 200)
		return (ft_error(7, game));
	if (ft_check_characters(game) == 1)
		return (1);
	if (ft_check_path(game) == 1)
		return (ft_error(6, game));
	return (0);
}

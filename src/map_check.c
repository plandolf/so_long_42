/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plandolf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 13:02:58 by plandolf          #+#    #+#             */
/*   Updated: 2023/07/21 13:04:02 by plandolf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	map_errors(t_game *game)
{
	if (game->map.collectibles == 0)
		error_handler(game, "No collectibles");
	if (game->map.exit == 0 || game->map.exit > 1)
		error_handler(game, "The map must have one exit");
	if (game->map.player == 0 || game->map.player > 1)
		error_handler(game, "The map must have one player");
}

void	check_elements(t_game *game)
{
	int	i;
	int	j;

	i = -1;
	while (++i < game->map.rows)
	{
		j = -1;
		while (++j < game->map.columns)
		{
			if (game->map.map[i][j] == COLLECTIBLE)
				game->map.collectibles++;
			else if (game->map.map[i][j] == EXIT)
				game->map.exit++;
			else if (game->map.map[i][j] == PLAYER)
			{
				game->map.player++;
				game->map.player_pos = (t_point){j, i};
			}
		}
	}
	map_errors(game);
}

bool	map_is_closed(t_map *map)
{
	int	i;

	i = -1;
	while (++i < map->columns)
		if (map->map[0][i] != WALL || map->map[map->rows - 1][i] != WALL)
			return (false);
	i = -1;
	while (++i < map->rows)
		if (map->map[i][0] != WALL || map->map[i][map->columns - 1] != WALL)
			return (false);
	return (true);
}

bool	valid_len(t_game *game)
{
	size_t	len;
	size_t	i;

	len = game->map.columns;
	i = 0;
	while (game->map.map[i])
	{
		if (len != ft_strlen(game->map.map[i]))
			return (false);
		i++;
	}
	return (true);
}

void	map_check(t_game *game)
{
	if (!valid_len(game))
		error_handler(game, "Map is not rectangular");
	check_elements(game);
	if (!map_is_closed(&game->map))
		error_handler(game, "Map is not closed");
	path_check(game);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plandolf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 13:06:05 by plandolf          #+#    #+#             */
/*   Updated: 2023/07/21 13:06:34 by plandolf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

char	**empty_map(t_game *game)
{
	char	**map;
	int		i;

	i = 0;
	map = ft_calloc((game->map.rows + 1), sizeof(char *));
	if (!map)
		error_handler(game, "Can't allocate memory");
	while (i < game->map.rows)
	{
		map[i] = ft_strdup(game->map.map[i]);
		if (!map[i])
		{
			ft_free_matrix(map);
			error_handler(game, "Can't allocate memory");
		}
		i += 1;
	}
	return (map);
}

void	path_check(t_game *game)
{
	char	**path;

	path = empty_map(game);
	if (!ft_floodfill(&game->map, game->map.player_pos, path))
	{
		ft_free_matrix(path);
		error_handler(game, "Map is not valid");
	}
	ft_free_matrix(path);
}

bool	ft_floodfill(t_map *map, t_point cur, char **solution)
{
	static int	coins = 0;
	static bool	exit = false;

	if (solution[cur.y][cur.x] == WALL)
		return (false);
	else if (solution[cur.y][cur.x] == COLLECTIBLE)
		coins++;
	else if (solution[cur.y][cur.x] == EXIT)
		exit = true;
	solution[cur.y][cur.x] = WALL;
	ft_floodfill(map, (t_point){cur.x + 1, cur.y}, solution);
	ft_floodfill(map, (t_point){cur.x - 1, cur.y}, solution);
	ft_floodfill(map, (t_point){cur.x, cur.y + 1}, solution);
	ft_floodfill(map, (t_point){cur.x, cur.y - 1}, solution);
	return (coins == map->collectibles && exit);
}

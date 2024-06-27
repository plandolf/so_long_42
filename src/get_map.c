/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plandolf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 13:01:51 by plandolf          #+#    #+#             */
/*   Updated: 2023/07/21 13:02:23 by plandolf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	get_rows(char *map_file, t_game *game)
{
	int		counter;
	int		fd;
	char	*line;

	counter = 0;
	fd = open(map_file, O_RDONLY);
	if (fd < 0)
		error_handler(game, "Can't open map file");
	line = get_next_line(fd);
	while (line)
	{
		counter++;
		free(line);
		line = get_next_line(fd);
	}
	if (counter == 0)
		error_handler(game, "Empty map");
	game->map.rows = counter;
	free(line);
	close(fd);
}

void	get_lines(char *map_file, t_game *game)
{
	int	map_fd;
	int	i;

	map_fd = open(map_file, O_RDONLY);
	if (map_fd == -1)
		error_handler(game, "Can't open map file");
	i = 0;
	while (i < game->map.rows)
		game->map.map[i++] = get_next_line(map_fd);
	game->map.map[i] = NULL;
	close(map_fd);
	i = 0;
	while (i < (game->map.rows - 1))
	{
		game->map.map[i] = ft_trim(game->map.map[i], "\n");
		if (!game->map.map[i])
			error_handler(game, "Can't allocate memory");
		i += 1;
	}
	game->map.columns = ft_strlen(game->map.map[0]);
}

void	get_map(char *map_file, t_game *game)
{
	get_rows(map_file, game);
	game->map.map = malloc((game->map.rows + 1) * sizeof(char *));
	if (!game->map.map)
		error_handler(game, "Can't allocate memory");
	get_lines(map_file, game);
}

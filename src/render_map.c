/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plandolf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 13:09:08 by plandolf          #+#    #+#             */
/*   Updated: 2023/07/21 13:17:42 by plandolf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	which_tile(t_game *game)
{
	if (game->map.map[game->map.player_pos.y]
		[game->map.player_pos.x] == COLLECTIBLE)
	{
		game->map.map[game->map.player_pos.y]
		[game->map.player_pos.x] = OPEN_SPACE;
		game->map.collectibles -= 1;
		return ;
	}
	if (game->map.map[game->map.player_pos.y][game->map.player_pos.x] == EXIT
		&& game->map.collectibles == 0)
	{
		ft_printf(WIN_MSG);
		quit_game(game);
	}
}

void	render_tiles(t_game *game)
{
	int	i;
	int	j;

	i = -1;
	while (++i < game->map.rows)
	{
		j = -1;
		while (++j < game->map.columns)
		{
			if (game->map.map[i][j] == WALL)
				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
					game->tiles.wall, TILE_SIZE * j, TILE_SIZE * i);
			else if (game->map.map[i][j] == COLLECTIBLE)
				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
					game->tiles.collectible, TILE_SIZE * j, TILE_SIZE * i);
			else if (game->map.map[i][j] == EXIT)
				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
					game->tiles.exit, TILE_SIZE * j, TILE_SIZE * i);
			else
				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
					game->tiles.floor, TILE_SIZE * j, TILE_SIZE * i);
		}
	}
	put_player_tile(game);
}

void	render_map(t_game *game)
{
	open_xmp(game);
	render_tiles(game);
}

void	put_player_tile(t_game *game)
{
	char	*moves_str;

	game->moves += 1;
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->tiles.player,
		TILE_SIZE * game->map.player_pos.x, TILE_SIZE * game->map.player_pos.y);
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
		game->tiles.wall, 0, 0);
	moves_str = ft_itoa(game->moves);
	mlx_string_put(game->mlx_ptr, game->win_ptr, 10, 10, 16777215, moves_str);
	free(moves_str);
}

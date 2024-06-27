/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plandolf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 13:17:03 by plandolf          #+#    #+#             */
/*   Updated: 2023/07/21 13:17:51 by plandolf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	update_player_pos(t_game *game, bool horizontal, int length)
{
	if (horizontal)
	{
		if (game->map.map[game->map.player_pos.y]
			[game->map.player_pos.x + length] == WALL)
			return ;
		update_tile(game);
		game->map.player_pos.x += length;
	}
	else
	{
		if (game->map.map[game->map.player_pos.y + length]
			[game->map.player_pos.x] == WALL)
			return ;
		update_tile(game);
		game->map.player_pos.y += length;
	}
	which_tile(game);
	put_player_tile(game);
}

int	on_press(int key, t_game *game)
{
	if (key == ESC)
		quit_game(game);
	else if (key == W || key == UP)
		update_player_pos(game, false, -1);
	else if (key == A || key == LEFT)
		update_player_pos(game, true, -1);
	else if (key == S || key == DOWN)
		update_player_pos(game, false, 1);
	else if (key == D || key == RIGHT)
		update_player_pos(game, true, 1);
	return (EXIT_SUCCESS);
}

void	move_hook(t_game *game)
{
	mlx_hook(game->win_ptr, 2, (1L << 0), on_press, game);
	mlx_hook(game->win_ptr, 17, (1L << 17),
		quit_game, game);
	mlx_loop(game->mlx_ptr);
}

/* Overloads the player tile that is left behind when the player moves */
void	update_tile(t_game *game)
{
	if (game->map.map[game->map.player_pos.y]
		[game->map.player_pos.x] == EXIT)
	{
		mlx_put_image_to_window(
			game->mlx_ptr, game->win_ptr, game->tiles.exit,
			TILE_SIZE * game->map.player_pos.x,
			TILE_SIZE * game->map.player_pos.y);
	}
	else
		mlx_put_image_to_window(
			game->mlx_ptr, game->win_ptr, game->tiles.floor,
			TILE_SIZE * game->map.player_pos.x,
			TILE_SIZE * game->map.player_pos.y);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plandolf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 13:07:14 by plandolf          #+#    #+#             */
/*   Updated: 2023/08/09 12:03:55 by plandolf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	open_xmp(t_game *game)
{
	int	img_size;

	img_size = TILE_SIZE;
	game->tiles.wall = mlx_xpm_file_to_image(game->mlx_ptr,
			WALL_TILE, &img_size, &img_size);
	game->tiles.floor = mlx_xpm_file_to_image(game->mlx_ptr,
			FLOOR_TILE, &img_size, &img_size);
	game->tiles.player = mlx_xpm_file_to_image(game->mlx_ptr,
			PLAYER_TILE, &img_size, &img_size);
	game->tiles.collectible = mlx_xpm_file_to_image(game->mlx_ptr,
			COLLECTIBLE_TILE, &img_size, &img_size);
	game->tiles.exit = mlx_xpm_file_to_image(game->mlx_ptr,
			EXIT_TILE, &img_size, &img_size);
	if (!game->tiles.wall || !game->tiles.floor || !game->tiles.player
		|| !game->tiles.collectible || !game->tiles.exit)
		error_handler(game, "Can't open textures");
}

void	destroy(t_game *game)
{
	if (!game)
		return ;
	if (game->win_ptr)
		mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	if (game->mlx_ptr)
	{
		mlx_destroy_image(game->mlx_ptr, game->tiles.player);
		mlx_destroy_image(game->mlx_ptr, game->tiles.wall);
		mlx_destroy_image(game->mlx_ptr, game->tiles.collectible);
		mlx_destroy_image(game->mlx_ptr, game->tiles.floor);
		mlx_destroy_image(game->mlx_ptr, game->tiles.exit);
		mlx_destroy_display(game->mlx_ptr);
		free(game->mlx_ptr);
	}
	if (game->map.map)
		ft_free_matrix(game->map.map);
}

int	quit_game(t_game *game)
{
	destroy(game);
	exit(EXIT_SUCCESS);
	return (EXIT_SUCCESS);
}

void	error_handler(t_game *game, char *msg)
{
	destroy(game);
	ft_putstr_fd("Error:", 2);
	ft_putendl_fd(msg, 2);
	exit(EXIT_FAILURE);
}

void	args_check(int ac, char **av)
{
	if (ac != 2)
	{
		ft_putstr_fd("Error\n", 2);
		ft_putstr_fd("Usage: ./so_long [map.ber]\n", 2);
		exit(EXIT_FAILURE);
	}
	if (ft_strncmp(av[1] + ft_strlen(av[1]) - 4, ".ber", 4))
	{
		ft_putstr_fd("Error\n", 2);
		ft_putstr_fd("Usage: ./so_long [map.ber]\n", 2);
		exit(EXIT_FAILURE);
	}
}

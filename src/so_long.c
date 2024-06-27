/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plandolf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 08:56:42 by plandolf          #+#    #+#             */
/*   Updated: 2023/07/21 13:17:27 by plandolf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	init_mlx(t_game *game)
{
	game->mlx_ptr = mlx_init();
	if (!game->mlx_ptr)
		error_handler(game, "Can't initialize mlx");
	game->win_ptr = mlx_new_window(game->mlx_ptr, game->map.columns * 40,
			game->map.rows * 40, "so_long");
	if (!game->win_ptr)
		error_handler(game, "Can't create window");
}

int	main(int ac, char **av)
{
	t_game	so_long;

	args_check(ac, av);
	so_long = init_game();
	get_map(av[1], &so_long);
	map_check(&so_long);
	init_mlx(&so_long);
	render_map(&so_long);
	move_hook(&so_long);
	destroy(&so_long);
	return (0);
}

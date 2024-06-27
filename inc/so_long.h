/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plandolf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 08:55:53 by plandolf          #+#    #+#             */
/*   Updated: 2023/07/21 13:16:24 by plandolf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define OPEN_SPACE 48
# define WALL 49
# define EXIT 69
# define COLLECTIBLE 67
# define PLAYER 80
# define WIN_WIDTH 1000
# define WIN_HEIGHT 1000
# define ESC 65307
# define MOUSE_LEFT 1
# define MOUSE_RIGHT 2
# define MOUSE_MIDDLE 3
# define W 119
# define A 97
# define S 115
# define D 100
# define UP 65362
# define LEFT 65361
# define DOWN 65364
# define RIGHT 65363
# define SPACE_KEY 32
# define WIN_MSG "Wiiner, winner, chicken dinner!"
# define WALL_TILE "./imgs/wall.xpm"
# define FLOOR_TILE "./imgs/open.xpm"
# define PLAYER_TILE "./imgs/player.xpm"
# define COLLECTIBLE_TILE "./imgs/collectible.xpm"
# define EXIT_TILE "./imgs/exit.xpm"
# define TILE_SIZE 40

# include "../inc/mlx_linux/mlx.h"
# include <stdlib.h>
# include "../inc/libft_nob/libft.h"

typedef struct s_point {
	int	x;
	int	y;
}	t_point;

typedef struct s_map {
	char			**map;
	int				rows;
	int				columns;
	int				collectibles;
	int				exit;
	int				player;
	t_point			player_pos;
}				t_map;

typedef struct s_tiles {
	void	*wall;
	void	*floor;
	void	*player;
	void	*collectible;
	void	*exit;
}				t_tiles;

typedef struct s_game {
	t_map		map;
	void		*mlx_ptr;
	void		*win_ptr;
	t_tiles		tiles;
	int			moves;
}				t_game;

static inline t_game	init_game(void)
{
	return ((t_game){
		.map.map = NULL,
		.map.rows = 0,
		.map.columns = 0,
		.map.collectibles = 0,
		.map.exit = 0,
		.map.player = 0,
		.tiles.collectible = NULL,
		.tiles.exit = NULL,
		.tiles.floor = NULL,
		.tiles.player = NULL,
		.tiles.wall = NULL,
		.moves = -1,
	});
}

void	destroy(t_game *game);
int		quit_game(t_game *game);
void	error_handler(t_game *game, char *msg);
void	args_check(int ac, char **av);
void	get_rows(char *map_file, t_game *game);
void	get_columns(char *map_file, t_game *game);
void	get_map(char *map_file, t_game *game);
void	open_xmp(t_game *game);
void	put_player_tile(t_game *game);
void	which_tile(t_game *game);
void	update_tile(t_game *game);
void	update_player_pos(t_game *game, bool horizontal, int lenght);
void	render_tiles(t_game *game);
void	render_map(t_game *game);
int		on_press(int key, t_game *game);
void	move_hook(t_game *game);
void	init_mlx(t_game *game);
void	map_errors(t_game *game);
void	check_elements(t_game *game);
bool	map_is_closed(t_map *map);
bool	valid_len(t_game *game);
void	map_check(t_game *game);
char	**empty_map(t_game *game);
void	path_check(t_game *game);
bool	ft_floodfill(t_map *map, t_point cur, char **solution);

#endif

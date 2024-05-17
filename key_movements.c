/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   key_movements.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: rkaras <rkaras@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/05/13 12:23:14 by rkaras        #+#    #+#                 */
/*   Updated: 2024/05/13 14:48:30 by rkaras        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_right(t_game *game)
{
	if (game->map[game->player_y][game->player_x + 1] != '1')
	{
		game->textures->player->instances->x += PIXELS;
		game->player_x++;
		game->moves++;
		collectible_checker(game->player_x, game->player_y, game);
	}
	end_game_checker(game);
}

void	move_up(t_game *game)
{
	if (game->map[game->player_y - 1][game->player_x] != '1')
	{
		game->textures->player->instances->y -= PIXELS;
		game->player_y--;
		game->moves++;
		collectible_checker(game->player_x, game->player_y, game);
	}
	end_game_checker(game);
}

void	move_left(t_game *game)
{
	if (game->map[game->player_y][game->player_x - 1] != '1')
	{
		game->textures->player->instances->x -= PIXELS;
		game->player_x--;
		game->moves++;
		collectible_checker(game->player_x, game->player_y, game);
	}
	end_game_checker(game);
}

void	move_down(t_game *game)
{
	if (game->map[game->player_y + 1][game->player_x] != '1')
	{
		game->textures->player->instances->y += PIXELS;
		game->player_y++;
		game->moves++;
		collectible_checker(game->player_x, game->player_y, game);
	}
	end_game_checker(game);
}

void	hook_moves(mlx_key_data_t keydata, void *mlx)
{
	t_game	*game;

	game = (t_game *)mlx;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		mlx_close_window(game->mlx);
	if ((keydata.key == MLX_KEY_W || keydata.key == MLX_KEY_UP)
		&& keydata.action == MLX_PRESS)
		move_up(mlx);
	if ((keydata.key == MLX_KEY_A || keydata.key == MLX_KEY_LEFT)
		&& keydata.action == MLX_PRESS)
		move_left(mlx);
	if ((keydata.key == MLX_KEY_S || keydata.key == MLX_KEY_DOWN)
		&& keydata.action == MLX_PRESS)
		move_down(mlx);
	if ((keydata.key == MLX_KEY_D || keydata.key == MLX_KEY_RIGHT)
		&& keydata.action == MLX_PRESS)
		move_right(mlx);
}

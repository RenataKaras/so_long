/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   end_checkers.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: rkaras <rkaras@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/05/13 14:21:31 by rkaras        #+#    #+#                 */
/*   Updated: 2024/05/13 15:00:38 by rkaras        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	collectible_checker(int x, int y, t_game *game)
{
	size_t	collectible;

	collectible = 0;
	if (game->map[y][x] == 'C')
	{
		while (collectible < game->textures->collectible->count)
		{
			if (game->textures->collectible->instances[collectible].x
				/ PIXELS == x
				&& game->textures->collectible->instances[collectible].y
				/ PIXELS == y)
			{
				game->textures->collectible->instances[collectible].enabled
					= false;
				game->collectible--;
				game->map[y][x] = '0';
			}
			collectible++;
		}
	}
}

void	end_game_checker(t_game *game)
{
	ft_printf("Moves: %i\n", game->moves);
	if (game->collectible == 0
		&& game->player_x == game->exit_x && game->player_y == game->exit_y)
	{
		mlx_close_window(game->mlx);
	}
}

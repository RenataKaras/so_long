/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   add_to_window.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: rkaras <rkaras@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/05/12 15:33:27 by rkaras        #+#    #+#                 */
/*   Updated: 2024/05/12 16:08:16 by rkaras        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	floor_to_window(t_game *game)
{
	int	line;
	int	column;

	line = 0;
	while (line < game->height)
	{
		column = 0;
		while (column < game->width)
		{
			if (mlx_image_to_window(game->mlx, game->textures->floor,
					column * PIXELS, line * PIXELS) < 0)
				ft_error("Floor image to window failure");
			column++;
		}
		line++;
	}
}

void	add_sprites(t_game *game, int line, int column)
{
	if (game->map[line][column] == '1')
	{
		if (mlx_image_to_window(game->mlx, game->textures->wall,
				column * PIXELS, line * PIXELS) < 0)
			ft_error("Wall image to window failure");
	}
	else if (game->map[line][column] == 'P')
	{
		if (mlx_image_to_window(game->mlx, game->textures->player,
				column * PIXELS, line * PIXELS) < 0)
			ft_error("Player image to window failure");
	}
	else if (game->map[line][column] == 'C')
	{
		if (mlx_image_to_window(game->mlx, game->textures->collectible,
				column * PIXELS, line * PIXELS) < 0)
			ft_error("Colectible image to window failure");
	}
	else if (game->map[line][column] == 'E')
	{
		if (mlx_image_to_window(game->mlx, game->textures->exit,
				column * PIXELS, line * PIXELS) < 0)
			ft_error("Exit image to window failure");
	}
}

void	texture_to_window(t_game *game)
{
	int	line;
	int	column;

	line = 0;
	while (line < game->height)
	{
		column = 0;
		while (column < game->width)
		{
			add_sprites(game, line, column);
			column++;
		}
		line++;
	}
}

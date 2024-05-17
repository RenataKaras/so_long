/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   struct_inits.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: rkaras <rkaras@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/05/09 13:31:32 by rkaras        #+#    #+#                 */
/*   Updated: 2024/05/16 11:26:50 by rkaras        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	element_position(char **map, t_game *game)
{
	int	column;
	int	line;

	line = 0;
	while (map[line])
	{
		column = 0;
		while (map[line][column])
		{
			if (map[line][column] == 'P')
			{
				game->player_x = column;
				game->player_y = line;
			}
			if (map[line][column] == 'E')
			{
				game->exit_x = column;
				game->exit_y = line;
			}
			column++;
		}
		line++;
	}
}

static int	count_collectible(char **map)
{
	int	collectible;
	int	lines;
	int	columns;

	lines = 0;
	collectible = 0;
	while (map[lines])
	{
		columns = 0;
		while (map[lines][columns])
		{
			if (map[lines][columns] == 'C')
				collectible++;
			columns++;
		}
		lines++;
	}
	return (collectible);
}

t_game	temp_creation(int height, char **map)
{
	t_game	temp;
	int		i;

	temp.collectible = count_collectible(map);
	element_position(map, &temp);
	temp.height = height;
	temp.map = (char **)ft_calloc(height, sizeof(char *));
	if (temp.map == NULL)
	{
		free_map(map, height);
		free_map(temp.map, temp.height);
		ft_error("Memory allocation failed");
	}
	i = 0;
	while (i < height)
	{
		temp.map[i] = ft_strdup(map[i]);
		i++;
	}
	return (temp);
}

t_image	*image_struct_init(t_game *game)
{
	t_image	*textures;

	textures = ft_calloc(1, sizeof(t_image));
	if (!textures)
		ft_error("Memory allocation fail");
	textures = exit_texture(game->mlx, textures);
	textures = collectible_texture(game->mlx, textures);
	textures = wall_texture(game->mlx, textures);
	textures = player_texture(game->mlx, textures);
	textures = floor_texture(game->mlx, textures);
	return (textures);
}

t_game	game_struct_init(char **map_array, int height)
{
	t_game	game;

	game.map = map_array;
	game.moves = 0;
	game.collectible = count_collectible(map_array);
	element_position(map_array, &game);
	game.height = height;
	game.width = ft_strlen(map_array[0]);
	return (game);
}

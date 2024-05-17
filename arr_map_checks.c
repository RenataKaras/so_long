/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   arr_map_checks.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: rkaras <rkaras@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/04/18 15:44:41 by rkaras        #+#    #+#                 */
/*   Updated: 2024/05/09 18:21:02 by rkaras        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	is_it_rectangular(char **map)
{
	int		lines;
	size_t	line_len;

	lines = 0;
	line_len = ft_strlen(map[lines]);
	while (map[lines])
	{
		if (ft_strlen(map[lines]) != line_len)
			ft_error("Map is not shaped as a rectangular");
		lines++;
	}
	return (lines);
}

static void	wall_check(int height, char **map)
{
	int	columns;
	int	lines;
	int	length;

	lines = 0;
	length = ft_strlen(map[0]) - 1;
	while (map[lines])
	{
		columns = 0;
		while (map[lines][columns])
		{
			if (map[0][columns] != '1' || map[height - 1][columns] != '1')
				ft_error("The map is not surrounded by walls");
			columns++;
		}
		if (map[lines][0] != '1' || map[lines][length] != '1')
			ft_error("The map is not surrounded by walls");
		lines++;
	}
}

static void	walkable_path(t_game *temp, int y, int x)
{
	if (temp->map[y][x] == '1')
		return ;
	if (temp->map[y][x] == 'E')
		temp->exit_x = 1;
	if (temp->map[y][x] == 'C')
		temp->collectible--;
	temp->map[y][x] = '1';
	walkable_path(temp, y + 1, x);
	walkable_path(temp, y - 1, x);
	walkable_path(temp, y, x + 1);
	walkable_path(temp, y, x - 1);
}

static void	path_check(int height, char **map)
{
	t_game	temp;

	temp = temp_creation(height, map);
	walkable_path(&temp, temp.player_y, temp.player_x);
	if (temp.exit_x != 1 || temp.collectible != 0)
	{
		free_map(map, height);
		free_map(temp.map, temp.height);
		ft_error("No walkable path available");
	}
	free_map(temp.map, temp.height);
}

int	array_map_check(char **map)
{
	int	height;

	height = is_it_rectangular(map);
	wall_check(height, map);
	path_check(height, map);
	return (height);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   str_map_checks.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: rkaras <rkaras@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/04/18 15:02:41 by rkaras        #+#    #+#                 */
/*   Updated: 2024/04/22 17:39:29 by rkaras        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	empty_map(char *map)
{
	if (map[0] == '\0')
		ft_error("The map is empty, try different file");
}

static void	empty_line(char *map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		if (map[0] == '\n' || (map[i] == '\n' && map[i + 1] == '\n'))
			ft_error("Map has empty lines");
		i++;
	}
}

static void	invalid_char(char *map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		if (ft_strchr("01PEC\n", map[i]) == NULL)
			ft_error("There is an invalid character in the map");
		i++;
	}
}

static void	map_occurence(char *map)
{
	int		player;
	int		collectible;
	int		exit;
	int		i;

	player = 0;
	collectible = 0;
	exit = 0;
	i = 0;
	while (map[i])
	{
		if (map[i] == 'P')
			player++;
		if (map[i] == 'C')
			collectible++;
		if (map[i] == 'E')
			exit++;
		i++;
	}
	if (player != 1 || exit != 1 || collectible < 1)
		ft_error("Invalid map content");
}

void	str_map_check(char *map_str)
{
	empty_map(map_str);
	empty_line(map_str);
	invalid_char(map_str);
	map_occurence(map_str);
}

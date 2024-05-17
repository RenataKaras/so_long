/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parsing.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: rkaras <rkaras@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/04/05 17:56:40 by rkaras        #+#    #+#                 */
/*   Updated: 2024/05/13 17:42:34 by rkaras        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*read_map(char *map)
{
	int		fd;
	char	*temp;
	char	*map_read;
	char	*current_line;

	fd = open(map, O_RDONLY);
	if (fd == -1)
		ft_error("Cannot open the map file");
	temp = ft_calloc(1, sizeof(char *));
	if (temp == NULL)
		ft_error("Memory allocation issue");
	current_line = get_next_line(fd);
	if (current_line == NULL)
		ft_error("Problem with reading the file");
	while (current_line != NULL)
	{
		map_read = ft_strjoin(temp, current_line);
		if (map_read == NULL)
			return (free(temp), NULL);
		free(current_line);
		current_line = get_next_line(fd);
		free(temp);
		temp = map_read;
	}
	return (close(fd), map_read);
}

t_game	map_check(char *argv)
{
	char	*map_str;
	char	**map_array;
	int		height;
	t_game	game;

	map_str = read_map(argv);
	str_map_check(map_str);
	map_array = ft_split(map_str, '\n');
	height = array_map_check(map_array);
	game = game_struct_init(map_array, height);
	free(map_str);
	return (game);
}

void	file_extension_check(char *filename)
{
	int	len;
	int	same;

	len = ft_strlen(filename);
	same = ft_strncmp(&filename[len - 4], ".ber", 4);
	if (len < 4 || same != 0)
		ft_error("Map file has to be .ber");
}

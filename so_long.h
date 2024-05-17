/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   so_long.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: rkaras <rkaras@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/04/18 17:52:07 by rkaras        #+#    #+#                 */
/*   Updated: 2024/05/16 11:30:16 by rkaras        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./Libft/libft.h"
# include "./Libft/ft_printf.h"
# include "./Libft/get_next_line.h"
# include "./MLX42/include/MLX42/MLX42.h"

# define PIXELS 64

typedef struct s_image
{
	mlx_image_t	*floor;
	mlx_image_t	*wall;
	mlx_image_t	*exit;
	mlx_image_t	*collectible;
	mlx_image_t	*player;
}	t_image;

typedef struct s_game
{
	char	**map;
	int		moves;
	int		collectible;
	int		player_x;
	int		player_y;
	int		exit_x;
	int		exit_y;
	int		height;
	int		width;
	mlx_t	*mlx;
	t_image	*textures;
}	t_game;

void		ft_error(char *message);
void		free_map(char **map, int height);
int			main(int argc, char *argv[]);

//parsing - map checks
void		file_extension_check(char *filename);
char		*read_map(char *map);
t_game		map_check(char *argv);
void		str_map_check(char *map_str);
int			array_map_check(char **map);

//struct inits - window & images
t_game		game_struct_init(char **map_array, int height);
t_image		*exit_texture(mlx_t *mlx, t_image *image);
t_image		*collectible_texture(mlx_t *mlx, t_image *image);
t_image		*wall_texture(mlx_t *mlx, t_image *image);
t_image		*player_texture(mlx_t *mlx, t_image *image);
t_image		*floor_texture(mlx_t *mlx, t_image *image);
t_image		*image_struct_init(t_game *game);
t_game		temp_creation(int height, char **map);
void		floor_to_window(t_game *game);
void		texture_to_window(t_game *game);
void		add_sprites(t_game *game, int line, int column);

//movement - game working
void		hook_moves(mlx_key_data_t keydata, void *mlx);
void		move_right(t_game *game);
void		move_up(t_game *game);
void		move_left(t_game *game);
void		collectible_checker(int x, int y, t_game *game);
void		end_game_checker(t_game *game);

#endif
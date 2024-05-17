/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: rkaras <rkaras@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/05/09 13:40:42 by rkaras        #+#    #+#                 */
/*   Updated: 2024/05/13 15:28:54 by rkaras        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char *argv[])
{
	t_game	game;

	if (argc != 2)
		ft_error("One argument only pwetty pwease");
	file_extension_check(argv[1]);
	game = map_check(argv[1]);
	game.mlx = mlx_init(game.width * PIXELS,
			game.height * PIXELS, "so_long", true);
	if (!game.mlx)
		ft_error("there's an issue with MLX");
	game.textures = image_struct_init(&game);
	floor_to_window(&game);
	texture_to_window(&game);
	mlx_key_hook(game.mlx, hook_moves, &game);
	mlx_loop(game.mlx);
	mlx_terminate(game.mlx);
	free_map(game.map, game.height);
	return (free(game.textures), (EXIT_SUCCESS));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   texture.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: rkaras <rkaras@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/05/07 18:05:27 by rkaras        #+#    #+#                 */
/*   Updated: 2024/05/12 17:06:51 by rkaras        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_image	*exit_texture(mlx_t *mlx, t_image *image)
{
	mlx_texture_t	*exit;

	exit = mlx_load_png("textures/exit.png");
	if (!exit)
		ft_error("Problem with loading exit png");
	image->exit = mlx_texture_to_image(mlx, exit);
	if (!image->exit)
		ft_error("Problem adding exit texture to image");
	mlx_delete_texture(exit);
	return (image);
}

t_image	*collectible_texture(mlx_t *mlx, t_image *image)
{
	mlx_texture_t	*collectible;

	collectible = mlx_load_png("textures/Melon.png");
	if (!collectible)
		ft_error("Problem with loading collectible png");
	image->collectible = mlx_texture_to_image(mlx, collectible);
	if (!image->collectible)
		ft_error("Problem adding collectible texture to image");
	mlx_delete_texture(collectible);
	return (image);
}

t_image	*wall_texture(mlx_t *mlx, t_image *image)
{
	mlx_texture_t	*wall;

	wall = mlx_load_png("textures/wall.png");
	if (!wall)
		ft_error("Problem with loading wall png");
	image->wall = mlx_texture_to_image(mlx, wall);
	if (!image->wall)
		ft_error("Problem adding wall texture to image");
	mlx_delete_texture(wall);
	return (image);
}

t_image	*player_texture(mlx_t *mlx, t_image *image)
{
	mlx_texture_t	*player;

	player = mlx_load_png("textures/Link_Right.png");
	if (!player)
		ft_error("Problem with loading player png");
	image->player = mlx_texture_to_image(mlx, player);
	if (!image->player)
		ft_error("Problem adding player texture to image");
	mlx_delete_texture(player);
	return (image);
}

t_image	*floor_texture(mlx_t *mlx, t_image *image)
{
	mlx_texture_t	*floor;

	floor = mlx_load_png("textures/floor.png");
	if (!floor)
		ft_error("Problem with loading floor png");
	image->floor = mlx_texture_to_image(mlx, floor);
	if (!image->floor)
		ft_error("Problem adding floor texture to image");
	mlx_delete_texture(floor);
	return (image);
}

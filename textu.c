/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textu.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moer-ret <moer-ret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 13:15:33 by moer-ret          #+#    #+#             */
/*   Updated: 2024/03/12 16:43:05 by moer-ret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_texture(t_game *game)
{
	int	height_image;
	int	width_image;

	game->texture.player_img_right = mlx_xpm_file_to_image(game->mlx_in, \
	"./textures/player_right.xpm", &width_image, &height_image);
	game->texture.player_img_left = mlx_xpm_file_to_image(game->mlx_in, \
	"./textures/player_left.xpm", &width_image, &height_image);
	game->texture.coin_img = mlx_xpm_file_to_image(game->mlx_in, \
	"./textures/coin.xpm", &width_image, &height_image);
	game->texture.exit_img_close = mlx_xpm_file_to_image(game->mlx_in, \
	"./textures/exit_close.xpm", &width_image, &height_image);
	game->texture.exit_img_open = mlx_xpm_file_to_image(game->mlx_in, \
	"./textures/exit_open.xpm", &width_image, &height_image);
	game->texture.wall_img = mlx_xpm_file_to_image(game->mlx_in, \
	"./textures/wall.xpm", &width_image, &height_image);
	game->texture.space_img = mlx_xpm_file_to_image(game->mlx_in, \
	"./textures/space.xpm", &width_image, &height_image);
}
void	destroy_textures(t_game *game)
{
	mlx_destroy_image(game->mlx_in, game->texture.player_img_right);
	mlx_destroy_image(game->mlx_in, game->texture.player_img_left);
	mlx_destroy_image(game->mlx_in, game->texture.coin_img);
	mlx_destroy_image(game->mlx_in, game->texture.exit_img_close);
	mlx_destroy_image(game->mlx_in, game->texture.exit_img_open);
	mlx_destroy_image(game->mlx_in, game->texture.wall_img);
	mlx_destroy_image(game->mlx_in, game->texture.space_img);
}

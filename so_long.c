/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moer-ret <moer-ret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 19:29:53 by moer-ret          #+#    #+#             */
/*   Updated: 2024/03/12 17:02:54 by moer-ret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	to_fix_nor(t_game *game, int i, int j)
{
	if (game->track.map[i][j] == '1')
		mlx_put_image_to_window(game->mlx_in, game->mlx_window, \
		game->texture.wall_img, j * 64, i * 64);
	else if (game->track.map[i][j] == '0')
		mlx_put_image_to_window(game->mlx_in, game->mlx_window, \
		game->texture.space_img, j * 64, i * 64);
	else if (game->track.map[i][j] == 'E')
	{
		if (game->track.p_collected != game->track.c_count)
			mlx_put_image_to_window(game->mlx_in, game->mlx_window, \
		game->texture.exit_img_close, j * 64, i * 64);
		else
			mlx_put_image_to_window(game->mlx_in, game->mlx_window, \
			game->texture.exit_img_open, j * 64, i * 64);
	}
	else
		mlx_put_image_to_window(game->mlx_in, game->mlx_window, \
		game->texture.coin_img, j * 64, i * 64);
}

void	display_map(t_game *game, int flag)
{
	int	i;
	int	j;

	i = 0;
	while (game->track.map[i])
	{
		j = 0;
		while (game->track.map[i][j])
		{
			if (game->track.map[i][j] == 'P')
			{
				if (flag == 1)
					mlx_put_image_to_window(game->mlx_in, game->mlx_window, \
					game->texture.player_img_right, j * 64, i * 64);
				else if (flag == 0)
					mlx_put_image_to_window(game->mlx_in, game->mlx_window, \
					game->texture.player_img_left, j * 64, i * 64);
			}
			else
				to_fix_nor(game, i, j);
			j++;
		}
		i++;
	}
}

int	keyhook(int code, t_game *game)
{
	if (code == 119)
		move_up(game->track.x - 1, game->track.y, game);
	else if (code == 115)
		move_down(game->track.x + 1, game->track.y, game);
	else if (code == 97)
		move_left(game->track.x, game->track.y - 1, game);
	else if (code == 100)
		move_right(game->track.x, game->track.y + 1, game);
	else if (code == 65307)
	{
		free_aloc(game->track.map);
		mlx_destroy_window(game->mlx_in, game->mlx_window);
		destroy_textures(game);
		mlx_destroy_display(game->mlx_in);
		exit (1);
	}
	return (1);
}

void	so_long(t_game *game)
{
	game->track.p_collected = 0;
	game->mlx_in = mlx_init();
	game->mlx_window = mlx_new_window(game->mlx_in, \
	ft_strlen(game->track.map[0]) * 64, \
	lentgh(game->track.map) * 64, "So_long");
	init_texture(game);
	display_map(game, 1);
	mlx_key_hook(game->mlx_window, &keyhook, game);
	mlx_loop(game->mlx_in);
}

int	main(int ac, char **av)
{
	char	*buffer;
	t_game	game;

	game.track.c_count_cpy = 0;
	if (ac != 2)
		exit(1);
	buffer = NULL;
	check_argument(av);
	parsing_map(av, buffer, &game, 0);
	so_long(&game);
}

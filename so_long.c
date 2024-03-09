/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moer-ret <moer-ret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 19:29:53 by moer-ret          #+#    #+#             */
/*   Updated: 2024/03/09 21:34:28 by moer-ret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	po_player(char **map, t_track *position)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P')
			{
				position->x = i;
				position->y = j;
				break ;
			}
			j++;
		}
		i++;
	}
}

void	check_argument(char **av)
{
	int		i;
	char	*format_map;
	char	*ber;

	i = 0;
	format_map = ".ber\0";
	ber = ft_strchr(av[1], '.');
	while (ber[i])
	{
		if (format_map[i] != ber[i])
			exit(1);
		i++;
	}
}

void	floodfill(int x, int y, char **map, t_track *game)
{
	if (map[x][y] == '1')
		return ;
	if (map[x][y] == 'E')
	{
		game->flag = 1;
		return ;
	}
	if (map[x][y] == 'C')
		game->c_count_cpy++;
	map[x][y] = '1';
	floodfill(x + 1, y, map, game);
	floodfill(x - 1, y, map, game);
	floodfill(x, y + 1, map, game);
	floodfill(x, y - 1, map, game);
}

void init_texture(t_game *game)
{
	int height_image;
	int width_image;
	game->texture.player_img = mlx_xpm_file_to_image(game->mlx_in,"./textures/player.xpm",&width_image,&height_image);
	game->texture.coin_img = mlx_xpm_file_to_image(game->mlx_in,"./textures/coin.xpm",&width_image,&height_image);
	game->texture.exit_img = mlx_xpm_file_to_image(game->mlx_in,"./textures/coin.xpm",&width_image,&height_image);
	game->texture.wall_img = mlx_xpm_file_to_image(game->mlx_in,"./textures/coin.xpm",&width_image,&height_image);
	game->texture.space_img = mlx_xpm_file_to_image(game->mlx_in,"./textures/coin.xpm",&width_image,&height_image);
}


int	main(int ac, char **av)
{
	char	*buffer;
	t_track	position;
	t_game game;

	if (ac != 2)
		exit(1);
	buffer = NULL;
	check_argument(av);
	read_map(av, buffer, &position);
	game.mlx_in = mlx_init();
	game.mlx_window = mlx_new_window(game.mlx_in, 500, 500, "So_long");
	mlx_loop(game.mlx_in);
}

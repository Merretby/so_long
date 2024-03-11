/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moer-ret <moer-ret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 19:29:53 by moer-ret          #+#    #+#             */
/*   Updated: 2024/03/11 20:12:52 by moer-ret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	po_player(t_track *position)
{
	int	i;
	int	j;

	i = 0;
	while (position->map[i])
	{
		j = 0;
		while (position->map[i][j])
		{
			if (position->map[i][j] == 'P')
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

	game->texture.player_img_right = mlx_xpm_file_to_image(game->mlx_in,"./textures/player_right.xpm",&width_image,&height_image);
	game->texture.player_img_left = mlx_xpm_file_to_image(game->mlx_in,"./textures/player_left.xpm",&width_image,&height_image);
	game->texture.coin_img = mlx_xpm_file_to_image(game->mlx_in,"./textures/coin.xpm",&width_image,&height_image);
	game->texture.exit_img_close = mlx_xpm_file_to_image(game->mlx_in,"./textures/exit_close.xpm",&width_image,&height_image);
	game->texture.exit_img_open = mlx_xpm_file_to_image(game->mlx_in,"./textures/exit_open.xpm",&width_image,&height_image);
	game->texture.wall_img = mlx_xpm_file_to_image(game->mlx_in,"./textures/wall.xpm",&width_image,&height_image);
	game->texture.space_img = mlx_xpm_file_to_image(game->mlx_in,"./textures/space.xpm",&width_image,&height_image);
}

void	display_map(t_game *game, int flag)
{
	int i;
	int	j;

	i = 0;
	while (game->track.map[i])
	{
		j = 0;
		while (game->track.map[i][j])
		{
			if (game->track.map[i][j] == '1')
				mlx_put_image_to_window(game->mlx_in,game->mlx_window,game->texture.wall_img, j * 64 ,i * 64);
			else if (game->track.map[i][j] == '0')
				mlx_put_image_to_window(game->mlx_in,game->mlx_window,game->texture.space_img, j * 64 ,i * 64);
			else if (game->track.map[i][j] == 'P')
			{
				if (flag == 1)
					mlx_put_image_to_window(game->mlx_in,game->mlx_window,game->texture.player_img_right, j * 64 ,i * 64);
				else if (flag == 0)
					mlx_put_image_to_window(game->mlx_in,game->mlx_window,game->texture.player_img_left, j * 64 ,i * 64);				
			}
			else if (game->track.map[i][j] == 'E')
			{
				if (game->track.p_collected != game->track.c_count)
					mlx_put_image_to_window(game->mlx_in,game->mlx_window,game->texture.exit_img_close, j * 64 ,i * 64);
				else
					mlx_put_image_to_window(game->mlx_in,game->mlx_window,game->texture.exit_img_open, j * 64 ,i * 64);
			}
			else
				mlx_put_image_to_window(game->mlx_in,game->mlx_window,game->texture.coin_img, j * 64 ,i * 64);
			j++;
		}
		i++;
	}
}

int lentgh(char **map)
{
	int i;

	i = 0;
	while (map[i])
		i++;
	return (i);
}

int keyhook(int code, t_game *game)
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
		mlx_destroy_display(game->mlx_in);
		exit (1);
	}
	return (1);
}

// int ft_animation(t_game *game)
// {
// 	mlx_clear_window(game->mlx_in,game->mlx_window);
// 	display_map(game);
// 	return (0);
// }

void	so_long(t_game *game)
{
	game->track.p_collected = 0;
	game->mlx_in = mlx_init();
	game->mlx_window = mlx_new_window(game->mlx_in, ft_strlen(game->track.map[0]) * 64, lentgh(game->track.map) * 64, "So_long");
	init_texture(game);
	display_map(game, 1);
	mlx_key_hook(game->mlx_window, &keyhook, game);
	// mlx_loop_hook(game->mlx_in,&ft_animation,game);
	mlx_loop(game->mlx_in);
}

int	main(int ac, char **av)
{
	char	*buffer;
	t_game game;

	if (ac != 2)
		exit(1);
	buffer = NULL;
	check_argument(av);
	parsing_map(av, buffer, &game);
	so_long(&game);
}

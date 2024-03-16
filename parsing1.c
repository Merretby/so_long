/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moer-ret <moer-ret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 20:35:09 by moer-ret          #+#    #+#             */
/*   Updated: 2024/03/16 22:31:04 by moer-ret         ###   ########.fr       */
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
	if (ber == NULL)
		error("ERROR");
	while (ber[i])
	{
		if (format_map[i] != ber[i])
			error("ERROR");
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

int	lentgh(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	return (i);
}

int	ft_close(t_game *game)
{
	ft_free(game->track.map);
	mlx_destroy_window(game->mlx_in, game->mlx_window);
	destroy_textures(game);
	mlx_destroy_display(game->mlx_in);
	free(game->mlx_in);
	exit (0);
}

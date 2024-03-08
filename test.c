/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moer-ret <moer-ret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 19:29:53 by moer-ret          #+#    #+#             */
/*   Updated: 2024/03/08 21:17:44 by moer-ret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	po_player(char **map, t_track *position)
{
	int	i;
	int j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while(map[i][j])
		{
			if (map[i][j] == 'P')
			{
				position->x = i;
				position->y = j;
				break;
			}
			j++;
		}
		i++;
	}
}

void  floodfill(int x, int y, char **map, t_track *game)
{
	if (map[x][y] == '1')
		return ;
	if(map[x][y] == 'E')
		game->flag = 1;
	map[x][y] = '1';
	floodfill(x + 1, y, map, game);
 	floodfill(x - 1, y, map, game);
 	floodfill(x, y + 1, map, game);
 	floodfill(x, y - 1, map, game);
}

int	main(int ac, char **av)
{
	char	*buffer;
	char	*ber;
	char	*format_map;
	int		i;
	t_track position;

	position.flag = 0;
	i = 0;
	if (ac != 2)
		exit(1);
	format_map = ".ber\0";
	buffer = NULL;
	ber = ft_strchr(av[1], '.');
	while (ber[i])
	{
		if(format_map[i] != ber[i])
			exit(1);
		i++;
	}
	read_map(av, buffer, &position);
}

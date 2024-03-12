/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moer-ret <moer-ret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 21:16:24 by moer-ret          #+#    #+#             */
/*   Updated: 2024/03/12 14:45:43 by moer-ret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check(t_game *game, int c_line, char *buffer2)
{
	check1(&game->track, c_line);
	check_2(&game->track);
	check3(buffer2, &game->track);
}

void	check1(t_track *position, int c_l)
{
	int	i;
	int	j;

	i = 0;
	while (position->map[i])
	{
		j = 0;
		while (position->map[i][j])
		{
			if (position->map[i][j] != '0' && position->map[i][j] != '1' && \
			position->map[i][j] != 'P' && \
			position->map[i][j] != 'C' && position->map[i][j] != 'E')
				error("INVALID MAP");
			if (position->map[0][j] != '1' || \
			position->map[c_l - 1][j] != '1' || position->map[i][0] != '1' || \
			position->map[i][ft_strlen(position->map[i]) - 1] != '1')
				error("INVALID MAP");
			j++;
		}
		if (++i < c_l)
		{
			if (ft_strlen(position->map[1]) != ft_strlen(position->map[i]))
				error("INVALID MAP");
		}
	}
}

void	check_2(t_track *position)
{
	int	i;
	int	j;

	position->c_count = 0;
	position->p_count = 0;
	position->e_count = 0;
	i = 0;
	while (position->map[i])
	{
		j = 0;
		while (position->map[i][j++])
		{
			if (position->map[i][j] == 'C')
				position->c_count++;
			else if (position->map[i][j] == 'P')
				position->p_count++;
			else if (position->map[i][j] == 'E')
				position->e_count++;
		}
		i++;
	}
	if (position->e_count != 1 || position->p_count != 1 \
	|| position->c_count == 0)
		error("INVALID MAP");
}

void	check3(char *buffer2, t_track *position)
{
	char	**cpy_map;

	cpy_map = ft_split(buffer2, '\n');
	po_player(position);
	floodfill(position->x, position->y, cpy_map, position);
	check_map(position);
}

void	parsing_map(char **av, char *buffer, t_game *game)
{
	int		fd;
	int		c_line;	
	char	*buffer2;

	c_line = 0;
	game->track.c_count_cpy = 0;
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		error("THER IS NO FILE");
	buffer2 = NULL;
	buffer = get_next_line(fd);
	if (buffer == NULL)
		error ("INVALID MAP");
	while (buffer)
	{
		if (buffer[0] == '\n')
			error ("INVALID MAP");
		buffer2 = ft_strjoin(buffer2, buffer);
		c_line++;
		free(buffer);
		buffer = get_next_line(fd);
	}
	game->track.map = ft_split(buffer2, '\n');
	check(game, c_line, buffer2);
	free (buffer2);
}

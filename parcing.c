/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moer-ret <moer-ret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 21:16:24 by moer-ret          #+#    #+#             */
/*   Updated: 2024/03/12 16:16:39 by moer-ret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check(t_game *game, int c_line, char *buffer2)
{
	check1(&game->track, c_line, buffer2);
	check_2(&game->track, buffer2);
	check3(buffer2, &game->track);
	free (buffer2);
}

void	check1(t_track *position, int c_l, char *buffer2)
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
				ft_error("INVALID MAP", buffer2, position);
			if (position->map[0][j] != '1' || \
			position->map[c_l - 1][j] != '1' || position->map[i][0] != '1' || \
			position->map[i][ft_strlen(position->map[i]) - 1] != '1')
				ft_error("INVALID MAP !", buffer2, position);
			j++;
		}
		if (++i < c_l)
		{
			if (ft_strlen(position->map[1]) != ft_strlen(position->map[i]))
				ft_error("NOT SAME LEN", buffer2, position);
		}
	}
}

void	check_2(t_track *position, char *buffer2)
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
		ft_error("U NEDD 1E 1P >1C", buffer2, position);
}

void	check3(char *buffer2, t_track *position)
{
	char	**cpy_map;

	cpy_map = ft_split(buffer2, '\n');
	po_player(position);
	floodfill(position->x, position->y, cpy_map, position);
	free_aloc(cpy_map);
	check_map(position, buffer2);
}

void	parsing_map(char **av, char *buffer, t_game *game, int c_line)
{
	int		fd;
	char	*buffer2;

	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		error("THER IS NO FILE");
	buffer2 = NULL;
	buffer = get_next_line(fd);
	if (buffer == NULL)
		error ("NULL BUFFER");
	while (buffer)
	{
		if (buffer[0] == '\n')
		{
			free (buffer);
			ft_error ("THER IS A NEW LINE :(", buffer2, &game->track);
		}
		buffer2 = ft_strjoin(buffer2, buffer);
		c_line++;
		free(buffer);
		buffer = get_next_line(fd);
	}
	game->track.map = ft_split(buffer2, '\n');
	check(game, c_line, buffer2);
}

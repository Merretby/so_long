/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moer-ret <moer-ret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 21:16:24 by moer-ret          #+#    #+#             */
/*   Updated: 2024/03/09 17:04:26 by moer-ret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check(char **tmp, int c_line)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	len = ft_strlen(tmp[i]);
	while (tmp[i])
	{
		j = 0;
		while (tmp[i][j])
		{
			if (tmp[i][j] != '0' && tmp[i][j] != '1' && tmp[i][j] != 'P'\
			&& tmp[i][j] != 'C' && tmp[i][j] != 'E')
				error("INVALID MAP");
			if (tmp[0][j] != '1' || tmp[c_line - 1][j] != '1'\
			|| tmp[i][0] != '1' || tmp[i][len - 1] != '1')
				error("INVALID MAP");
			j++;
		}
		if (++i < c_line)
		{
			if (len != ft_strlen(tmp[i]))
				error("INVALID MAP");
		}
	}
}

void	check_2(char **tmp, t_track *position)
{
	int	i;
	int	j;

	position->c_count = 0;
	position->p_count = 0;
	position->e_count = 0;
	i = 0;
	while (tmp[i])
	{
		j = 0;
		while (tmp[i][j++])
		{
			if (tmp[i][j] == 'C')
				position->c_count++;
			else if (tmp[i][j] == 'P')
				position->p_count++;
			else if (tmp[i][j] == 'E')
				position->e_count++;
		}
		i++;
	}
	if (position->e_count != 1 || position->p_count != 1 \
	|| position->c_count == 0)
		error("INVALID MAP");
}

void	check_map(t_track *position)
{
	if (!(position->flag == 1 && position->c_count == position->c_count_cpy))
		error("INVALID MAP");
}

void	check3(char *buffer2, t_track *position)
{
	char	**cpy_map;

	cpy_map = ft_split(buffer2, '\n');
	po_player(cpy_map, position);
	floodfill(position->x, position->y, cpy_map, position);
	check_map(position);
	// free_aloc(cpy_map);
}

void	read_map(char **av, char *buffer, t_track *position)
{
	int		fd;
	int		c_line;
	char	**map;
	char	*buffer2;

	c_line = 0;
	position->c_count_cpy = 0;
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		error("THER IS NO FILE");
	buffer2 = NULL;
	buffer = get_next_line(fd);
	while (buffer)
	{
		if (buffer[0] == '\n')
			error ("INVALID MAP");
		buffer2 = ft_strjoin(buffer2, buffer);
		c_line++;
		free(buffer);
		buffer = get_next_line(fd);
	}
	map = ft_split(buffer2, '\n');
	check(map, c_line);
	check_2(map, position);
	check3(buffer2, position);
	// free_aloc(map);
	// free (buffer2);
}

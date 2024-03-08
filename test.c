/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moer-ret <moer-ret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 19:29:53 by moer-ret          #+#    #+#             */
/*   Updated: 2024/03/08 15:37:48 by moer-ret         ###   ########.fr       */
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
				exit (1);
			if (tmp[0][j] != '1' || tmp[c_line - 1][j] != '1'\
			 || tmp[i][0] != '1' || tmp[i][len - 1] != '1')
				exit(1);
			j++;
		}
		i++;
	}
	i = 0;
	while(i < c_line)
	{
		if (len != ft_strlen(tmp[i]))
			exit (1);
		i++;
	}
}

void	check_2(char **tmp)
{
	int	i;
	int	j;
	int	c_count;
	int	p_count;
	int	e_count;

	c_count = 0;
	p_count = 0;
	e_count = 0;
	i = 0;
	while (tmp[i])
	{
		j = 0;
		while (tmp[i][j++])
		{
			if (tmp[i][j] == 'C')
				c_count++;
			else if (tmp[i][j] == 'P')
				p_count++;
			else if (tmp[i][j] == 'E')
				e_count++;
		}
		i++;
	}
	if (e_count != 1 || p_count != 1 || c_count == 0)
		exit (1);
}
void	po_player(char **map)
{
	t_track position;
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
				position.x = i;
				position.y = j;
				break;
			}
			j++;
		}
		i++;
	}
}


void	read_map(char **av, char *buffer)
{
	int		fd;
	int		c_line;
	char	**map;
	char	**cpy_map;
	char	*buffer2;

	c_line = 0;
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		exit(1);
	buffer2 = NULL;
	while ((buffer = get_next_line(fd)))
	{
		if (buffer[0] == '\n')
			exit (1);
		buffer2 = ft_strjoin(buffer2, buffer);
		c_line++;
		free(buffer);
	}
	map = ft_split(buffer2,'\n');
	check(map, c_line);
	check_2(map);
	cpy_map = ft_split(buffer2, '\n');
	po_player(cpy_map);
}

int	main(int ac, char **av)
{
	char	*buffer;
	char	*ber;
	char	*format_map;
	int		i;

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
	read_map(av, buffer);
}

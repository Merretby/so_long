/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moer-ret <moer-ret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 03:02:25 by moer-ret          #+#    #+#             */
/*   Updated: 2024/03/14 00:24:35 by moer-ret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

char	*read_line(char *tmp)
{
	int		i;
	char	*line;

	if (!tmp || !tmp[0])
		return (NULL);
	i = 0;
	while (tmp[i] && tmp[i] != '\n')
		i++;
	if (tmp[i] == '\n')
		i++;
	line = malloc(sizeof(char) * (i + 1));
	if (!line)
		return (NULL);
	i = 0;
	while (tmp[i] && tmp[i] != '\n')
	{
		line[i] = tmp[i];
		i++;
	}
	if (tmp[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*get_line(char *tmp, int i)
{
	int		j;
	char	*line;

	while (tmp[i] && tmp[i] != '\n')
		i++;
	if (tmp[i] == '\0')
	{
		free(tmp);
		return (NULL);
	}
	if (tmp[i] == '\n')
		i++;
	line = malloc(sizeof(char) * (ft_strlen(tmp) - i + 1));
	if (!line)
		return (NULL);
	j = 0;
	while (tmp[i + j])
	{
		line[j] = tmp[i + j];
		j++;
	}
	line[j] = '\0';
	free(tmp);
	return (line);
}

char	*get_next_line(int fd)
{
	int			r_line;
	char		*buffer;
	char		*tmp;

	tmp = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0 || BUFFER_SIZE > 2147483647)
		return (NULL);
	r_line = 1;
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	while (!ft_strchr(tmp, '\n') && r_line != 0)
	{
		r_line = read(fd, buffer, BUFFER_SIZE);
		if (r_line == -1)
			return (free(buffer), NULL);
		buffer[r_line] = '\0';
		tmp = ft_strjoin(tmp, buffer);
	}
	free(buffer);
	buffer = read_line(tmp);
	tmp = get_line(tmp, 0);
	return (free(tmp), buffer);
}

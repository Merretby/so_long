/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utiles.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moer-ret <moer-ret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 18:02:32 by moer-ret          #+#    #+#             */
/*   Updated: 2024/03/16 22:27:07 by moer-ret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_map(t_track *position, char *buffer2)
{
	if (!(position->flag == 1 && position->c_count == position->c_count_cpy))
		ft_error("INVALID MAP", buffer2, position);
}

static void	**free_aloc(char **fr)
{
	size_t	i;

	i = 0;
	while (fr[i])
	{
		free(fr[i]);
		i++;
	}
	free (fr);
	return (0);
}

static char	*small_alloc(char *str, int *index, char separator)
{
	char	*ptr;
	int		len;
	int		pos;
	int		k;

	len = 0;
	while (str[*index] == separator && str[*index])
		(*index)++;
	pos = *index;
	while (str[*index] != separator && str[*index])
		(*index)++;
	len = *index - pos;
	ptr = malloc(sizeof(char) * (len + 1));
	if (!ptr)
		return (*free_aloc(&ptr));
	k = 0;
	while (k < len)
	{
		ptr[k] = str[pos];
		k++;
		pos++;
	}
	ptr[k] = '\0';
	return (ptr);
}

static int	count_words(char *str, char c)
{
	size_t	wo;
	size_t	i;

	wo = 0;
	i = 0;
	while (str[i])
	{
		while (str[i] == c)
			i++;
		if (str[i])
			wo++;
		while (str[i] && str[i] != c)
			i++;
	}
	return (wo);
}

char	**ft_split(char *s, char c)
{
	char	**ptr;
	int		i;
	int		count;
	int		j;

	j = 0;
	if (s == NULL)
		return (NULL);
	count = count_words(s, c);
	ptr = (char **)malloc(sizeof(char *) * (count + 1));
	if (!ptr)
		return (NULL);
	ptr[count] = NULL;
	i = 0;
	while (j < count)
	{
		ptr[j] = small_alloc(s, &i, c);
		j++;
	}
	return (ptr);
}

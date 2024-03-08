/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moer-ret <moer-ret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 20:49:13 by moer-ret          #+#    #+#             */
/*   Updated: 2024/03/08 20:51:01 by moer-ret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error(char *err)
{
	ft_putstr(err);
	exit (1);
}

void	ft_putstr(char *s)
{
	int	i;

	i = 0;
	if (s != NULL)
	{
		while (s[i])
		{
			write(2, &s[i], 1);
			i++;
		}
		write(2, "\n", 1);
	}
}

void	**free_aloc(char **fr)
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

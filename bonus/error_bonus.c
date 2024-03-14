/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moer-ret <moer-ret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 20:49:13 by moer-ret          #+#    #+#             */
/*   Updated: 2024/03/14 00:39:55 by moer-ret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	error(char *err)
{
	ft_putstri(err);
	exit (1);
}

void	ft_error(char *err, char *tmp, t_track *game)
{
	if (game->map != NULL)
		free_aloc(game->map);
	free (tmp);
	ft_putstri(err);
	exit (1);
}

void	ft_mssage(char *str, t_game *game)
{
	free_aloc(game->track.map);
	mlx_destroy_window(game->mlx_in, game->mlx_window);
	destroy_textures(game);
	mlx_destroy_display(game->mlx_in);
	free(game->mlx_in);
	print_str(str);
	exit (0);
}

void	print_str(char *s)
{
	int	i;

	i = 0;
	if (s != NULL)
	{
		while (s[i])
		{
			write(1, &s[i], 1);
			i++;
		}
		write(1, "\n", 1);
	}
}

void	ft_putstri(char *s)
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

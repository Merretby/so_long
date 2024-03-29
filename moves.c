/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moer-ret <moer-ret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 21:17:06 by moer-ret          #+#    #+#             */
/*   Updated: 2024/03/16 22:30:53 by moer-ret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_counter(void)
{
	static int	i;

	ft_printf("move : %d\n", i++);
}

void	move_up(int x, int y, t_game *game)
{
	if (game->track.map[x][y] == '1' || \
	(game->track.map[x][y] == 'E' && \
	game->track.p_collected != game->track.c_count))
		return ;
	if (game->track.map[x][y] == 'E')
	{
		if (game->track.p_collected == game->track.c_count)
		{
			ft_free(game->track.map);
			mlx_destroy_window(game->mlx_in, game->mlx_window);
			destroy_textures(game);
			mlx_destroy_display(game->mlx_in);
			free(game->mlx_in);
			ft_message("YOU WIN!!");
			exit(0);
		}
	}
	else if (game->track.map[x][y] == 'C')
		game->track.p_collected++;
	game->track.map[x][y] = 'P';
	game->track.map[game->track.x][game->track.y] = '0';
	game->track.x--;
	move_counter();
	display_map(game, 0);
}

void	move_down(int x, int y, t_game *game)
{
	if (game->track.map[x][y] == '1' || \
	(game->track.map[x][y] == 'E' && \
	game->track.p_collected != game->track.c_count))
		return ;
	if (game->track.map[x][y] == 'E')
	{
		if (game->track.p_collected == game->track.c_count)
		{
			ft_free(game->track.map);
			mlx_destroy_window(game->mlx_in, game->mlx_window);
			destroy_textures(game);
			mlx_destroy_display(game->mlx_in);
			free(game->mlx_in);
			ft_message("YOU WIN!!");
			exit(0);
		}
	}
	else if (game->track.map[x][y] == 'C')
		game->track.p_collected++;
	game->track.map[x][y] = 'P';
	game->track.map[game->track.x][game->track.y] = '0';
	game->track.x++;
	move_counter();
	display_map(game, 1);
}

void	move_left(int x, int y, t_game *game)
{
	if (game->track.map[x][y] == '1' || \
	(game->track.map[x][y] == 'E' && \
	game->track.p_collected != game->track.c_count))
		return ;
	if (game->track.map[x][y] == 'E')
	{
		if (game->track.p_collected == game->track.c_count)
		{
			ft_free(game->track.map);
			mlx_destroy_window(game->mlx_in, game->mlx_window);
			destroy_textures(game);
			mlx_destroy_display(game->mlx_in);
			free(game->mlx_in);
			ft_message("YOU WIN!!");
			exit(0);
		}
	}
	else if (game->track.map[x][y] == 'C')
		game->track.p_collected++;
	game->track.map[x][y] = 'P';
	game->track.map[game->track.x][game->track.y] = '0';
	game->track.y--;
	move_counter();
	display_map(game, 0);
}

void	move_right(int x, int y, t_game *game)
{
	if (game->track.map[x][y] == '1' || \
	(game->track.map[x][y] == 'E' && \
	game->track.p_collected != game->track.c_count))
		return ;
	if (game->track.map[x][y] == 'E')
	{
		if (game->track.p_collected == game->track.c_count)
		{
			ft_free(game->track.map);
			mlx_destroy_window(game->mlx_in, game->mlx_window);
			destroy_textures(game);
			mlx_destroy_display(game->mlx_in);
			free(game->mlx_in);
			ft_message("YOU WIN!!");
			exit(0);
		}
	}
	else if (game->track.map[x][y] == 'C')
		game->track.p_collected++;
	game->track.map[x][y] = 'P';
	game->track.map[game->track.x][game->track.y] = '0';
	game->track.y++;
	move_counter();
	display_map(game, 1);
}

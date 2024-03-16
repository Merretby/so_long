/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moer-ret <moer-ret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 19:31:36 by moer-ret          #+#    #+#             */
/*   Updated: 2024/03/16 22:29:49 by moer-ret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <limits.h> 
# include <fcntl.h>
# include <X11/keysym.h>
# include <X11/X.h>
# include "mlx.h"

typedef struct s_texture
{
	void	*player_img_left;
	void	*player_img_right;
	void	*coin_img;
	void	*exit_img_open;
	void	*exit_img_close;
	void	*wall_img;
	void	*space_img;
}	t_texture;

typedef struct s_tarck
{
	char	**map;
	int		c_count_cpy;
	int		x;
	int		y;
	int		flag;
	int		p_collected;
	int		c_count;
	int		p_count;
	int		e_count;
}	t_track;

typedef struct s_game
{
	void		*mlx_window;
	void		*mlx_in;
	int			line_len;
	t_texture	texture;
	t_track		track;
}	t_game;

//parsing
void	check1(t_track *position, int c_l, char *buffer2);
void	check_2(t_track *position, char *buffer2);
void	check3(char *buffer2, t_track *position);
void	parsing_map(char **av, char *buffer, t_game *game, int c_line);
void	check_map(t_track *position, char *buffer2);
void	floodfill(int x, int y, char **map, t_track *game);
void	po_player(t_track *position);
void	check_argument(char **av);
//hellper
char	*get_next_line(int fd);
int		ft_strlen(char *str);
char	*ft_strchr(char *str, int c);
char	*ft_strdup(char *str);
char	*ft_strjoin(char *s1, char *s2);
char	**ft_split(char *s, char c);
void	ft_message(char *str);
void	print_str(char *s);
//for_error
void	ft_free(char **fr);
void	ft_putstri(char *s);
void	error(char *err);
void	ft_error(char *err, char *tmp, t_track *game);
void	destroy_textures(t_game *game);
//moves
void	move_up(int x, int y, t_game *game);
void	move_down(int x, int y, t_game *game);
void	move_left(int x, int y, t_game *game);
void	move_right(int x, int y, t_game *game);
//so_long
void	init_texture(t_game *game);
void	so_long(t_game *game);
void	display_map(t_game *game, int flag);
void	po_player(t_track *position);
int		lentgh(char **map);
int		ft_close(t_game *game);
int		ft_printf(char *str, ...);

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

#endif
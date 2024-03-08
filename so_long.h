/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moer-ret <moer-ret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 19:31:36 by moer-ret          #+#    #+#             */
/*   Updated: 2024/03/08 21:24:25 by moer-ret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <limits.h> 
# include <fcntl.h>

typedef struct s_tarck
{
    int x;
    int y;
    int flag;
    int c_count;
}   t_track;
//parsing
void	check(char **tmp, int c_line);
void	check_2(char **tmp, t_track *position);
void	check3(char *buffer2, t_track *position);
void	read_map(char **av, char *buffer, t_track *position);
void	check_map(char **map);
void  floodfill(int x, int y, char **map, t_track *game);
void	po_player(char **map, t_track *position);
//hellper
char	*get_next_line(int fd);
int		ft_strlen(char *str);
char	*ft_strchr(char *str, int c);
char	*ft_strdup(char *str);
char	*ft_strjoin(char *s1, char *s2);
char	**ft_split(char const *s, char c);
//for_error
void	**free_aloc(char **fr);
void	ft_putstr(char *s);
void	error(char *err);

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

#endif
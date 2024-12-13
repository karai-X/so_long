/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: karai <karai@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 19:12:41 by karai             #+#    #+#             */
/*   Updated: 2024/12/13 21:08:51 by karai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "ft_printf.h"
# include "get_next_line.h"
# include "libft.h"
# include <fcntl.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>

# define BLOCK_WIDTH 64
# define BLOCK_HEIGHT 64
# define UP 1
# define RIGHT 2
# define DOWN 3
# define LEFT 4
# define UP_ARROW 65362
# define RIGHT_ARROW 65363
# define DOWN_ARROW 65364
# define LEFT_ARROW 65361
# define ESCAPE 65307

typedef struct s_mapdata
{
	void	*mlx;
	void	*mlx_win;
	int		ny;
	int		nx;
	int		win_height;
	int		win_width;
	char	**map;
	void	*tile;
	void	*dolphin;
	void	*fish;
	void	*goal;
	void	*leaf;
	int		getcoin;
	int		totalcoin;
	int		move_cnt;
	int		reachable_coin;
}			t_mapdata;

void		get_width_height_ec(char *file_name, t_mapdata *md);
char		**get_map(char *file_name, t_mapdata *md);
void		cnt_totalcoin(t_mapdata *md);

void		error_check_main(t_mapdata *md);

bool		is_playable(t_mapdata *md);
void		dfs_coin(t_mapdata *md, unsigned int *reach, int ny, int nx);
void		dfs_coin_part(t_mapdata *md, unsigned int *reach, int ny, int nx);

bool		map_error_player(t_mapdata *md);
bool		map_error_end(t_mapdata *md);
bool		map_error_coin(t_mapdata *md);
bool		surrounded_leaf_is_else(t_mapdata *md);

void		free2dim(char **str);

#endif

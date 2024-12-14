/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: karai <karai@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 19:12:41 by karai             #+#    #+#             */
/*   Updated: 2024/12/14 12:16:56 by karai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "ft_printf.h"
# include "get_next_line.h"
# include "libft.h"
# include "mlx.h"
# include <fcntl.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>

# define BLOCK_WIDTH 64
# define BLOCK_HEIGHT 64
# define UP_ARROW 65362
# define RIGHT_ARROW 65363
# define DOWN_ARROW 65364
# define LEFT_ARROW 65361
# define ESCAPE 65307
# define IMG_TILE "./textures/tile.xpm"
# define IMG_DOLPHIN "./textures/dolphin.xpm"
# define IMG_FISH "./textures/fish.xpm"
# define IMG_LEAF "./textures/leaf.xpm"
# define IMG_GOAL "./textures/goal.xpm"
# define IMG_GOAL_BLOCK "./textures/goal_block.xpm"

typedef struct s_mapdata
{
	void	*mlx;
	void	*mlx_win;
	size_t	ny;
	size_t	nx;
	size_t	gy;
	size_t	gx;
	size_t	win_height;
	size_t	win_width;
	char	**map;
	void	*tile;
	void	*dolphin;
	void	*fish;
	void	*goal;
	void	*leaf;
	void	*goal_block;
	size_t	getcoin;
	size_t	totalcoin;
	size_t	move_cnt;
	size_t	reachable_coin;
}			t_mapdata;

int			main(int argc, char *argv[]);

void		show_image(t_mapdata *md, size_t i, size_t j);
int			ft_key_hook(int keycode, t_mapdata *md);
void		finish(t_mapdata *md);
int			map_close(t_mapdata *md);
void		initialize_window(t_mapdata *md);

void		move(t_mapdata *md, size_t dy, size_t dx);
void		move_part(t_mapdata *md, size_t my, size_t mx);

void		get_width_height_ec(char *file_name, t_mapdata *md);
void		get_width_height_ec_part(char *line, int fd, t_mapdata *md);
char		**get_map(char *file_name, t_mapdata *md);
void		get_map_part(int fd, char **map, t_mapdata *md);
void		cnt_totalcoin(t_mapdata *md);

void		error_check_main(t_mapdata *md, char *str);
bool		error_check_file_name(char *str);

bool		is_playable(t_mapdata *md);
void		dfs_coin(t_mapdata *md, unsigned char *reach, size_t ny, size_t nx);
void		dfs_coin_part(t_mapdata *md, unsigned char *reach, size_t ny,
				size_t nx);
bool		is_reach_end(t_mapdata *md, unsigned char *reach, size_t ny,
				size_t nx);
bool		is_reach_end_part(t_mapdata *md, unsigned char *reach, size_t ny,
				size_t nx);

bool		map_error_player(t_mapdata *md);
bool		map_error_end(t_mapdata *md);
bool		map_error_coin(t_mapdata *md);
bool		surrounded_leaf_is_else(t_mapdata *md);

void		free2dim(char **str);

#endif

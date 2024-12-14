/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility_mlx.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: karai <karai@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 12:03:33 by karai             #+#    #+#             */
/*   Updated: 2024/12/14 12:16:25 by karai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	show_image(t_mapdata *md, size_t i, size_t j)
{
	if (md->map[i][j] == '0')
		mlx_put_image_to_window(md->mlx, md->mlx_win, md->tile, j * BLOCK_WIDTH,
			i * BLOCK_HEIGHT);
	else if (md->map[i][j] == '1')
		mlx_put_image_to_window(md->mlx, md->mlx_win, md->leaf, j * BLOCK_WIDTH,
			i * BLOCK_HEIGHT);
	else if (md->map[i][j] == 'C')
		mlx_put_image_to_window(md->mlx, md->mlx_win, md->fish, j * BLOCK_WIDTH,
			i * BLOCK_HEIGHT);
	else if (md->map[i][j] == 'P')
		mlx_put_image_to_window(md->mlx, md->mlx_win, md->dolphin, j
			* BLOCK_WIDTH, i * BLOCK_HEIGHT);
	else if (md->map[i][j] == 'E')
		mlx_put_image_to_window(md->mlx, md->mlx_win, md->goal_block, j
			* BLOCK_WIDTH, i * BLOCK_HEIGHT);
	else if (md->map[i][j] == 'O')
		mlx_put_image_to_window(md->mlx, md->mlx_win, md->goal, j * BLOCK_WIDTH,
			i * BLOCK_HEIGHT);
}

int	ft_key_hook(int keycode, t_mapdata *md)
{
	if (keycode == ESCAPE)
		exit(0);
	if (keycode == 'w' || keycode == UP_ARROW)
	{
		move(md, -1, 0);
	}
	if (keycode == 'd' || keycode == RIGHT_ARROW)
	{
		move(md, 0, 1);
	}
	if (keycode == 's' || keycode == DOWN_ARROW)
	{
		move(md, 1, 0);
	}
	if (keycode == 'a' || keycode == LEFT_ARROW)
	{
		move(md, 0, -1);
	}
	return (0);
}

void	finish(t_mapdata *md)
{
	free2dim(md->map);
	mlx_destroy_image(md->mlx, md->goal);
	mlx_destroy_image(md->mlx, md->dolphin);
	mlx_destroy_image(md->mlx, md->fish);
	mlx_destroy_image(md->mlx, md->tile);
	mlx_destroy_image(md->mlx, md->leaf);
	mlx_destroy_window(md->mlx, md->mlx_win);
	mlx_destroy_display(md->mlx);
	free(md->mlx);
}

int	map_close(t_mapdata *md)
{
	finish(md);
	ft_printf("You reached goal.\n");
	exit(0);
}

void	initialize_window(t_mapdata *md)
{
	size_t	i;
	int		tmp1;

	md->mlx = mlx_init();
	md->mlx_win = mlx_new_window(md->mlx, BLOCK_WIDTH * md->win_width,
			BLOCK_HEIGHT * md->win_height, "./so_long");
	md->tile = mlx_xpm_file_to_image(md->mlx, IMG_TILE, &tmp1, &tmp1);
	md->fish = mlx_xpm_file_to_image(md->mlx, IMG_FISH, &tmp1, &tmp1);
	md->dolphin = mlx_xpm_file_to_image(md->mlx, IMG_DOLPHIN, &tmp1, &tmp1);
	md->leaf = mlx_xpm_file_to_image(md->mlx, IMG_LEAF, &tmp1, &tmp1);
	md->goal = mlx_xpm_file_to_image(md->mlx, IMG_GOAL, &tmp1, &tmp1);
	md->goal_block = mlx_xpm_file_to_image(md->mlx, IMG_GOAL_BLOCK, &tmp1,
			&tmp1);
	i = 0;
	while (i < md->win_width * md->win_height)
	{
		show_image(md, i / md->win_width, i % md->win_width);
		i += 1;
	}
}

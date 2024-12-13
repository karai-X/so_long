/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: karai <karai@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 19:05:25 by karai             #+#    #+#             */
/*   Updated: 2024/12/13 20:54:12 by karai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "so_long.h"

const char	*img_tile = "./image/tile.xpm";
const char	*img_dolphin = "./image/dolphin.xpm";
const char	*img_fish = "./image/fish.xpm";
const char	*img_leaf = "./image/leaf.xpm";
const char	*img_goal = "./image/goal.xpm";

void	show_image(t_mapdata *md, int i, int j)
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
	{
		mlx_put_image_to_window(md->mlx, md->mlx_win, md->dolphin, j
			* BLOCK_WIDTH, i * BLOCK_HEIGHT);
	}
	else if (md->map[i][j] == 'E')
		mlx_put_image_to_window(md->mlx, md->mlx_win, md->goal, j * BLOCK_WIDTH,
			i * BLOCK_HEIGHT);
}

void	move(t_mapdata *md, int dy, int dx)
{
	int	my;
	int	mx;

	my = md->ny + dy;
	mx = md->nx + dx;
	if (md->map[my][mx] == '1' || (md->map[my][mx] == 'E'
			&& md->totalcoin != md->getcoin))
		return ;
	else if (md->map[my][mx] == 'E' && md->totalcoin == md->getcoin)
	{
		ft_printf("Move Count: %d\n", md->move_cnt + 1);
		exit(0);
	}
	else if (md->map[my][mx] == '0')
	{
		md->map[my][mx] = 'P';
		md->map[md->ny][md->nx] = '0';
	}
	else if (md->map[my][mx] == 'C')
	{
		md->map[my][mx] = 'P';
		md->map[md->ny][md->nx] = '0';
		md->getcoin += 1;
	}
	show_image(md, my, mx);
	show_image(md, md->ny, md->nx);
	md->ny = my;
	md->nx = mx;
	md->move_cnt += 1;
	ft_printf("Move Count: %d\n", md->move_cnt);
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

int	main(int argc, char *argv[])
{
	int			img_width;
	int			img_height;
	int			i;
	t_mapdata	md[1];

	md->getcoin = 0;
	get_width_height_ec(argv[1], md);
	get_map(argv[1], md);
	cnt_totalcoin(md);
	error_check_main(md);
	md->mlx = mlx_init();
	md->mlx_win = mlx_new_window(md->mlx, BLOCK_WIDTH * md->win_width,
			BLOCK_HEIGHT * md->win_height, "./so_long");
	md->tile = mlx_xpm_file_to_image(md->mlx, (char *)img_tile, &img_width,
			&img_height);
	md->fish = mlx_xpm_file_to_image(md->mlx, (char *)img_fish, &img_width,
			&img_height);
	md->dolphin = mlx_xpm_file_to_image(md->mlx, (char *)img_dolphin,
			&img_width, &img_height);
	md->leaf = mlx_xpm_file_to_image(md->mlx, (char *)img_leaf, &img_width,
			&img_height);
	md->goal = mlx_xpm_file_to_image(md->mlx, (char *)img_goal, &img_width,
			&img_height);
	i = 0;
	while (i < md->win_width * md->win_height)
	{
		show_image(md, i / md->win_width, i % md->win_width);
		i += 1;
	}
	md->move_cnt = 0;
	mlx_key_hook(md->mlx_win, ft_key_hook, md);
	mlx_loop(md->mlx);
}

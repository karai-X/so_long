/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: karai <karai@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 08:30:53 by karai             #+#    #+#             */
/*   Updated: 2024/12/15 08:54:08 by karai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	initialize_window(t_mapdata *md)
{
	size_t	i;

	initialize_window_part1(md);
	initialize_window_part2(md);
	initialize_window_part3(md);
	initialize_window_part4(md);
	initialize_window_part5(md);
	initialize_window_part6(md);
	i = 0;
	while (i < md->win_width * md->win_height)
	{
		show_image(md, i / md->win_width, i % md->win_width);
		i += 1;
	}
}

void	initialize_window_part1(t_mapdata *md)
{
	md->mlx = mlx_init();
	if (md->mlx == NULL)
	{
		free2dim(md->map);
		ft_printf("Processing Error\n");
		exit(1);
	}
	md->mlx_win = mlx_new_window(md->mlx, BLOCK_WIDTH * md->win_width,
			BLOCK_HEIGHT * md->win_height, "./so_long");
	if (md->mlx_win == NULL)
	{
		free2dim(md->map);
		mlx_destroy_display(md->mlx);
		free(md->mlx);
		ft_printf("Processing Error\n");
		exit(1);
	}
}

void	initialize_window_part2(t_mapdata *md)
{
	int	tmp1;

	md->tile = mlx_xpm_file_to_image(md->mlx, IMG_TILE, &tmp1, &tmp1);
	if (md->tile == NULL)
	{
		free2dim(md->map);
		mlx_destroy_window(md->mlx, md->mlx_win);
		mlx_destroy_display(md->mlx);
		free(md->mlx);
		ft_printf("Processing Error");
		exit(1);
	}
	md->fish = mlx_xpm_file_to_image(md->mlx, IMG_FISH, &tmp1, &tmp1);
	if (md->fish == NULL)
	{
		free2dim(md->map);
		mlx_destroy_image(md->mlx, md->tile);
		mlx_destroy_window(md->mlx, md->mlx_win);
		mlx_destroy_display(md->mlx);
		free(md->mlx);
		ft_printf("Processing Error");
		exit(1);
	}
}

void	initialize_window_part3(t_mapdata *md)
{
	int	tmp1;

	md->dolphin = mlx_xpm_file_to_image(md->mlx, IMG_DOLPHIN, &tmp1, &tmp1);
	if (md->dolphin == NULL)
	{
		free2dim(md->map);
		mlx_destroy_image(md->mlx, md->tile);
		mlx_destroy_image(md->mlx, md->fish);
		mlx_destroy_window(md->mlx, md->mlx_win);
		mlx_destroy_display(md->mlx);
		free(md->mlx);
		ft_printf("Processing Error\n");
		exit(1);
	}
}

void	initialize_window_part4(t_mapdata *md)
{
	int	tmp1;

	md->leaf = mlx_xpm_file_to_image(md->mlx, IMG_LEAF, &tmp1, &tmp1);
	if (md->leaf == NULL)
	{
		free2dim(md->map);
		mlx_destroy_image(md->mlx, md->tile);
		mlx_destroy_image(md->mlx, md->fish);
		mlx_destroy_image(md->mlx, md->dolphin);
		mlx_destroy_window(md->mlx, md->mlx_win);
		mlx_destroy_display(md->mlx);
		free(md->mlx);
		ft_printf("Processing Error\n");
		exit(1);
	}
}

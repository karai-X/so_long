/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: karai <karai@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 08:44:25 by karai             #+#    #+#             */
/*   Updated: 2024/12/15 08:44:51 by karai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	initialize_window_part5(t_mapdata *md)
{
	int	tmp1;

	md->goal = mlx_xpm_file_to_image(md->mlx, IMG_GOAL, &tmp1, &tmp1);
	if (md->goal == NULL)
	{
		free2dim(md->map);
		mlx_destroy_image(md->mlx, md->tile);
		mlx_destroy_image(md->mlx, md->fish);
		mlx_destroy_image(md->mlx, md->dolphin);
		mlx_destroy_image(md->mlx, md->leaf);
		mlx_destroy_window(md->mlx, md->mlx_win);
		mlx_destroy_display(md->mlx);
		free(md->mlx);
		ft_printf("Processing Error\n");
		exit(1);
	}
}

void	initialize_window_part6(t_mapdata *md)
{
	int	tmp1;

	md->goal_block = mlx_xpm_file_to_image(md->mlx, IMG_GOAL_BLOCK, &tmp1,
			&tmp1);
	if (md->goal_block == NULL)
	{
		free2dim(md->map);
		mlx_destroy_image(md->mlx, md->tile);
		mlx_destroy_image(md->mlx, md->fish);
		mlx_destroy_image(md->mlx, md->dolphin);
		mlx_destroy_image(md->mlx, md->leaf);
		mlx_destroy_image(md->mlx, md->goal);
		mlx_destroy_window(md->mlx, md->mlx_win);
		mlx_destroy_display(md->mlx);
		free(md->mlx);
		ft_printf("Processing Error\n");
		exit(1);
	}
}

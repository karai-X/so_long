/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check_playable.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: karai <karai@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 20:59:10 by karai             #+#    #+#             */
/*   Updated: 2024/12/13 21:18:03 by karai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

bool	is_playable(t_mapdata *md)
{
	unsigned int	*reach;

	reach = (unsigned int *)ft_calloc(sizeof(unsigned int), md->win_height
			* md->win_width);
	if (reach == NULL)
	{
		ft_printf("Processing Error\n");
		free2dim(md->map);
		exit(0);
	}
	md->reachable_coin = 0;
	dfs_coin(md, reach, md->ny, md->nx);
	free(reach);
	if (md->reachable_coin != md->totalcoin)
		return (false);
}

void	dfs_coin(t_mapdata *md, unsigned int *reach, int ny, int nx)
{
	dfs_coin_part(md, reach, ny - 1, nx);
	dfs_coin_part(md, reach, ny + 1, nx);
	dfs_coin_part(md, reach, ny, nx - 1);
	dfs_coin_part(md, reach, ny, nx + 1);
}

void	dfs_coin_part(t_mapdata *md, unsigned int *reach, int ny, int nx)
{
	if (md->map[ny][nx] == '1' || md->map[ny][nx] == 'E')
		return ;
	else if (reach[ny * md->win_width + nx] == 1)
		return ;
	else if (md->map[ny][nx] == '0' || md->map[ny][nx] == 'P')
	{
		reach[ny * md->win_width + nx] = 1;
		dfs_coin(md, reach, ny, nx);
	}
	else if (md->map[ny][nx] == 'C')
	{
		reach[ny * md->win_width + nx] = 1;
		md->reachable_coin += 1;
		dfs_coin(md, reach, ny, nx);
	}
}

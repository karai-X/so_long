/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check_playable.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: karai <karai@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 20:59:10 by karai             #+#    #+#             */
/*   Updated: 2024/12/14 12:08:08 by karai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

bool	is_playable(t_mapdata *md)
{
	unsigned char	*reach;
	bool			tf;

	reach = (unsigned char *)ft_calloc(sizeof(unsigned char), md->win_height
			* md->win_width);
	if (reach == NULL)
	{
		ft_printf("Processing Error\n");
		free2dim(md->map);
		exit(0);
	}
	md->reachable_coin = 0;
	dfs_coin(md, reach, md->ny, md->nx);
	ft_bzero(reach, md->win_height * md->win_width);
	tf = is_reach_end(md, reach, md->ny, md->nx);
	free(reach);
	if (md->reachable_coin != md->totalcoin || tf == false)
		return (false);
	return (true);
}

void	dfs_coin(t_mapdata *md, unsigned char *reach, size_t ny, size_t nx)
{
	dfs_coin_part(md, reach, ny - 1, nx);
	dfs_coin_part(md, reach, ny + 1, nx);
	dfs_coin_part(md, reach, ny, nx - 1);
	dfs_coin_part(md, reach, ny, nx + 1);
}

void	dfs_coin_part(t_mapdata *md, unsigned char *reach, size_t ny, size_t nx)
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

bool	is_reach_end(t_mapdata *md, unsigned char *reach, size_t ny, size_t nx)
{
	if (is_reach_end_part(md, reach, ny - 1, nx))
		return (true);
	if (is_reach_end_part(md, reach, ny + 1, nx))
		return (true);
	if (is_reach_end_part(md, reach, ny, nx - 1))
		return (true);
	if (is_reach_end_part(md, reach, ny, nx + 1))
		return (true);
	return (false);
}

bool	is_reach_end_part(t_mapdata *md, unsigned char *reach, size_t ny,
		size_t nx)
{
	if (md->map[ny][nx] == '1')
		return (false);
	else if (reach[ny * md->win_width + nx] == 1)
		return (false);
	else if (md->map[ny][nx] == '0' || md->map[ny][nx] == 'P'
		|| md->map[ny][nx] == 'C')
	{
		reach[ny * md->win_width + nx] = 1;
		return (is_reach_end(md, reach, ny, nx));
	}
	else if (md->map[ny][nx] == 'E')
	{
		return (true);
	}
	return (false);
}

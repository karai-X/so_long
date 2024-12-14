/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: karai <karai@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 21:49:20 by karai             #+#    #+#             */
/*   Updated: 2024/12/14 12:10:03 by karai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

bool	map_error_player(t_mapdata *md)
{
	size_t			i;
	unsigned char	find_player;

	i = 0;
	find_player = 0;
	while (i < md->win_width * md->win_height)
	{
		if (md->map[i / md->win_width][i % md->win_width] == 'P')
		{
			if (find_player == 1)
				return (false);
			find_player = 1;
			md->ny = i / md->win_width;
			md->nx = i % md->win_width;
		}
		i += 1;
	}
	if (find_player == 1)
		return (true);
	return (false);
}

bool	map_error_end(t_mapdata *md)
{
	size_t			i;
	unsigned char	find_end;

	i = 0;
	find_end = 0;
	while (i < md->win_width * md->win_height)
	{
		if (md->map[i / md->win_width][i % md->win_width] == 'E')
		{
			md->gy = i / md->win_width;
			md->gx = i % md->win_width;
			if (find_end == 1)
				return (false);
			find_end = 1;
		}
		i += 1;
	}
	if (find_end == 1)
		return (true);
	return (false);
}

bool	map_error_coin(t_mapdata *md)
{
	size_t			i;
	unsigned char	find_coin;

	i = 0;
	find_coin = 0;
	while (i < md->win_width * md->win_height)
	{
		if (md->map[i / md->win_width][i % md->win_width] == 'C')
		{
			find_coin = 1;
		}
		i += 1;
	}
	if (find_coin == 1)
		return (true);
	return (false);
}

bool	surrounded_leaf_is_else(t_mapdata *md)
{
	size_t	i;
	size_t	ny;
	size_t	nx;

	i = 0;
	while (i < md->win_width * md->win_height)
	{
		ny = i / md->win_width;
		nx = i % md->win_width;
		if (md->map[ny][nx] != '0' && md->map[ny][nx] != '1'
			&& md->map[ny][nx] != 'P' && md->map[ny][nx] != 'C'
			&& md->map[ny][nx] != 'E')
			return (false);
		if (ny == 0 || ny == md->win_height - 1 || nx == 0
			|| nx == md->win_width - 1)
		{
			if (md->map[i / md->win_width][i % md->win_width] != '1')
				return (false);
		}
		i += 1;
	}
	return (true);
}

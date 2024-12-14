/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: karai <karai@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 11:19:41 by karai             #+#    #+#             */
/*   Updated: 2024/12/14 12:01:30 by karai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move(t_mapdata *md, size_t dy, size_t dx)
{
	size_t	my;
	size_t	mx;

	my = md->ny + dy;
	mx = md->nx + dx;
	if (md->map[my][mx] == '1' || md->map[my][mx] == 'E')
		return ;
	move_part(md, my, mx);
	show_image(md, my, mx);
	show_image(md, md->ny, md->nx);
	md->ny = my;
	md->nx = mx;
	md->move_cnt += 1;
	ft_printf("Move Count: %d\n", md->move_cnt);
}

void	move_part(t_mapdata *md, size_t my, size_t mx)
{
	if (md->map[my][mx] == 'O')
	{
		ft_printf("Move Count: %d\n", md->move_cnt + 1);
		finish(md);
		ft_printf("You reached goal.\n");
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
		if (md->getcoin == md->totalcoin)
		{
			md->map[md->gy][md->gx] = 'O';
			show_image(md, md->gy, md->gx);
		}
	}
}

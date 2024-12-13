/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preprocessing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: karai <karai@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 20:56:25 by karai             #+#    #+#             */
/*   Updated: 2024/12/13 20:42:38 by karai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	get_width_height_ec(char *file_name, t_mapdata *md)
{
	char	*line;
	int		fd;

	md->win_height = 0;
	fd = open(file_name, O_RDONLY);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
		{
			break ;
		}
		if (md->win_height == 0)
			md->win_width = ft_strlen(line) - 1;
		else
		{
			if (md->win_width != ft_strlen(line) - 1)
				ft_printf("error\n");
		}
		md->win_height += 1;
		free(line);
	}
	close(fd);
}

char	**get_map(char *file_name, t_mapdata *md)
{
	char	*line;
	int		fd;
	char	**map;
	int		i;

	map = (char **)malloc(sizeof(char *) * (md->win_height + 1));
	fd = open(file_name, O_RDONLY);
	i = 0;
	while (i < md->win_height)
	{
		map[i] = get_next_line(fd);
		if (!map[i])
		{
			// error processing
			break ;
		}
		i += 1;
	}
	map[i] = NULL;
	md->map = map;
	close(fd);
	return (md->map);
}

void	cnt_totalcoin(t_mapdata *md)
{
	int	i;

	md->totalcoin = 0;
	i = 0;
	while (i < md->win_width * md->win_height)
	{
		if (md->map[i / md->win_width][i % md->win_width] == 'C')
		{
			md->totalcoin += 1;
		}
		i += 1;
	}
}

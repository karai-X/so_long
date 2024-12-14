/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preprocessing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: karai <karai@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 20:56:25 by karai             #+#    #+#             */
/*   Updated: 2024/12/14 12:08:48 by karai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	get_width_height_ec(char *file_name, t_mapdata *md)
{
	char	*line;
	int		fd;

	md->win_height = 0;
	fd = open(file_name, O_RDONLY);
	if (fd == -1)
	{
		ft_printf("File is not found.\n");
		exit(1);
	}
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		get_width_height_ec_part(line, fd, md);
		md->win_height += 1;
		free(line);
	}
	close(fd);
}

void	get_width_height_ec_part(char *line, int fd, t_mapdata *md)
{
	if (md->win_height == 0)
		md->win_width = ft_strlen(line) - 1;
	else if (md->win_width != ft_strlen(line) - 1)
	{
		ft_printf("Map Error\n");
		free(line);
		close(fd);
		exit(2);
	}
}

char	**get_map(char *file_name, t_mapdata *md)
{
	int		fd;
	char	**map;

	map = (char **)malloc(sizeof(char *) * (md->win_height + 1));
	fd = open(file_name, O_RDONLY);
	if (fd == -1)
	{
		ft_printf("File is not found.\n");
		exit(1);
	}
	get_map_part(fd, map, md);
	close(fd);
	return (md->map);
}

void	get_map_part(int fd, char **map, t_mapdata *md)
{
	size_t	i;

	i = 0;
	while (i < md->win_height)
	{
		map[i] = get_next_line(fd);
		if (!map[i])
		{
			free2dim(map);
			ft_printf("Processing Error\n");
			exit(3);
		}
		i += 1;
	}
	map[i] = NULL;
	md->map = map;
}

void	cnt_totalcoin(t_mapdata *md)
{
	size_t	i;

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

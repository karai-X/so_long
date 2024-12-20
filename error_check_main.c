/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check_main.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: karai <karai@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 20:37:10 by karai             #+#    #+#             */
/*   Updated: 2024/12/14 11:11:18 by karai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error_check_main(t_mapdata *md, char *str)
{
	if (map_error_player(md) == false || map_error_end(md) == false
		|| map_error_coin(md) == false || surrounded_leaf_is_else(md) == false
		|| is_playable(md) == false)
	{
		ft_printf("Map Error\n");
		free2dim(md->map);
		exit(2);
	}
	if (error_check_file_name(str) == false)
	{
		ft_printf("File Name Error\n");
		free2dim(md->map);
		exit(4);
	}
}

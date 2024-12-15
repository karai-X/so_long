/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: karai <karai@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 19:05:25 by karai             #+#    #+#             */
/*   Updated: 2024/12/15 09:32:55 by karai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char *argv[])
{
	t_mapdata	md[1];

	if (argc != 2)
	{
		ft_printf("The number of argument is wrong. Error\n");
		return (5);
	}
	md->getcoin = 0;
	get_width_height_ec(argv[1], md);
	get_map(argv[1], md);
	cnt_totalcoin(md);
	error_check_main(md, argv[1]);
	initialize_window(md);
	md->move_cnt = 0;
	mlx_hook(md->mlx_win, 17, 0, map_close, md);
	mlx_key_hook(md->mlx_win, ft_key_hook, md);
	mlx_loop(md->mlx);
}

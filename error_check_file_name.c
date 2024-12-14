/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check_file_name.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: karai <karai@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 10:43:06 by karai             #+#    #+#             */
/*   Updated: 2024/12/14 10:49:41 by karai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

bool	error_check_file_name(char *str)
{
	size_t	len;

	len = ft_strlen(str);
	if (len < 4)
		return (false);
	if (str[len - 1] == 'r' && str[len - 2] == 'e' && str[len - 3] == 'b'
		&& str[len - 4] == '.')
		return (true);
	return (false);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmabel <jmabel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 15:56:55 by jmabel            #+#    #+#             */
/*   Updated: 2022/03/21 17:58:56 by jmabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_error_map(t_map *map, char error)
{
	if (error == 'm')
		ft_putstr_fd("Error: Invalid map\n", 2);
	else if (error == 'p')
		perror("Error");
	free(map->line);
	close(map->fd);
	exit (1);
}

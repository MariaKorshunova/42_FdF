/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_define_value.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmabel <jmabel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 19:02:06 by jmabel            #+#    #+#             */
/*   Updated: 2022/04/24 20:37:05 by jmabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	ft_fill_value(t_fdf *fdf, char **map_line, int nb_line)
{
	char	**cell;
	int		i;
	int		is_color;

	i = 0;
	is_color = 0;
	while (i < fdf->column)
	{
		cell = ft_split(map_line[i], ',');
		if (!cell)
		{
			ft_free_char_array(map_line, fdf->column);
			ft_error_allocate_arr(fdf, 'p');
		}
		fdf->map[nb_line][i] = ft_atoi_base_10(fdf, cell[0], map_line, cell);
		fdf->color[nb_line][i] = ft_atoi_base_16(fdf, cell[1], map_line, cell);
		if (cell[1] != '\0')
			is_color = 1;
		ft_free_char_array(cell, is_color + 1);
		i++;
	}
}

void	ft_define_map_value(t_fdf *fdf, int nb_line)
{
	char	**map_line;

	map_line = ft_split(fdf->line, ' ');
	if (!map_line)
		ft_error_allocate_arr(fdf, 'p');
	ft_fill_value(fdf, map_line, nb_line);
	ft_free_char_array(map_line, fdf->column);
}

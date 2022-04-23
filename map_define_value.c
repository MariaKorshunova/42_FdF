/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_define_value.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmabel <jmabel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 19:02:06 by jmabel            #+#    #+#             */
/*   Updated: 2022/04/23 21:09:35 by jmabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	ft_altitude(t_fdf *fdf, char **map_line, char **cell)
{
	int	i;
	// int	nb;

	i = 0;
	while (cell[0][i] != '\0')
	{
		if (ft_isdigit(cell[0][i]) == 0 && cell[0][i] != '\n')
			ft_error_allocate_cell(fdf, map_line, cell, 'm');
		i++;
	}
	// nb = ft_atoi_check_digits(fdf, map, str);
	// return (nb);
	return (0);
}

void	ft_define_map_value(t_fdf *fdf, int nb_line)
{
	char	**map_line;
	char	**cell;
	int		i;
	int		is_color;

	i = 0;
	is_color = 0;
	map_line = ft_split(fdf->line, ' ');
	if (!map_line)
		ft_error_allocate_arr(fdf, 'p');
	while (i < fdf->column)
	{
		cell = ft_split(map_line[i], ',');
		if (!cell)
		{
			ft_free_char_array(map_line, fdf->column);
			ft_error_allocate_arr(fdf, 'p');
		}
		fdf->map[nb_line][i] = ft_altitude(fdf, map_line, cell);
		if (cell[1] != '\0')
			is_color = 1;
		ft_free_char_array(cell, is_color + 1);
		i++;
	}
	ft_free_char_array(map_line, fdf->column);
}

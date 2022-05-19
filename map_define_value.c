/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_define_value.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmabel <jmabel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 19:02:06 by jmabel            #+#    #+#             */
/*   Updated: 2022/05/19 20:30:40 by jmabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	ft_define_maxmin_altitude(t_fdf *fdf, int line, int i)
{
	if (fdf->map[line][i] > fdf->max_alt)
		fdf->max_alt = fdf->map[line][i];
	if (fdf->map[line][i] < fdf->min_alt)
		fdf->min_alt = fdf->map[line][i];
}

static void	ft_fill_value(t_fdf *fdf, t_pars *parser, int line)
{
	int		i;
	int		is_color;

	i = 0;
	is_color = 0;
	while (i < fdf->column)
	{
		parser->cell = ft_split((parser->map_line)[i], ',');
		if (!(parser->cell))
		{
			ft_free_char_array(parser->map_line);
			ft_error_allocate_arr(fdf, parser, 'p');
		}
		fdf->map[line][i] = ft_atoi_base_10(fdf, parser, (parser->cell)[0]);
		ft_define_maxmin_altitude(fdf, line, i);
		fdf->color[line][i] = ft_atoi_base_16(fdf, parser, (parser->cell)[1]);
		ft_free_char_array(parser->cell);
		i++;
	}
}

void	ft_define_map_value(t_fdf *fdf, t_pars *parser, int nb_line)
{
	parser->map_line = ft_split(parser->line, ' ');
	if (!(parser->map_line))
		ft_error_allocate_arr(fdf, parser, 'p');
	ft_fill_value(fdf, parser, nb_line);
	ft_free_char_array(parser->map_line);
}

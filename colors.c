/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmabel <jmabel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 19:54:44 by jmabel            #+#    #+#             */
/*   Updated: 2022/04/29 21:24:46 by jmabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	ft_hex_to_rgb(int color, t_rgb *rgb)
{
	rgb->r = ((color >> 16) & 0xFF);
	rgb->g = ((color >> 8) & 0xFF);
	rgb->b = (color & 0xFF);
}

static float	ft_coefficient_altitude(int x, int x_min, int x_max)
{
	float	coef;

	coef = ((float)(x - x_min)) / (x_max - x_min);
	return (coef);
}

static void	ft_define_color(int *color, t_rgb *low_c, t_rgb *high_c, float coef)
{
	t_rgb		color_rgb;

	ft_hex_to_rgb(*color, &color_rgb);
	color_rgb.r = (int)(round(low_c->r + coef * (high_c->r - low_c->r)));
	color_rgb.g = (int)(round(low_c->g + coef * (high_c->g - low_c->g)));
	color_rgb.b = (int)(round(low_c->b + coef * (high_c->b - low_c->b)));
}

void	ft_set_colors(t_fdf *fdf)
{
	int		i;
	int		j;
	t_rgb	low_color;
	t_rgb	high_color;
	float	coef;

	i = 0;
	ft_hex_to_rgb(LOW_COLOR, &low_color);
	ft_hex_to_rgb(HIGH_COLOR, &high_color);
	while (i < fdf->row)
	{
		j = 0;
		while (j < fdf->column)
		{
			if (fdf->color[i][j] == 0)
			{
				coef = ft_coefficient_altitude(fdf->map[i][j],
						fdf->min_alt, fdf->max_alt);
				ft_define_color(&(fdf->color[i][j]),
					&low_color, &high_color, coef);
			}
			j++;
		}
		i++;
		// printf("\n");
	}
}

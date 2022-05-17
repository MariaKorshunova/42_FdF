/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmabel <jmabel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 19:54:44 by jmabel            #+#    #+#             */
/*   Updated: 2022/05/17 20:10:04 by jmabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_hex_to_rgb(int color, t_rgb *rgb)
{
	rgb->r = ((color >> 16) & 0xFF);
	rgb->g = ((color >> 8) & 0xFF);
	rgb->b = (color & 0xFF);
}

static void	ft_define_color(int *color, t_rgb *low_c, t_rgb *high_c, float coef)
{
	t_rgb		color_rgb;

	ft_hex_to_rgb(*color, &color_rgb);
	color_rgb.r = (int)(round(low_c->r + coef * (high_c->r - low_c->r)));
	color_rgb.g = (int)(round(low_c->g + coef * (high_c->g - low_c->g)));
	color_rgb.b = (int)(round(low_c->b + coef * (high_c->b - low_c->b)));
	*color = color_rgb.r << 16 | color_rgb.g << 8 | color_rgb.b;
}

static void	ft_define_color_flatland(t_fdf *fdf)
{
	int	i;
	int	j;

	i = 0;
	while (i < fdf->row)
	{
		j = 0;
		while (j < fdf->column)
		{
			if (fdf->color[i][j] == 0)
				fdf->color[i][j] = 0xFFFFFF;
			j++;
		}
		i++;
	}
}

static void	ft_define_color_altitude(t_fdf *fdf, t_rgb *low_c, t_rgb *high_c)
{
	int		i;
	int		j;
	float	coef;

	i = 0;
	while (i < fdf->row)
	{
		j = 0;
		while (j < fdf->column)
		{
			if (fdf->color[i][j] == 0)
			{
				coef = ((float)(fdf->map[i][j] - fdf->min_alt))
					/ (fdf->max_alt - fdf->min_alt);
				ft_define_color(&(fdf->color[i][j]), low_c, high_c, coef);
			}
			j++;
		}
	i++;
	}
}

void	ft_set_colors(t_fdf *fdf)
{
	t_rgb	low_color;
	t_rgb	high_color;

	ft_hex_to_rgb(LOW_COLOR, &low_color);
	ft_hex_to_rgb(HIGH_COLOR, &high_color);
	if ((fdf->max_alt - fdf->min_alt) == 0)
		ft_define_color_flatland(fdf);
	else
		ft_define_color_altitude(fdf, &low_color, &high_color);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   default_value_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmabel <jmabel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 19:41:30 by jmabel            #+#    #+#             */
/*   Updated: 2022/05/21 18:20:35 by jmabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

static void	ft_define_zoom(t_fdf *fdf)
{
	float	zoom_x;
	float	zoom_y;

	zoom_x = ceil(0.6 * WIDTH / fdf->column);
	zoom_y = ceil(0.6 * HEIGHT / fdf->row);
	if (zoom_x <= zoom_y)
		fdf->scale = zoom_x;
	else
		fdf->scale = zoom_y;
}

static void	ft_define_altitude_zoom(t_fdf *fdf)
{
	int	i;
	int	j;
	int	max;

	if (fdf->column > fdf->row)
		max = fdf->column;
	else
		max = fdf->row;
	if (((float)(fdf->max_alt - fdf->min_alt) / max) > 1)
	{
		i = 0;
		while (i < fdf->row)
		{
			j = 0;
			while (j < fdf->column)
			{
				fdf->map[i][j] = (int)(round((float)(fdf->map[i][j]) * 0.1));
				j++;
			}
			i++;
		}
	}
}

void	ft_default_value(t_fdf *fdf)
{
	ft_define_zoom(fdf);
	ft_define_altitude_zoom(fdf);
	fdf->angle.x = 0;
	fdf->angle.y = 0;
	fdf->angle.z = 0;
	fdf->translate.x = 0;
	fdf->translate.y = 0;
	fdf->zoom = 1;
}

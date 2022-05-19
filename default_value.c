/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   default_value.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmabel <jmabel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 20:29:36 by jmabel            #+#    #+#             */
/*   Updated: 2022/05/19 21:47:59 by jmabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	ft_define_zoom(t_fdf *fdf)
{
	float	zoom_x;
	float	zoom_y;

	zoom_x = ceil(0.6 * WIDTH / fdf->column);
	zoom_y = ceil(0.6 * HEIGHT / fdf->row);
	if (zoom_x <= zoom_y)
		fdf->zoom = zoom_x;
	else
		fdf->zoom = zoom_y;
}

static void	ft_define_rotate_angle(t_fdf *fdf)
{
	fdf->angle.x = 20;
	fdf->angle.y = 0;
	fdf->angle.z = -20;
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
	ft_define_rotate_angle(fdf);
	ft_define_altitude_zoom(fdf);
}

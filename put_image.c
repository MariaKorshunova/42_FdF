/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_image.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmabel <jmabel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 18:00:46 by jmabel            #+#    #+#             */
/*   Updated: 2022/05/03 18:49:30 by jmabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_mlx_pixel_put_img(t_img	*img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bpp / 8));
	*(unsigned int *)dst = color;
}

static void	ft_draw_line_left(t_fdf *fdf, t_img *img, int i, int j)
{
	t_coord	p0;
	t_coord	p1;

	p0.x = j * fdf->zoom;
	p0.y = i * fdf->zoom;
	p1.x = (j + 1) * fdf->zoom;
	p1.y = i * fdf->zoom;
	ft_line(img, p0, p1, fdf->color[i][j]);
}

static void	ft_draw_line_down(t_fdf *fdf, t_img *img, int i, int j)
{
	t_coord	p0;
	t_coord	p1;

	p0.x = j * fdf->zoom;
	p0.y = i * fdf->zoom;
	p1.x = j * fdf->zoom;
	p1.y = (i + 1) * fdf->zoom;
	ft_line(img, p0, p1, fdf->color[i][j]);
}

void	ft_draw_lines(t_fdf *fdf, t_img *img)
{
	int		i;
	int		j;

	i = 0;
	while (i < fdf->row)
	{
		j = 0;
		while (j < fdf->column - 1)
		{
			ft_draw_line_left(fdf, img, i, j);
			j++;
		}
		j = 0;
		if (i < (fdf->row - 1))
		{
			while (j < fdf->column)
			{
				ft_draw_line_down(fdf, img, i, j);
				j++;
			}
		}
		i++;
	}
}

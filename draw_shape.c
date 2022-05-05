/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_shape.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmabel <jmabel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 18:55:19 by jmabel            #+#    #+#             */
/*   Updated: 2022/05/05 20:12:06 by jmabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	ft_draw_line_left(t_fdf *fdf, t_img *img, int i, int j)
{
	t_coord	p0;
	t_coord	p1;

	p0.x = j * fdf->zoom;
	p0.y = i * fdf->zoom;
	p0.color = fdf->color[i][j];
	p1.x = (j + 1) * fdf->zoom;
	p1.y = i * fdf->zoom;
	p1.color = fdf->color[i][j + 1];
	ft_line_gradient_color(img, p0, p1);
}

static void	ft_draw_line_down(t_fdf *fdf, t_img *img, int i, int j)
{
	t_coord	p0;
	t_coord	p1;

	p0.x = j * fdf->zoom;
	p0.y = i * fdf->zoom;
	p0.color = fdf->color[i][j];
	p1.x = j * fdf->zoom;
	p1.y = (i + 1) * fdf->zoom;
	p1.color = fdf->color[i + 1][j];
	ft_line_gradient_color(img, p0, p1);
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

// void	ft_isometric(t_fdf *fdf, t_img *img)
// {
// 	int		i;
// 	int		j;

// 	i = 0;
// 	while (i < fdf->row)
// 	{
// 		j = 0;
// 		while (j < fdf->column)
// 		{
// 			j++;
// 		}
// 		i++;
// 	}
// }

// static void	ft_draw_line_left(t_fdf *fdf, t_img *img, int i, int j)
// {
// 	t_coord	p0;
// 	t_coord	p1;

// 	p0.x = ((j - i) * cos(0.8)) * fdf->zoom;
// 	p0.y = i * fdf->zoom;
// 	p0.color = fdf->color[i][j];
// 	p1.x = (j + 1) * fdf->zoom;
// 	p1.y = i * fdf->zoom;
// 	p1.color = fdf->color[i][j + 1];
// 	ft_line_gradient_color(img, p0, p1);
// }

// static void	ft_draw_line_down(t_fdf *fdf, t_img *img, int i, int j)
// {
// 	t_coord	p0;
// 	t_coord	p1;

// 	p0.x = j * fdf->zoom;
// 	p0.y = i * fdf->zoom;
// 	p0.color = fdf->color[i][j];
// 	p1.x = j * fdf->zoom;
// 	p1.y = (i + 1) * fdf->zoom;
// 	p1.color = fdf->color[i + 1][j];
// 	ft_line_gradient_color(img, p0, p1);
// }

// void	ft_draw_lines(t_fdf *fdf, t_img *img)
// {
// 	int		i;
// 	int		j;

// 	i = 0;
// 	while (i < fdf->row)
// 	{
// 		j = 0;
// 		while (j < fdf->column - 1)
// 		{
// 			ft_draw_line_left(fdf, img, i, j);
// 			j++;
// 		}
// 		j = 0;
// 		if (i < (fdf->row - 1))
// 		{
// 			while (j < fdf->column)
// 			{
// 				ft_draw_line_down(fdf, img, i, j);
// 				j++;
// 			}
// 		}
// 		i++;
// 	}
// }

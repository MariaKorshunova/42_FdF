/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmabel <jmabel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 19:23:31 by jmabel            #+#    #+#             */
/*   Updated: 2022/05/17 21:30:28 by jmabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	ft_define_step_diff(t_coord *p0, t_coord *p1,
		t_coord *step, t_coord *diff)
{
	if (p0->x <= p1->x)
		step->x = 1;
	else
		step->x = -1;
	if (p0->y <= p1->y)
		step->y = 1;
	else
		step->y = -1;
	diff->x = (int)(abs(p1->x - p0->x));
	diff->y = -(int)(abs(p1->y - p0->y));
}

static int	ft_define_pixel_line(t_coord p0, t_coord p1,
		t_coord step, t_coord diff)
{
	int		n;
	int		error;
	int		d_error;

	n = 0;
	error = diff.x + diff.y;
	while ((p0.x != p1.x) || (p0.y != p1.y))
	{
		d_error = 2 * error;
		if (d_error >= diff.y && p0.x != p1.x)
		{
			error += diff.y;
			p0.x += step.x;
		}
		if (d_error <= diff.x && p0.y != p1.y)
		{
			error += diff.x;
			p0.y += step.y;
		}
		n++;
	}
	return (n + 1);
}

/*
	pixel - pixels in line
	pixel.x - amount of pixels 
	pixel.y - current position
*/

static int	ft_color_pixel(t_coord *p0, t_coord *p1, t_coord *pixel)
{
	t_rgb	p0_color;
	t_rgb	p1_color;
	t_rgb	color;
	float	alpha;

	ft_hex_to_rgb(p0->c, &p0_color);
	ft_hex_to_rgb(p1->c, &p1_color);
	alpha = pixel->y / (float)(pixel->x - 1);
	color.r = (int)(p0_color.r * (1 - alpha) + p1_color.r * alpha);
	color.g = (int)(p0_color.g * (1 - alpha) + p1_color.g * alpha);
	color.b = (int)(p0_color.b * (1 - alpha) + p1_color.b * alpha);
	(pixel->y)++;
	return (color.r << 16 | color.g << 8 | color.b);
}

void	ft_line_gradient_color(t_img *img, t_coord p0, t_coord p1)
{
	t_coord	step;
	t_coord	diff;
	t_coord	error;
	t_coord	pixel;

	ft_define_step_diff(&p0, &p1, &step, &diff);
	pixel.x = ft_define_pixel_line(p0, p1, step, diff);
	pixel.y = 0;
	error.x = diff.x + diff.y;
	while ((p0.x != p1.x) || (p0.y != p1.y))
	{
		ft_mlx_pixel_put_img(img, p0.x, p0.y, ft_color_pixel(&p0, &p1, &pixel));
		error.y = 2 * error.x;
		if (error.y >= diff.y && p0.x != p1.x)
		{
			error.x += diff.y;
			p0.x += step.x;
		}
		if (error.y <= diff.x && p0.y != p1.y)
		{
			error.x += diff.x;
			p0.y += step.y;
		}
	}
	ft_mlx_pixel_put_img(img, p1.x, p1.y, ft_color_pixel(&p0, &p1, &pixel));
}

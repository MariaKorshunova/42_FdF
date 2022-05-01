/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmabel <jmabel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 19:23:31 by jmabel            #+#    #+#             */
/*   Updated: 2022/05/01 19:23:52 by jmabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	ft_abs(int n)
{
	if (n >= 0)
		return (n);
	else
		return (-n);
}

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
	diff->x = ft_abs(p1->x - p0->x);
	diff->y = -ft_abs(p1->y - p0->y);
}

void	ft_line(t_img *img, t_coord p0, t_coord p1, int color)
{
	int		error;
	int		d_error;
	t_coord	step;
	t_coord	diff;

	ft_define_step_diff(&p0, &p1, &step, &diff);
	error = diff.x + diff.y;
	while ((p0.x != p1.x) || (p0.y != p1.y))
	{
		ft_mlx_pixel_put_img(img, p0.x, p0.y, color);
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
	}
	ft_mlx_pixel_put_img(img, p1.x, p1.y, color);
}

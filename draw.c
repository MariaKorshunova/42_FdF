/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmabel <jmabel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 17:04:20 by jmabel            #+#    #+#             */
/*   Updated: 2022/05/07 21:24:17 by jmabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	ft_define_point_coord(t_fdf *fdf, t_coord *p, int x, int y)
{
	(*p).x = x - (fdf->column / 2);
	(*p).y = y - (fdf->row / 2);
	(*p).x = (*p).x * fdf->zoom;
	(*p).y = (*p).y * fdf->zoom;
	(*p).x = (*p).x + (WIDTH / 2);
	(*p).y = (*p).y + (HEIGHT / 2);
	(*p).color = fdf->color[y][x];
	if ((*p).x < 0 || (*p).x > WIDTH || (*p).y < 0 || (*p).y > HEIGHT)
		return (-1);
	return (0);
}

static void	ft_draw_lines(t_fdf *fdf, t_coord *step)
{
	t_coord	p0;
	t_coord	p1;

	if (ft_define_point_coord(fdf, &p0, (*step).x, (*step).y) == 0)
	{
		if ((*step).x < fdf->column - 1)
		{
			if (ft_define_point_coord(fdf, &p1, (*step).x + 1, (*step).y) == 0)
				ft_line_gradient_color(&(fdf->img), p0, p1);
		}
		if ((*step).y < (fdf->row - 1))
		{
			if (ft_define_point_coord(fdf, &p1, (*step).x, (*step).y + 1) == 0)
				ft_line_gradient_color(&(fdf->img), p0, p1);
		}
	}
}

void	ft_draw_map(t_fdf *fdf)
{
	t_coord	step;

	step.y = 0;
	while (step.y < fdf->row)
	{
		step.x = 0;
		while (step.x < fdf->column)
		{
			ft_draw_lines(fdf, &step);
			step.x++;
		}
		step.y++;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmabel <jmabel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 17:04:20 by jmabel            #+#    #+#             */
/*   Updated: 2022/05/06 18:16:33 by jmabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_coord	ft_define_point_coord(t_fdf *fdf, int x, int y)
{
	t_coord	p;

	p.x = x - (fdf->column / 2);
	p.y = y - (fdf->row / 2);
	p.x = p.x * fdf->zoom;
	p.y = p.y * fdf->zoom;
	p.x = p.x + (WIDTH / 2);
	p.y = p.y + (HEIGHT / 2);
	p.color = fdf->color[y][x];
	return (p);
}

void	ft_draw_lines(t_fdf *fdf)
{
	t_coord	p0;
	t_coord	p1;
	t_coord	step;

	step.y = 0;
	while (step.y < fdf->row)
	{
		step.x = 0;
		while (step.x < fdf->column)
		{
			p0 = ft_define_point_coord(fdf, step.x, step.y);
			if (step.x < fdf->column - 1)
			{
				p1 = ft_define_point_coord(fdf, step.x + 1, step.y);
				ft_line_gradient_color(&(fdf->img), p0, p1);
			}
			if (step.y < (fdf->row - 1))
			{
				p1 = ft_define_point_coord(fdf, step.x, step.y + 1);
				ft_line_gradient_color(&(fdf->img), p0, p1);
			}
			step.x++;
		}
		step.y++;
	}
}

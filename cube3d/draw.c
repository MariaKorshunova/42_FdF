/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmabel <jmabel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 20:27:20 by jmabel            #+#    #+#             */
/*   Updated: 2022/05/10 15:37:08 by jmabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

static void	ft_mlx_pixel_put_img(t_img	*img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bpp / 8));
	*(unsigned int *)dst = color;
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
	diff->x = (int)(abs(p1->x - p0->x));
	diff->y = -(int)(abs(p1->y - p0->y));
}

static void	ft_line(t_img *img, t_coord p0, t_coord p1, int color)
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

static void	ft_draw_cube(t_cube *cube)
{
	ft_line(&(cube->img), cube->vertices[0], cube->vertices[1], 0xFFFFFF);
	ft_line(&(cube->img), cube->vertices[0], cube->vertices[3], 0xFFFFFF);
	ft_line(&(cube->img), cube->vertices[0], cube->vertices[4], 0xFFFFFF);
	ft_line(&(cube->img), cube->vertices[1], cube->vertices[2], 0xFFFFFF);
	ft_line(&(cube->img), cube->vertices[1], cube->vertices[5], 0xFFFFFF);
	ft_line(&(cube->img), cube->vertices[2], cube->vertices[3], 0xFFFFFF);
	ft_line(&(cube->img), cube->vertices[2], cube->vertices[6], 0xFFFFFF);
	ft_line(&(cube->img), cube->vertices[3], cube->vertices[7], 0xFFFFFF);
	ft_line(&(cube->img), cube->vertices[4], cube->vertices[5], 0xFFFFFF);
	ft_line(&(cube->img), cube->vertices[4], cube->vertices[7], 0xFFFFFF);
	ft_line(&(cube->img), cube->vertices[5], cube->vertices[6], 0xFFFFFF);
	ft_line(&(cube->img), cube->vertices[6], cube->vertices[7], 0xFFFFFF);
}

void	ft_cube_3d(t_cube *cube)
{
	int			i;
	t_matrix	m;

	m = ft_get_transform_matrix(cube);
	i = 0;
	while (i < 8)
	{
		cube->vertices[i].x = cube->vertices[i].x * m.a11
			+ cube->vertices[i].y * m.a12 + cube->vertices[i].z * m.a13;
		cube->vertices[i].y = cube->vertices[i].x * m.a21
			+ cube->vertices[i].y * m.a22 + cube->vertices[i].z * m.a23;
		i++;
	}
	ft_translation(cube, WIDTH / 2, HEIGHT / 2);
	ft_draw_cube(cube);
}

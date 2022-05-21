/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmabel <jmabel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 19:41:47 by jmabel            #+#    #+#             */
/*   Updated: 2022/05/21 19:22:48 by jmabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

static int	ft_define_point_coord(t_fdf *fdf, t_coord *p, int x, int y)
{
	int	temp_x;

	(*p).x = x - (fdf->column / 2);
	(*p).y = y - (fdf->row / 2);
	temp_x = (*p).x;
	(*p).x = fdf->m.a11 * (*p).x + fdf->m.a12 * (*p).y
		+ fdf->m.a13 * fdf->map[y][x];
	(*p).y = fdf->m.a21 * temp_x + fdf->m.a22 * (*p).y
		+ fdf->m.a23 * fdf->map[y][x];
	(*p).x = (*p).x + WIDTH / 2 + fdf->translate.x;
	(*p).y = (*p).y + HEIGHT / 2 + fdf->translate.y;
	(*p).c = fdf->color[y][x];
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

static void	ft_draw_current_rotate(t_fdf *fdf)
{
	char	*str_x;
	char	*str_y;
	char	*str_z;

	str_x = ft_itoa(fdf->angle.x);
	str_y = ft_itoa(fdf->angle.y);
	str_z = ft_itoa(fdf->angle.z);
	if (!str_x || !str_y || !str_z)
		ft_error_mlx(fdf);
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 0, 45, 0x20B2AA, str_x);
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 40, 45, 0x20B2AA, str_y);
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 80, 45, 0x20B2AA, str_z);
	free(str_x);
	free(str_y);
	free(str_z);
}

static void	ft_draw_tips(t_fdf *fdf)
{
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 0, 0, 0xFFFFFF,
		"You can change the map in this ways: ");
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 0, 15, 0xFFFFFF,
		"Rotate Ox +/- <x/s>    Rotate Oy +/- <y/j>    Rotate Oz +/- <z/a>");
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 0, 30, 0x20B2AA,
		"Current rotate angles (in degress): x / y / z");
	ft_draw_current_rotate(fdf);
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 0, 60, 0xFFFFFF,
		"Parallel projection (top view): <p>");
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 0, 75, 0xFFFFFF,
		"Translate map: keyboard arrows. Back to the center: <c>");
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 0, 90, 0xFFFFFF,
		"Zoom map: <+/->. Back to the beginning: <b>");
}

void	ft_draw(t_fdf *fdf)
{
	t_coord	step;

	fdf->m = ft_rotate(fdf->angle);
	fdf->m = ft_matrix_multiply(ft_scale_matrix(fdf->scale * fdf->zoom),
			fdf->m);
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
	mlx_put_image_to_window(fdf->mlx_ptr, fdf->win_ptr, fdf->img.img, 0, 0);
	mlx_destroy_image(fdf->mlx_ptr, fdf->img.img);
	ft_draw_tips(fdf);
}

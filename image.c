/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmabel <jmabel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 20:41:20 by jmabel            #+#    #+#             */
/*   Updated: 2022/05/19 21:52:14 by jmabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_mlx_pixel_put_img(t_img	*img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bpp / 8));
	*(unsigned int *)dst = color;
}

static void	ft_error_mlx(t_fdf *fdf)
{
	ft_free_int_array(fdf->map, fdf->row);
	ft_free_int_array(fdf->color, fdf->row);
	ft_exit_fdf('p');
}

void	ft_init_image(t_fdf *fdf)
{
	fdf->mlx_ptr = mlx_init();
	if (!fdf->mlx_ptr)
		ft_error_mlx(fdf);
	fdf->win_ptr = mlx_new_window(fdf->mlx_ptr, WIDTH, HEIGHT, "mlx_fdf");
	fdf->img.img = mlx_new_image(fdf->mlx_ptr, WIDTH, HEIGHT);
	if (!fdf->win_ptr || !fdf->img.img)
		ft_error_mlx(fdf);
	fdf->img.addr = mlx_get_data_addr(fdf->img.img,
			&(fdf->img.bpp), &(fdf->img.line_length), &(fdf->img.endian));
	if (!fdf->img.addr)
		ft_error_mlx(fdf);
}

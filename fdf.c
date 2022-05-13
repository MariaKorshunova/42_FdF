/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmabel <jmabel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 19:25:58 by jmabel            #+#    #+#             */
/*   Updated: 2022/05/13 21:33:05 by jmabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_fdf_close(t_fdf *fdf)
{
	ft_free_int_array(fdf->map, fdf->row);
	ft_free_int_array(fdf->color, fdf->row);
	exit (0);
}

int	main(int argc, char **argv)
{
	t_fdf	fdf;

	ft_read_map(&fdf, argc, argv);
	ft_set_colors(&fdf);
	ft_define_zoom(&fdf);
	ft_define_rotate_angle(&fdf);
	fdf.mlx_ptr = mlx_init();
	fdf.win_ptr = mlx_new_window(fdf.mlx_ptr, WIDTH, HEIGHT, "mlx_fdf");
	fdf.img.img = mlx_new_image(fdf.mlx_ptr, WIDTH, HEIGHT);
	fdf.img.addr = mlx_get_data_addr(fdf.img.img,
			&(fdf.img.bpp), &(fdf.img.line_length), &(fdf.img.endian));
	ft_draw_map(&fdf);
	mlx_put_image_to_window(fdf.mlx_ptr, fdf.win_ptr, fdf.img.img, 0, 0);
	ft_hook(&fdf);
	mlx_loop(fdf.mlx_ptr);
	ft_fdf_close(&fdf);
	exit (0);
}

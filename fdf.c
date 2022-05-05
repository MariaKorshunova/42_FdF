/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmabel <jmabel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 19:25:58 by jmabel            #+#    #+#             */
/*   Updated: 2022/05/05 18:46:08 by jmabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char **argv)
{
	t_fdf	fdf;
	t_img	img;

	ft_read_map(&fdf, argc, argv);
	ft_set_colors(&fdf);
	fdf.zoom = 50;
	fdf.mlx_ptr = mlx_init();
	fdf.win_ptr = mlx_new_window(fdf.mlx_ptr, 1000, 1000, "mlx_fdf");
	img.img = mlx_new_image(fdf.mlx_ptr, 1000, 1000);
	img.addr = mlx_get_data_addr(img.img,
			&img.bpp, &img.line_length, &img.endian);
	ft_draw_lines(&fdf, &img);
	mlx_put_image_to_window(fdf.mlx_ptr, fdf.win_ptr, img.img, 0, 0);
	mlx_loop(fdf.mlx_ptr);
	ft_free_int_array(fdf.map, fdf.row);
	ft_free_int_array(fdf.color, fdf.row);
	exit (0);
}

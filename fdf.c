/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmabel <jmabel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 19:25:58 by jmabel            #+#    #+#             */
/*   Updated: 2022/05/19 22:15:29 by jmabel           ###   ########.fr       */
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
	ft_default_value(&fdf);
	ft_init_image(&fdf);
	ft_draw_map(&fdf);
	mlx_put_image_to_window(fdf.mlx_ptr, fdf.win_ptr, fdf.img.img, 0, 0);
	mlx_destroy_image(fdf.mlx_ptr, fdf.img.img);
	ft_hook(&fdf);
	mlx_loop(fdf.mlx_ptr);
	ft_fdf_close(&fdf);
	exit (0);
}

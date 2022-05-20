/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmabel <jmabel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 19:42:10 by jmabel            #+#    #+#             */
/*   Updated: 2022/05/20 21:42:18 by jmabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

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
	ft_draw(&fdf);
	ft_hook(&fdf);
	mlx_loop(fdf.mlx_ptr);
	ft_fdf_close(&fdf);
	exit (0);
}

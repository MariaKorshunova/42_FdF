/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmabel <jmabel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 19:43:26 by jmabel            #+#    #+#             */
/*   Updated: 2022/05/20 21:42:31 by jmabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

static void	ft_new_image(t_fdf *fdf)
{
	fdf->img.img = mlx_new_image(fdf->mlx_ptr, WIDTH, HEIGHT);
	if (!fdf->img.img)
		ft_error_mlx(fdf);
	fdf->img.addr = mlx_get_data_addr(fdf->img.img,
			&(fdf->img.bpp), &(fdf->img.line_length), &(fdf->img.endian));
	if (!fdf->img.addr)
		ft_error_mlx(fdf);
	ft_draw(fdf);
}

static int	ft_key_hook(int keycode, t_fdf *fdf)
{
	if (keycode == 53)
		ft_fdf_close(fdf);
	else if (keycode == 7)
		fdf->angle.x = fdf->angle.x + 1;
	else
		return (0);
	ft_new_image(fdf);
	return (0);
}

void	ft_hook(t_fdf *fdf)
{
	mlx_hook(fdf->win_ptr, ON_DESTROY, 0, ft_fdf_close, fdf);
	mlx_hook(fdf->win_ptr, ON_KEYDOWN, 1L << 0, ft_key_hook, fdf);
}
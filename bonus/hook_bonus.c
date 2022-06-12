/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmabel <jmabel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 19:43:26 by jmabel            #+#    #+#             */
/*   Updated: 2022/05/24 20:03:17 by jmabel           ###   ########.fr       */
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

static int	ft_key_hook_rotate(int keycode, t_fdf *fdf)
{
	if (keycode == 7)
		fdf->angle.x = fdf->angle.x + 1;
	else if (keycode == 1)
		fdf->angle.x = fdf->angle.x - 1;
	else if (keycode == 16)
		fdf->angle.y = fdf->angle.y + 1;
	else if (keycode == 38)
		fdf->angle.y = fdf->angle.y - 1;
	else if (keycode == 6)
		fdf->angle.z = fdf->angle.z + 1;
	else if (keycode == 0)
		fdf->angle.z = fdf->angle.z - 1;
	else
		return (0);
	return (0);
}

static int	ft_key_hook_translate(int keycode, t_fdf *fdf)
{
	if (keycode == 125)
		fdf->translate.y = fdf->translate.y + 2;
	else if (keycode == 126)
		fdf->translate.y = fdf->translate.y - 2;
	else if (keycode == 123)
		fdf->translate.x = fdf->translate.x - 2;
	else if (keycode == 124)
		fdf->translate.x = fdf->translate.x + 2;
	else if (keycode == 8)
	{
		fdf->translate.x = 0;
		fdf->translate.y = 0;
	}
	else
		return (0);
	return (0);
}

static int	ft_key_hook(int keycode, t_fdf *fdf)
{
	if (keycode == 53)
		ft_fdf_close(fdf);
	ft_key_hook_rotate(keycode, fdf);
	ft_key_hook_translate(keycode, fdf);
	if (keycode == 69)
		fdf->zoom = fdf->zoom + 0.01;
	else if (keycode == 78)
		fdf->zoom = fdf->zoom - 0.01;
	else if (keycode == 11)
		fdf->zoom = 1;
	else if (keycode == 35)
	{
		fdf->angle.x = 0;
		fdf->angle.y = 0;
		fdf->angle.z = 0;
	}
	else if (keycode == 46)
		fdf->zoom_alt = fdf->zoom_alt + 0.1;
	else if (keycode == 45)
		fdf->zoom_alt = fdf->zoom_alt - 0.1;
	ft_new_image(fdf);
	return (0);
}

void	ft_hook(t_fdf *fdf)
{
	mlx_hook(fdf->win_ptr, ON_DESTROY, 0, ft_fdf_close, fdf);
	mlx_hook(fdf->win_ptr, ON_KEYDOWN, 1L << 0, ft_key_hook, fdf);
}

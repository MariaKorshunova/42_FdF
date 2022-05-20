/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmabel <jmabel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 21:32:02 by jmabel            #+#    #+#             */
/*   Updated: 2022/05/13 21:39:16 by jmabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	ft_key_hook(int keycode, t_fdf *fdf)
{
	if (keycode == ESC)
		ft_fdf_close(fdf);
	return (0);
}

void	ft_hook(t_fdf *fdf)
{
	mlx_hook(fdf->win_ptr, ON_DESTROY, 0, ft_fdf_close, fdf);
	mlx_hook(fdf->win_ptr, ON_KEYDOWN, 1L << 0, ft_key_hook, fdf);
}

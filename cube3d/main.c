/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmabel <jmabel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 21:55:00 by jmabel            #+#    #+#             */
/*   Updated: 2022/05/07 22:19:38 by jmabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int	main(void)
{
	t_cube	cube;

	cube.mlx_ptr = mlx_init();
	cube.win_ptr = mlx_new_window(cube.mlx_ptr, WIDTH, HEIGHT, "mlx_cube");
	cube.img.img = mlx_new_image(cube.mlx_ptr, WIDTH, HEIGHT);
	cube.img.addr = mlx_get_data_addr(cube.img.img,
			&(cube.img.bpp), &(cube.img.line_length), &(cube.img.endian));
	mlx_put_image_to_window(cube.mlx_ptr, cube.win_ptr, cube.img.img, 0, 0);
	mlx_loop(cube.mlx_ptr);
	return (0);
}

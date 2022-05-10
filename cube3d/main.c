/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmabel <jmabel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 21:55:00 by jmabel            #+#    #+#             */
/*   Updated: 2022/05/10 15:39:43 by jmabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

static void	ft_init_data_transform(t_cube *cube)
{
	cube->zoom = 100;
	cube->angle_x = 60;
	cube->angle_y = 30;
	cube->angle_z = 0;
}

static void	ft_init_cube_vertices(t_cube *cube)
{
	((cube->vertices)[0]).x = -1;
	((cube->vertices)[0]).y = 1;
	((cube->vertices)[0]).z = 1;
	((cube->vertices)[1]).x = -1;
	((cube->vertices)[1]).y = 1;
	((cube->vertices)[1]).z = -1;
	((cube->vertices)[2]).x = 1;
	((cube->vertices)[2]).y = 1;
	((cube->vertices)[2]).z = -1;
	((cube->vertices)[3]).x = 1;
	((cube->vertices)[3]).y = 1;
	((cube->vertices)[3]).z = 1;
	((cube->vertices)[4]).x = -1;
	((cube->vertices)[4]).y = -1;
	((cube->vertices)[4]).z = 1;
	((cube->vertices)[5]).x = -1;
	((cube->vertices)[5]).y = -1;
	((cube->vertices)[5]).z = -1;
	((cube->vertices)[6]).x = 1;
	((cube->vertices)[6]).y = -1;
	((cube->vertices)[6]).z = -1;
	((cube->vertices)[7]).x = 1;
	((cube->vertices)[7]).y = -1;
	((cube->vertices)[7]).z = 1;
}

int	main(void)
{
	t_cube	cube;

	cube.mlx_ptr = mlx_init();
	cube.win_ptr = mlx_new_window(cube.mlx_ptr, WIDTH, HEIGHT, "mlx_cube");
	cube.img.img = mlx_new_image(cube.mlx_ptr, WIDTH, HEIGHT);
	cube.img.addr = mlx_get_data_addr(cube.img.img,
			&(cube.img.bpp), &(cube.img.line_length), &(cube.img.endian));
	ft_init_cube_vertices(&cube);
	ft_init_data_transform(&cube);
	ft_cube_3d(&cube);
	mlx_put_image_to_window(cube.mlx_ptr, cube.win_ptr, cube.img.img, 0, 0);
	mlx_loop(cube.mlx_ptr);
	return (0);
}

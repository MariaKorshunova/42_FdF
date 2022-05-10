/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmabel <jmabel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 20:03:57 by jmabel            #+#    #+#             */
/*   Updated: 2022/05/10 15:30:52 by jmabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	ft_scale(t_cube *cube, int zoom)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		cube->vertices[i].x = zoom * cube->vertices[i].x;
		cube->vertices[i].y = zoom * cube->vertices[i].y;
		cube->vertices[i].z = zoom * cube->vertices[i].z;
		i++;
	}
}

void	ft_translation(t_cube *cube, int dx, int dy)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		cube->vertices[i].x = cube->vertices[i].x + dx;
		cube->vertices[i].y = cube->vertices[i].y + dy;
		i++;
	}
}

t_matrix	ft_get_transform_matrix(t_cube *cube)
{
	t_matrix	matrix;

	matrix = ft_matrix_rotate_x(cube->angle_x);
	matrix = multiply_matrices_3_3(ft_matrix_rotate_y(cube->angle_y), matrix);
	matrix = multiply_matrices_3_3(ft_matrix_rotate_z(cube->angle_z), matrix);
	matrix = multiply_matrices_3_3(ft_matrix_scale(cube->zoom), matrix);
	return (matrix);
}

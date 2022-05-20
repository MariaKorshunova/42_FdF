/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_rotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmabel <jmabel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 21:04:37 by jmabel            #+#    #+#             */
/*   Updated: 2022/05/12 22:28:39 by jmabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_matrix	ft_rotate_x(int angle)
{
	float		alpha;
	t_matrix	matrix;

	alpha = M_PI / 180 * angle;
	matrix.a11 = 1;
	matrix.a12 = 0;
	matrix.a13 = 0;
	matrix.a21 = 0;
	matrix.a22 = cos(alpha);
	matrix.a23 = -sin(alpha);
	matrix.a31 = 0;
	matrix.a32 = sin(alpha);
	matrix.a33 = cos(alpha);
	return (matrix);
}

static t_matrix	ft_rotate_y(int angle)
{
	float		alpha;
	t_matrix	matrix;

	alpha = M_PI / 180 * angle;
	matrix.a11 = cos(alpha);
	matrix.a12 = 0;
	matrix.a13 = sin(alpha);
	matrix.a21 = 0;
	matrix.a22 = 1;
	matrix.a23 = 0;
	matrix.a31 = -sin(alpha);
	matrix.a32 = 0;
	matrix.a33 = cos(alpha);
	return (matrix);
}

static t_matrix	ft_rotate_z(int angle)
{
	float		alpha;
	t_matrix	matrix;

	alpha = M_PI / 180 * angle;
	matrix.a11 = cos(alpha);
	matrix.a12 = -sin(alpha);
	matrix.a13 = 0;
	matrix.a21 = sin(alpha);
	matrix.a22 = cos(alpha);
	matrix.a23 = 0;
	matrix.a31 = 0;
	matrix.a32 = 0;
	matrix.a33 = 1;
	return (matrix);
}

t_matrix	ft_rotate(t_coord	angle)
{
	t_matrix	matrix;

	matrix = ft_identity_matrix();
	if (angle.z != 0)
		matrix = ft_rotate_z(angle.z);
	if (angle.y != 0)
		matrix = ft_matrix_multiply(ft_rotate_y(angle.y), matrix);
	if (angle.x != 0)
		matrix = ft_matrix_multiply(ft_rotate_x(angle.x), matrix);
	return (matrix);
}

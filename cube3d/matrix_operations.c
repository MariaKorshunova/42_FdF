/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmabel <jmabel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 10:31:23 by jmabel            #+#    #+#             */
/*   Updated: 2022/05/10 15:24:45 by jmabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

t_matrix	ft_matrix_rotate_x(int angle)
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

t_matrix	ft_matrix_rotate_y(int angle)
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

t_matrix	ft_matrix_rotate_z(int angle)
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

t_matrix	ft_matrix_scale(int zoom)
{
	t_matrix	matrix;

	matrix.a11 = (float)zoom;
	matrix.a12 = 0;
	matrix.a13 = 0;
	matrix.a21 = 0;
	matrix.a22 = (float)zoom;
	matrix.a23 = 0;
	matrix.a31 = 0;
	matrix.a32 = 0;
	matrix.a22 = (float)zoom;
	return (matrix);
}

t_matrix	multiply_matrices_3_3(t_matrix X, t_matrix Y)
{
	t_matrix	matrix;

	matrix.a11 = X.a11 * Y.a11 + X.a12 * Y.a21 + X.a13 * Y.a31;
	matrix.a12 = X.a11 * Y.a12 + X.a12 * Y.a22 + X.a13 * Y.a32;
	matrix.a13 = X.a11 * Y.a13 + X.a12 * Y.a23 + X.a13 * Y.a33;
	matrix.a21 = X.a21 * Y.a11 + X.a22 * Y.a21 + X.a23 * Y.a31;
	matrix.a22 = X.a21 * Y.a12 + X.a22 * Y.a22 + X.a23 * Y.a32;
	matrix.a23 = X.a21 * Y.a13 + X.a22 * Y.a23 + X.a23 * Y.a33;
	matrix.a31 = X.a31 * Y.a11 + X.a32 * Y.a21 + X.a33 * Y.a31;
	matrix.a32 = X.a31 * Y.a12 + X.a32 * Y.a22 + X.a33 * Y.a32;
	matrix.a33 = X.a31 * Y.a13 + X.a32 * Y.a23 + X.a33 * Y.a33;
	return (matrix);
}

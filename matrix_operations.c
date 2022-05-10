/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmabel <jmabel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 15:57:09 by jmabel            #+#    #+#             */
/*   Updated: 2022/05/10 21:35:01 by jmabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_matrix	ft_translation_matrix(int dx, int dy)
{
	t_matrix	matrix;

	matrix.a11 = 1;
	matrix.a12 = 0;
	matrix.a13 = 0;
	matrix.a14 = (float)dx;
	matrix.a21 = 0;
	matrix.a22 = 1;
	matrix.a23 = 0;
	matrix.a24 = (float)dy;
	matrix.a31 = 0;
	matrix.a32 = 0;
	matrix.a33 = 1;
	matrix.a34 = 0;
	matrix.a41 = 0;
	matrix.a42 = 0;
	matrix.a43 = 0;
	matrix.a44 = 1;
	return (matrix);
}

t_matrix	ft_scale_matrix(int zoom)
{
	t_matrix	matrix;

	matrix.a11 = (float)zoom;
	matrix.a12 = 0;
	matrix.a13 = 0;
	matrix.a14 = 0;
	matrix.a21 = 0;
	matrix.a22 = (float)zoom;
	matrix.a23 = 0;
	matrix.a24 = 0;
	matrix.a31 = 0;
	matrix.a32 = 0;
	matrix.a33 = (float)zoom;
	matrix.a34 = 0;
	matrix.a41 = 0;
	matrix.a42 = 0;
	matrix.a43 = 0;
	matrix.a44 = 1;
	return (matrix);
}

t_matrix	ft_identity_matrix(void)
{
	t_matrix	matrix;

	matrix.a11 = 1;
	matrix.a12 = 0;
	matrix.a13 = 0;
	matrix.a14 = 0;
	matrix.a21 = 0;
	matrix.a22 = 1;
	matrix.a23 = 0;
	matrix.a24 = 0;
	matrix.a31 = 0;
	matrix.a32 = 0;
	matrix.a33 = 1;
	matrix.a34 = 0;
	matrix.a41 = 0;
	matrix.a42 = 0;
	matrix.a43 = 0;
	matrix.a44 = 1;
	return (matrix);
}

t_matrix	ft_matrix_multiply_4_4(t_matrix X, t_matrix Y)
{
	t_matrix	matrix;

	matrix.a11 = X.a11 * Y.a11 + X.a12 * Y.a21 + X.a13 * Y.a31 + X.a14 * Y.a41;
	matrix.a12 = X.a11 * Y.a12 + X.a12 * Y.a22 + X.a13 * Y.a32 + X.a14 * Y.a42;
	matrix.a13 = X.a11 * Y.a13 + X.a12 * Y.a23 + X.a13 * Y.a33 + X.a14 * Y.a43;
	matrix.a14 = X.a11 * Y.a14 + X.a12 * Y.a24 + X.a13 * Y.a34 + X.a14 * Y.a44;
	matrix.a21 = X.a21 * Y.a11 + X.a22 * Y.a21 + X.a23 * Y.a31 + X.a24 * Y.a41;
	matrix.a22 = X.a21 * Y.a12 + X.a22 * Y.a22 + X.a23 * Y.a32 + X.a24 * Y.a42;
	matrix.a23 = X.a21 * Y.a13 + X.a22 * Y.a23 + X.a23 * Y.a33 + X.a24 * Y.a43;
	matrix.a24 = X.a21 * Y.a14 + X.a22 * Y.a24 + X.a23 * Y.a34 + X.a24 * Y.a44;
	matrix.a31 = X.a31 * Y.a11 + X.a32 * Y.a21 + X.a33 * Y.a31 + X.a34 * Y.a41;
	matrix.a32 = X.a31 * Y.a12 + X.a32 * Y.a22 + X.a33 * Y.a32 + X.a34 * Y.a42;
	matrix.a33 = X.a31 * Y.a13 + X.a32 * Y.a23 + X.a33 * Y.a33 + X.a34 * Y.a43;
	matrix.a34 = X.a31 * Y.a14 + X.a32 * Y.a24 + X.a33 * Y.a34 + X.a34 * Y.a44;
	matrix.a41 = X.a41 * Y.a11 + X.a42 * Y.a21 + X.a43 * Y.a31 + X.a44 * Y.a41;
	matrix.a42 = X.a41 * Y.a12 + X.a42 * Y.a22 + X.a43 * Y.a32 + X.a44 * Y.a42;
	matrix.a43 = X.a41 * Y.a13 + X.a42 * Y.a23 + X.a43 * Y.a33 + X.a44 * Y.a43;
	matrix.a44 = X.a41 * Y.a14 + X.a42 * Y.a24 + X.a43 * Y.a34 + X.a44 * Y.a44;
	return (matrix);
}

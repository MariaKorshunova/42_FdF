/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmabel <jmabel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 15:57:09 by jmabel            #+#    #+#             */
/*   Updated: 2022/05/12 21:15:02 by jmabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_matrix	ft_scale_matrix(int zoom)
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
	matrix.a33 = (float)zoom;
	return (matrix);
}

t_matrix	ft_identity_matrix(void)
{
	t_matrix	matrix;

	matrix.a11 = 1;
	matrix.a12 = 0;
	matrix.a13 = 0;
	matrix.a21 = 0;
	matrix.a22 = 1;
	matrix.a23 = 0;
	matrix.a31 = 0;
	matrix.a32 = 0;
	matrix.a33 = 1;
	return (matrix);
}

t_matrix	ft_matrix_multiply(t_matrix X, t_matrix Y)
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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmabel <jmabel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 22:12:04 by jmabel            #+#    #+#             */
/*   Updated: 2022/05/10 15:25:45 by jmabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE_H
# define CUBE_H

# include <unistd.h>
# include <math.h>
# include <fcntl.h>
# include <stdio.h>
# include <limits.h>

# include "mlx.h"
# include "../libft/libft.h"

/*  set default window size */
# define WIDTH 1000
# define HEIGHT 1000

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_length;
	int		endian;
}	t_img;

typedef struct s_coord
{
	int	x;
	int	y;
	int	z;
}	t_coord;

typedef struct s_cube
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		zoom;
	int		angle_x;
	int		angle_y;
	int		angle_z;
	t_coord	vertices[8];
	t_img	img;
}	t_cube;

typedef struct s_matrix
{
	float	a11;
	float	a12;
	float	a13;
	float	a21;
	float	a22;
	float	a23;
	float	a31;
	float	a32;
	float	a33;
}	t_matrix;

void		ft_cube_3d(t_cube *cube);
t_matrix	ft_get_transform_matrix(t_cube *cube);
t_matrix	multiply_matrices_3_3(t_matrix X, t_matrix Y);
t_matrix	ft_matrix_rotate_x(int angle);
t_matrix	ft_matrix_rotate_y(int angle);
t_matrix	ft_matrix_rotate_z(int angle);
t_matrix	ft_matrix_scale(int zoom);
void		ft_translation(t_cube *cube, int dx, int dy);

#endif
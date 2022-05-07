/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmabel <jmabel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 22:12:04 by jmabel            #+#    #+#             */
/*   Updated: 2022/05/07 22:21:45 by jmabel           ###   ########.fr       */
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
# define WIDTH 1024
# define HEIGHT 1024

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_length;
	int		endian;
}	t_img;

typedef struct s_cube
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		zoom;
	t_img	img;
}	t_cube;

typedef struct s_coord
{
	int	x;
	int	y;
	int	z;
}	t_coord;

#endif
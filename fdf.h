/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmabel <jmabel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 19:26:19 by jmabel            #+#    #+#             */
/*   Updated: 2022/03/20 19:53:37 by jmabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <unistd.h>
# include <math.h>
# include <fcntl.h>
# include <stdio.h>

# include "mlx.h"
# include "./libft/libft.h"
# include "./get_next_line/get_next_line.h"

typedef struct s_fdf
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		**maps;
	char	**colors;
	int		fd;
}	t_fdf;

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
}	t_coord;

void	ft_read_map(t_fdf *fdf, int argc, char **argv);

void	ft_mlx_pixel_put_img(t_img	*img, int x, int y, int color);
void	ft_line(t_img *img, t_coord p1, t_coord p2, int color);

int		ft_str_count(char const *s, char c);
void	ft_free_char_array(char **arr, size_t len);

#endif
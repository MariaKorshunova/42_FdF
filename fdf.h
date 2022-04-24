/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmabel <jmabel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 19:26:19 by jmabel            #+#    #+#             */
/*   Updated: 2022/04/24 20:39:21 by jmabel           ###   ########.fr       */
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
	int		**map;
	int		**color;
	int		fd;
	int		column;
	int		row;
	char	*line;
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

/* map_read.c */
void	ft_read_map(t_fdf *fdf, int argc, char **argv);

/* map_define_value.c */
void	ft_define_map_value(t_fdf *fdf, int nb_line);

/* map_error.c  */
void	ft_error_map(t_fdf *fdf, char error);
void	ft_error_allocate_arr(t_fdf *fdf, char error);
void	ft_error_allocate_cell(t_fdf *fdf,
			char **line, char **cell, char error);

/* put_image.c */
void	ft_mlx_pixel_put_img(t_img	*img, int x, int y, int color);
void	ft_line(t_img *img, t_coord p1, t_coord p2, int color);

/* array_operations.c */
void	ft_free_int_array(int **arr, int len);
void	ft_free_char_array(char **arr, int row);
int		ft_count_column(char const *s, char c);

/*  ft_atoi_base10.c  */
int		ft_atoi_base_10(t_fdf *fdf, char *str, char **map_line, char **cell);

/* ft_atoi_base16.c */
int		ft_atoi_base_16(t_fdf *fdf, char *str, char **map_line, char **cell);

#endif
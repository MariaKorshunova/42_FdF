/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmabel <jmabel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 19:00:51 by jmabel            #+#    #+#             */
/*   Updated: 2022/04/24 18:45:51 by jmabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_error_map(t_fdf *fdf, char error)
{
	if (error == 'm')
		ft_putstr_fd("Error: Invalid map\n", 2);
	else if (error == 'p')
		perror("Error");
	free(fdf->line);
	close(fdf->fd);
	exit (1);
}

void	ft_error_allocate_arr(t_fdf *fdf, char error)
{
	ft_free_int_array(fdf->map, fdf->row);
	ft_free_int_array(fdf->color, fdf->row);
	ft_error_map(fdf, error);
}

void	ft_error_allocate_cell(t_fdf *fdf, char **line, char **cell, char error)
{
	int	is_color;

	is_color = 0;
	if (cell[1] != '\0')
		is_color = 1;
	ft_free_char_array(cell, is_color + 1);
	ft_free_char_array(line, fdf->column);
	ft_error_allocate_arr(fdf, error);
}

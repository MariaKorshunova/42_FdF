/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_error_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmabel <jmabel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 19:45:05 by jmabel            #+#    #+#             */
/*   Updated: 2022/05/20 19:45:18 by jmabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	ft_exit_fdf(char error)
{
	if (error == 'm')
		ft_putstr_fd("Error: Invalid map\n", 2);
	else if (error == 'p')
		perror("Error");
	exit (1);
}

void	ft_error_map_close(t_pars *parser, char error)
{
	close(parser->fd);
	ft_exit_fdf(error);
}

void	ft_error_map(t_pars *parser, char error)
{
	free(parser->line);
	ft_error_map_close(parser, error);
}

void	ft_error_allocate_arr(t_fdf *fdf, t_pars *parser, char error)
{
	ft_free_int_array(fdf->map, fdf->row);
	ft_free_int_array(fdf->color, fdf->row);
	ft_error_map(parser, error);
}

void	ft_error_allocate_cell(t_fdf *fdf, t_pars *parser, char error)
{
	ft_free_char_array(parser->cell);
	ft_free_char_array(parser->map_line);
	ft_error_allocate_arr(fdf, parser, error);
}

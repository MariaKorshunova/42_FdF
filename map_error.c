/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmabel <jmabel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 19:00:51 by jmabel            #+#    #+#             */
/*   Updated: 2022/04/23 21:01:37 by jmabel           ###   ########.fr       */
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

// static int	ft_atoi_sign(const char *str, int *i)
// {
// 	while (!(ft_isprint(str[*i])))
// 		(*i)++;
// 	if (str[*i] == '+')
// 		(*i)++;
// 	else if (str[*i] == '-')
// 	{
// 		(*i)++;
// 		return (-1);
// 	}
// 	return (1);
// }

// static	int	ft_create_nb(const char *str, int *i, long long *nb)
// {
// 	size_t			nb_digit;

// 	nb_digit = 0;
// 	while (str[*i] == '0')
// 		(*i)++;
// 	while (str[*i] >= '0' && str[*i] <= '9')
// 	{
// 		*nb = 10 * (*nb) + str[(*i)++] - '0';
// 		nb_digit++;
// 	}
// 	while (ft_isprint(str[*i]) == 0 && str[*i] != '\0')
// 		(*i)++;
// 	return (nb_digit);
// }

// static int	ft_atoi_check_digits(t_fdf *fdf, t_map *map, const char *str)
// {
// 	int				i;
// 	int				minus;
// 	long long		nb;
// 	size_t			nb_digit;

// 	i = 0;
// 	nb = 0;
// 	nb_digit = 0;
// 	minus = ft_atoi_sign(str, &i);
// 	if (str[i] == '\0')
// 	{
// 		ft_free_int_array(fdf->map, map->row);
// 		ft_error_map(map, 'm');
// 	}
// 	nb_digit = ft_create_nb(str, &i, &nb);
// 	if (str[i] != '\0' || (nb > 2147483647 && minus == 1)
// 		|| (nb > 2147483648 && minus == -1) || nb_digit > 11)
// 	{
// 		ft_free_int_array(fdf->map, map->row);
// 		ft_error_map(map, 'm');
// 	}
// 	return (minus * nb);
// }

